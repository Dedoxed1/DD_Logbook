//
// Created by coolj on 12/29/2025.
//
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <limits>
#include <cstdio>
#include "date.h"


/* Date (Using Chrono) , Minutes Elapsed , Total Milage , Tips, Flat Earnings , Total Deliveries */

struct DashSessionStats{
long minutes;
unsigned short int milage;
float tips;
float flat_pay;
char total_deliveries;
};
// Reminder to exception handle before final choice is processed and sent to dash_logger!!!

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
short choice() {
    short number;
    bool validInput{false};
    std::cout << "Enter the number corresponding to the choice.\n";
    std::cout << "Earn by Offer (1) or Earn by Time (2)?\n";
    std::cin >> number;
    while (!validInput) {
        if (readValue(number)) {
            if (number == 1 || number == 2) {
            validInput = true;
        } else {
            std::cout << "Please Enter either 1 (EBO) or 2 (EBT)\n";
        }
    } else {
        std::cout << "Invalid Input. Please Enter a Number\n";
    }
}
return number;
}


void dash_logger(DashSessionStats &Stats) {
    std::ofstream statFile("d_log.csv", std::ios::app);

    if (!statFile.is_open()) {
        std::cout << "ERROR OPENING d_log.csv!!!\n";
        return;
    }

    std::cout << "Enter the data from your concluded dash.\n";
    std::cout << "Minutes:\n";
    std::cin >> Stats.minutes;
    std::cout << "Total Mileage:\n";
    std::cin >> Stats.milage;
    std::cout << "Tips:\n";
    std::cin >> Stats.tips;
    std::cout << "Flat Earnings:\n";
    std::cin >> Stats.flat_pay;
    std::cout << "Total Deliveries:\n";
    std::cin >> Stats.total_deliveries;
    std::cout << std::endl;
    std::cout << getCurrentDate();

    if  (const short num {choice()}; num == 1) {
        const char *mode = nullptr;
        std::cout << "Earn by Offer";
         mode == "Earn by Offer";

    }
    else if (num == 2) {
        std::cout << "Earn by Time";

    }
    else {
        std::cout << "Error in Choice: dash_logger";

        }
    statFile << "Minutes: " << Stats.minutes << "\n" << "Milage: " << Stats.milage << "\n" << "Tips: " << Stats.tips << "\n" << "Flat Pay: " << Stats.flat_pay << "\n" << "Total Deliveries: " << Stats.total_deliveries << "\n" << "Method: " << Stats.mode;
        statFile.close();

    }

int main() {
DashSessionStats Stats;

dash_logger(Stats);

return 0;
}