#include <iostream>
#include <unistd.h>
#include "core/video_reader.h"
#include "core/processing/filters.h"
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

    cv::Mat stage1, stage2, stage3;

    while(!frame.empty())
    {
        stage1 = frame;
        camerus::core::processing::median_blur(stage1, stage2, 9);
        stage3 = bge.apply(stage2);

        camerus::core::output::concatenation::horizontal_concat(stage1, stage2, stage2);
        camerus::core::output::concatenation::horizontal_concat(stage2, stage3, stage3);

        video1.write(stage3);
        frame = reader.get_current_frame();
    }

    return 0;
}