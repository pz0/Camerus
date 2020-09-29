#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>


namespace camerus::core
{
    class VideoReader {
        public:
            VideoReader(int index) : cap(index) {}
            VideoReader(char *source) : cap(source) {}
        private:
            cv::VideoCapture cap;
    };
}