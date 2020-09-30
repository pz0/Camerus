#include <iostream>
#include <chrono>
#include <ctime>


namespace camerus::core::logger 
{
    void print_log(char *level, char *msg)
    {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::cout << level << " | " << msg << "\t\t\t\t" << std::ctime(&now_time);
    }
}