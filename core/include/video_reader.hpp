#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <mutex>
#include <thread>

namespace camerus
{
namespace core
{
namespace input
{
class VideoReader {
public:
    VideoReader(int index, bool live);
    VideoReader(char *source, bool live);
    
    ~VideoReader();

    cv::Mat get_current_frame();
    void thread_task_body();
private:
    static void thread_task(VideoReader *ptr);

    cv::VideoCapture capture;
    cv::Mat frame;

    bool live_stream;
    bool finish_thread;

    std::thread thread;
    std::mutex mtx;
};
}
}
}