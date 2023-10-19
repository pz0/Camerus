#include "filters.hpp"

namespace camerus
{
namespace core
{
namespace processing
{
void Filters::gaussian_blur(cv::Mat const& source, cv::Mat &out, int const mask, float const sigmaX, float const sigmaY) {
    cv::GaussianBlur(source, out, cv::Size(mask, mask), sigmaX, sigmaY);
}

void Filters::median_blur(cv::Mat const& source, cv::Mat &out, int const mask) {
    cv::medianBlur(source, out, mask);
}
}
}
}