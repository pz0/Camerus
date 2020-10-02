#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include "../logger.h"


namespace camerus::core::processing
{
    cv::Mat detect_canny_edges(cv::Mat input_frame, float threshold1, float threshold2, int aperture_size = 3, bool l2gradient = false)
    {
        cv::cvtColor(input_frame, input_frame, cv::COLOR_RGB2GRAY);
        cv::Canny(input_frame, input_frame, threshold1, threshold2, aperture_size, l2gradient);

        camerus::core::logger::debug("get_frame_with_edges - done.");

        cv::cvtColor(input_frame, input_frame, cv::COLOR_GRAY2RGB);
        return input_frame;
    }

    cv::Mat draw_canny_edges_on(cv::Mat edges, cv::Mat &destination, float edge_weight)
    {
        cv::Mat output_frame;

        if (edge_weight > 1)
            edge_weight = 1.0f;
        else if (edge_weight < 0)
            edge_weight = 0.0f;

        cv::addWeighted(destination, 1.0f - edge_weight, edges, edge_weight, 0.0f, output_frame);
        camerus::core::logger::debug("draw_canny_edges_on - done.");

        return output_frame;
    }
}