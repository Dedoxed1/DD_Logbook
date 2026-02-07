
#pragma once
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

   inline std::string getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t t =std::chrono::system_clock::to_time_t(now);
    std::tm localTime = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%m-%d-%Y");
    return oss.str();

}


