#include <iostream>
#include <unistd.h>
#include "core/video_reader.h"
#include "core/processing/filters.h"
#include "core/processing/edge_detection.h"
#include "core/processing/contours.h"
#include "core/processing/background_extractor_mog2.h"
#include "core/output/video_creator.h"
#include "core/output/concatenation.h"



int main(int argc, char *argv[])
{
    camerus::core::VideoReader reader = camerus::core::VideoReader("/tmp/resources/traffic.mp4", false);
    camerus::core::processing::BackgroundExtractorMOG2 bge;

    cv::Mat frame = reader.get_current_frame();
    std::cout << frame.cols << "\n";
    camerus::core::output::VideoCreator video1("/tmp/resources/test.avi", frame.cols * 3, frame.rows, 15);
    camerus::core::output::VideoCreator video2("/tmp/resources/test2.avi", frame.cols * 3, frame.rows, 15);
    camerus::core::output::VideoCreator video3("/tmp/resources/test3.avi", frame.cols * 2, frame.rows, 15);

    cv::Mat stage1, stage2, stage3;
    cv::Mat stage4, stage5;
    cv::Mat stage6, stage7;

    while(!frame.empty())
    {
        stage1 = frame;
        camerus::core::processing::gaussian_blur(stage1, stage1, 5);
        stage2 = bge.apply(stage1);
        camerus::core::processing::median_blur(stage2, stage3, 9);

        // from left: input frame (with gaussian blur) -> background subtraction -> median blur
        cv::Mat concat_stage1;
        camerus::core::output::concatenation::horizontal_concat(stage1, stage2, concat_stage1);
        camerus::core::output::concatenation::horizontal_concat(concat_stage1, stage3, concat_stage1);
        video1.write(concat_stage1);

        stage4 = camerus::core::processing::detect_canny_edges(stage3, 100, 100);
        stage5 = camerus::core::processing::draw_canny_edges_on(stage4, frame, 0.25f);

        cv::Mat concat_stage2;
        camerus::core::output::concatenation::horizontal_concat(stage3, stage4, concat_stage2);
        camerus::core::output::concatenation::horizontal_concat(concat_stage2, stage5, concat_stage2);
        video2.write(concat_stage2);

        std::vector<cv::Rect> rects = camerus::core::processing::get_bounding_rects(stage4);
        stage6 = camerus::core::processing::draw_bounding_rects_on(frame, rects);

        cv::Mat concat_stage3;
        camerus::core::output::concatenation::horizontal_concat(stage3, stage6, concat_stage3);
        video3.write(concat_stage3);

        frame = reader.get_current_frame();
    }

    return 0;
}