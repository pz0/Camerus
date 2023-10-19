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
        thread = std::thread(thread_task, this);
    }
}

VideoReader::VideoReader(char *source, bool live) {
    capture = cv::VideoCapture(source);
    live_stream = live;

    if (live)
    {
        finish_thread = false;
        thread = std::thread(thread_task, this);
    }
}

VideoReader::~VideoReader() {
    if (live_stream)
    {
        finish_thread = true;
        thread.join();
    }
}

cv::Mat VideoReader::get_current_frame() {
    std::lock_guard<std::mutex> lock(mtx);

    if (!live_stream)
    {
        capture.read(frame);
    }

    return frame;
}

void VideoReader::thread_task_body() {
    while(!finish_thread)
    {
        std::lock_guard<std::mutex> lock(mtx);
        capture.read(frame);
    }
}

void VideoReader::thread_task(VideoReader *ptr) {
    ptr->thread_task_body();
}
}
}
}