
#pragma once
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <thread>
// Function for Retrieving date and time.
inline std::string getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t t =std::chrono::system_clock::to_time_t(now);
    std::tm localTime = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%m-%d-%Y, " "%I:%M:%S %p");
    return oss.str();

}

// Function for Date only.
inline std::string getCurrentDatenoT() {
       auto now = std::chrono::system_clock::now();
       std::time_t t =std::chrono::system_clock::to_time_t(now);
       std::tm localTime = *std::localtime(&t);

       std::ostringstream oss;
       oss << std::put_time(&localTime, "%m-%d-%Y");
       return oss.str();

   }
/* Similar but different function used only for the welcome screen. As well as
#threads for a dynamic text output. */

void WelcomeScreen() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm local = *std::localtime(&t);
    int hour = local.tm_hour;
    std::cout << "===== DASH LOGGER =====\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    if (hour < 12) {
        std::cout << "Good Morning!\n";
    }
    else if (hour < 16 ) {
        std::cout << "Good Afternoon!\n";
    }
    else {
        std::cout << "Good Evening!\n";
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << std::put_time(&local, "%A, %B %d, %Y "  "%I:%M:%S %p \n");
    std::this_thread::sleep_for(std::chrono::seconds(1));


}


