#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>

namespace camerus
{
namespace core
{
namespace processing
{
class Filters {
public:
    static void gaussian_blur(
        cv::Mat const& source, cv::Mat &out, int const mask, float const sigmaX = 0.0f, float const sigmaY = 0.0f);

    static void median_blur(cv::Mat const& source, cv::Mat &out, int mask);
};
}
}
}