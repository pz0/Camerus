#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include "../logger.h"


namespace camerus::core::output::concatenation 
{
    void horizontal_concat(cv::Mat &lhs, cv::Mat &rhs, cv::Mat &out)
    {
        cv::hconcat(lhs, rhs, out);
        camerus::core::logger::debug("Horizontal concatination passed.");
    }

    void vertical_concat(cv::Mat &uhs, cv::Mat &dhs, cv::Mat &out)
    {
        cv::vconcat(uhs, dhs, out);
        camerus::core::logger::debug("Vertical concatination passed.");
    }
}