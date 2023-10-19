#include "video_creator.hpp"

namespace camerus
{
namespace core
{
namespace output
{
VideoCreator::VideoCreator(char *filename, int const width, int const height, int fps) 
    : writer_{cv::VideoWriter(filename, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(width, height))}
    {}

void VideoCreator::write(cv::Mat const& frame) {
    writer_.write(frame);
}
}
}
}