#include <opencv2/imgproc.hpp>
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
                ptr_bg_subtractor_mog2 = cv::createBackgroundSubtractorMOG2();
                ptr_bg_subtractor_mog2->setDetectShadows(false);
                camerus::core::logger::debug("BackgroundExtractorMOG2 - object created.");
            }

            cv::Mat apply(cv::Mat frame)
            {
                ptr_bg_subtractor_mog2->apply(frame, fg);
                cv::cvtColor(fg, fg, cv::COLOR_GRAY2RGB);

                camerus::core::logger::debug("BackgroundExtractorMOG2 - new frame applied.");
                camerus::core::logger::debug("BackgroundExtractorMOG2 - frame returned.");

                return fg;
            }

            cv::Mat get_frame()
            {
                camerus::core::logger::debug("BackgroundExtractorMOG2 - frame returned.");
                return fg;
            }
        private:
            cv::Ptr<cv::BackgroundSubtractorMOG2> ptr_bg_subtractor_mog2;
            cv::Mat fg;
    };
}
