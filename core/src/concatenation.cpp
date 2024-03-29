#include "concatenation.hpp"

namespace camerus 
{
namespace core
{
namespace output
{
void Concatenation::Horizontal(cv::Mat const& lhs, cv::Mat const& rhs, cv::Mat &out) {
    cv::hconcat(lhs, rhs, out);
}

void Concatenation::Vertical(cv::Mat const& lhs, cv::Mat const& rhs, cv::Mat &out) {
    cv::vconcat(lhs, rhs, out);
}
}
}
}