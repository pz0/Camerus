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
    static std::vector<cv::Rect> GetBoudingRects(cv::Mat const& source);
    static void DrawBoundingRectsOn(cv::Mat &out, std::vector<cv::Rect> const& rects);
};
}
}
}