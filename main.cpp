//
// Created by coolj on 12/29/2025.
//
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <limits>
#include "date.h"


/* Date (Using Chrono) , Minutes Elapsed , Total Milage , Tips, Flat Earnings , Total Deliveries */

struct DashSessionStats{
short int minutes;
unsigned short int milage;
unsigned short int total_deliveries;
float tips;
float flat_pay;

};

// Template for choice()
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
short choice() {
    short number;
    while (true) {
        std::cout << "Enter the number corresponding to the choice.\n";
        std::cout << "Earn by Offer (1) or Earn by Time (2)?\n";

        if (!readValue(number)) {
            std::cout << "Invalid Input.";
            continue;
        }
        if (number == 1 || number == 2) {
            return number;
        }
    }
}

void dash_logger(DashSessionStats &Stats) {
    std::ofstream statFile("d_log.csv", std::ios::app);

    if (!statFile.is_open()) {
        std::cout << "ERROR OPENING d_log.csv!!!\n";
        return;
    }
    statFile << getCurrentDate() << "\n";

checkInput("Minutes:\n", Stats.minutes);
checkInput("Milage:\n", Stats.milage);
checkInput("Tips:\n", Stats.tips);
checkInput("Flat Pay:\n", Stats.flat_pay);
checkInput("Deliveries:\n", Stats.total_deliveries);

  const short num{choice()};
    if (num == 1) {
        std::cout << "Earn by Offer\n";
    }
    if (num == 2) {
        std::cout << "Earn by Time\n";

    }

    statFile << "Minutes: " << Stats.minutes << "\n" << "Milage: " << Stats.milage << "\n" << "Tips: $" << std::fixed << std::setprecision(2) << Stats.tips << "\n" << "Flat Pay: $" << Stats.flat_pay << "\n" << "Total Deliveries: " << std::noshowpoint << Stats.total_deliveries << "\n" << "\n";
        statFile.close();

    }

int main() {
DashSessionStats Stats{};

dash_logger(Stats);

return 0;
}