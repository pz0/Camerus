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
    static void Horizontal(cv::Mat const& lhs, cv::Mat const& rhs, cv::Mat &out);
    static void Vertical(cv::Mat const& lhs, cv::Mat const& rhs, cv::Mat &out);
};
}
}
}