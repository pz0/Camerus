#include <iostream>
#include <unistd.h>
#include "core/video_reader.h"


int main(int argc, char *argv[])
{
    camerus::core::VideoReader reader = camerus::core::VideoReader("test");

    while(1)
    {
        cv::Mat frame = reader.get_current_frame();
        std::cout << frame.rows << " " << frame.cols << "\n";
        usleep(1000000);
    }

    return 0;
}