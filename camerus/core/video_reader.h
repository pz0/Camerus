#include <mutex>
#include <thread>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include "logger.h"


namespace camerus::core
{
    class VideoReader 
    {
        public:
            VideoReader(int index, bool live)
            {
                camerus::core::logger::debug("VideoReader - object created.");
                capture = cv::VideoCapture(index);
                live_stream = live;

                if (live)
                {
                    finish_thread = false;
                    thread = std::thread(thread_task, this);
                    camerus::core::logger::debug("VideoReader - live thread created.");
                }
            }
            
            VideoReader(char *source, bool live)
            {
                camerus::core::logger::debug("VideoReader - object created.");
                capture = cv::VideoCapture(source);
                live_stream = live;

                if (live)
                {
                    finish_thread = false;
                    thread = std::thread(thread_task, this);
                    camerus::core::logger::debug("VideoReader - live thread created.");
                }
            }

            ~VideoReader()
            {
                if (live_stream)
                {
                    finish_thread = true;
                    thread.join();
                }

                camerus::core::logger::debug("VideoReader - object destroyed.");
            }
            
            cv::Mat get_current_frame()
            {
                std::lock_guard<std::mutex> lock(mtx);

                if (!live_stream)
                {
                    capture.read(frame);
                    camerus::core::logger::debug("VideoReader - new frame received.");
                }

                camerus::core::logger::debug("VideoReader - frame returned.");
                return frame;
            }

            void thread_task_body()
            {
                while(!finish_thread)
                {
                    std::lock_guard<std::mutex> lock(mtx);
                    capture.read(frame);
                    camerus::core::logger::debug("VideoReader - new frame received.");
                }
            }
        private:
            static void thread_task(VideoReader *ptr)
            {
                ptr->thread_task_body();
            }

            cv::VideoCapture capture;
            cv::Mat frame;
            bool live_stream;

            bool finish_thread;
            std::thread thread;
            std::mutex mtx;
    };
}