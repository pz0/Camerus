#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

namespace camerus
{
namespace core
{
namespace output
{
class VideoCreator {
public:
    VideoCreator(char *filename, int const width, int const height, int fps);

    void Write(cv::Mat const& frame);
private:
    cv::VideoWriter writer_;
};
}
}
}