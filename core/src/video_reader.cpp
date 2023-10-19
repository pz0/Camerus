#include "video_reader.hpp"

namespace camerus
{
namespace core
{
namespace input
{
VideoReader::VideoReader(int index, bool live) {
    capture = cv::VideoCapture(index);
    live_stream = live;

    if (live)
    {
        finish_thread = false;
        thread = std::thread(ThreadTask, this);
    }
}

VideoReader::VideoReader(char *source, bool live) {
    capture = cv::VideoCapture(source);
    live_stream = live;

    if (live)
    {
        finish_thread = false;
        thread = std::thread(ThreadTask, this);
    }
}

VideoReader::~VideoReader() {
    if (live_stream)
    {
        finish_thread = true;
        thread.join();
    }
}

cv::Mat VideoReader::GetCurrentFrame() {
    std::lock_guard<std::mutex> lock(mtx);

    if (!live_stream)
    {
        capture.read(frame);
    }

    return frame;
}

void VideoReader::ThreadTaskBody() {
    while(!finish_thread)
    {
        std::lock_guard<std::mutex> lock(mtx);
        capture.read(frame);
    }
}

void VideoReader::ThreadTask(VideoReader *ptr) {
    ptr->ThreadTaskBody();
}
}
}
}