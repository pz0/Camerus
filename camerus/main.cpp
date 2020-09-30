#include <unistd.h>
#include "core/video_reader.h"


int main(int argc, char *argv[])
{
    camerus::core::VideoReader reader = camerus::core::VideoReader("test");

    while(1)
    {
        usleep(1000);
    }

    return 0;
}