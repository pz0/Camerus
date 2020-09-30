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
            VideoReader(int index)
            {
                finish_thread = false;
                capture = cv::VideoCapture(index);
                thread = std::thread(thread_task, this);
            }
            
            VideoReader(char *source)
            {
                finish_thread = false;
                capture = cv::VideoCapture(source);
                thread = std::thread(thread_task, this);
            }

            ~VideoReader()
            {
                finish_thread = true;
                thread.join();
            }
            
            cv::Mat get_current_frame()
            {
                std::lock_guard<std::mutex> lock(mtx);
                return frame;
            }

            void thread_task_body()
            {
                while(!finish_thread)
                {
                    std::lock_guard<std::mutex> lock(mtx);
                    capture.read(frame);
                    camerus::core::logger::debug("New Frame");
                }
            }
        private:
            static void thread_task(VideoReader *ptr)
            {
                ptr->thread_task_body();
            }

            cv::VideoCapture capture;
            cv::Mat frame;


            bool finish_thread;
            std::thread thread;
            std::mutex mtx;
    };
}