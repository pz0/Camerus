#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include "../logger.h"


namespace camerus::core::processing
{
    std::vector<cv::Rect> get_bounding_rects(cv::Mat input_frame)
    {
        cv::cvtColor(input_frame, input_frame, cv::COLOR_RGB2GRAY);

        std::vector<std::vector<cv::Point>> cnts;
        cv::findContours(input_frame, cnts, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

        std::vector<std::vector<cv::Point>> cnts_poly(cnts.size());
        std::vector<cv::Rect> rects(cnts.size());

        for (int i = 0; i < cnts.size(); i++)
        {
            std::vector<cv::Point> cnt_poly;

            cv::approxPolyDP(cnts[i], cnt_poly, 3.0f, true);
            rects[i] = cv::boundingRect(cnt_poly);
        }

        camerus::core::logger::debug("get_bounding_rects - done.");
        return rects;
    }

    cv::Mat draw_bounding_rects_on(cv::Mat output_frame, std::vector<cv::Rect> rects)
    {
        cv::RNG rng;
        for (int i = 0; i < rects.size(); i++)
        {
            cv::Scalar color = cv::Scalar(rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256));
            cv::rectangle(output_frame, rects[i].tl(), rects[i].br(), color, 2);
        }

        return output_frame;
    }
}