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
                cap = cv::VideoCapture(index);
                thread = std::thread(thread_task, this);
            }
            
            VideoReader(char *source)
            {
                finish_thread = false;
                cap = cv::VideoCapture(source);
                thread = std::thread(thread_task, this);
            }

            ~VideoReader()
            {
                finish_thread = true;
                thread.join();
            }
            
            void thread_task_body()
            {
                while(!finish_thread)
                {
                    cap.read(mat);
                    camerus::core::logger::print_log("DEBUG", "New Frame");
                }
            }
        private:
            static void thread_task(VideoReader *ptr)
            {
                ptr->thread_task_body();
            }

            cv::VideoCapture cap;
            cv::Mat mat;
            bool finish_thread;
            std::thread thread;
    };
}