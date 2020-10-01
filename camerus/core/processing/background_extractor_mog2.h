#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/core.hpp>
#include "../logger.h"


namespace camerus::core::processing
{
    class BackgroundExtractorMOG2
    {
        public:
            BackgroundExtractorMOG2()
            {
                bgsub = cv::createBackgroundSubtractorMOG2();
                camerus::core::logger::debug("BackgroundExtractorMOG2 - object created.");
            }
            
            cv::Mat apply(cv::Mat frame)
            {
                bgsub->apply(frame, fg);
                cv::cvtColor(fg, fg, cv::COLOR_GRAY2RGB);

                camerus::core::logger::debug("BackgroundExtractorMOG2 - new frame applied.");

                return fg;
            }
        private:
            cv::Ptr<cv::BackgroundSubtractor> bgsub;
            cv::Mat fg;
    };
}