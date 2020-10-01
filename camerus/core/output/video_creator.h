#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include "../logger.h"


namespace camerus::core::output
{
    class VideoCreator
    {
        public:
            VideoCreator(char *filename, int width, int height, int fps)
            {
                writer = cv::VideoWriter(
                    filename, 
                    cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 
                    fps, 
                    cv::Size(width, height)
                );
                camerus::core::logger::debug("VideoCreator - object created.");
            }

            void write(cv::Mat frame)
            {
                writer.write(frame);
                camerus::core::logger::debug("VideoCreator - Frame written to file.");
            }
        private:
            cv::VideoWriter writer;
    };
}