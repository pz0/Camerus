#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>

namespace camerus 
{
namespace core
{
namespace output
{
class Concatenation {
public:
    static void horizontal(cv::Mat const& lhs, cv::Mat const& rhs, cv::Mat &out);
    static void vertical(cv::Mat const& lhs, cv::Mat const& rhs, cv::Mat &out);
};
}
}
}