#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>

#include <vector>

namespace camerus
{
namespace core
{
namespace processing
{
class Contours {
public:
    static std::vector<cv::Rect> get_bouding_rects(cv::Mat const& source);
    static cv::Mat draw_bounding_rects_on(cv::Mat &out, std::vector<cv::Rect> const& rects);
};
}
}
}