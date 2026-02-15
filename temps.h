#pragma once
#include "temps.h"

// Template for choice() and getMenuChoice()
template <typename T>
    bool readValue(T& out) {
    if (std::cin >> out) {
        return true;
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}
// Template for checkInput in dash_logger()
template <typename T>
void checkInput(const std::string& prompt, T& value) {
    while (true) {
        std::cout << prompt;
        if (std::cin >> value)
            return;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input.\n";
    }
}