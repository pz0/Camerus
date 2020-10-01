#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include "../logger.h"


namespace camerus::core::processing 
{
    void gaussian_blur(cv::Mat &source, cv::Mat &dest, int mask, float sigmaX = 0.0f, float sigmaY = 0.0f)
    {
        cv::GaussianBlur(source, dest, cv::Size(mask, mask), sigmaX, sigmaX);
        camerus::core::logger::debug("Gaussian blur passed.");
    }

    void median_blur(cv::Mat &source, cv::Mat &dest, int mask)
    {
        cv::medianBlur(source, dest, mask);
        camerus::core::logger::debug("Median blur passed.");
    }
}