#include "contours.hpp"

namespace camerus
{
namespace core
{
namespace processing
{
std::vector<cv::Rect> Contours::get_bouding_rects(cv::Mat const& source) {
    cv::cvtColor(source, source, cv::COLOR_RGB2GRAY);

    std::vector<std::vector<cv::Point>> cnts;
    cv::findContours(source, cnts, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    std::vector<std::vector<cv::Point>> cnts_poly(cnts.size());
    std::vector<cv::Rect> rects(cnts.size());

    for (int i = 0; i < cnts.size(); i++)
    {
        std::vector<cv::Point> cnt_poly;

        cv::approxPolyDP(cnts[i], cnt_poly, 3.0f, true);
        rects[i] = cv::boundingRect(cnt_poly);
    }

    return rects;
}

cv::Mat Contours::draw_bounding_rects_on(cv::Mat &out, std::vector<cv::Rect> const& rects) {
    cv::RNG rng;
    for (int i = 0; i < rects.size(); i++)
    {
        cv::Scalar color = cv::Scalar(rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256));
        cv::rectangle(out, rects[i].tl(), rects[i].br(), color, 2);
    }
}
}
}
}