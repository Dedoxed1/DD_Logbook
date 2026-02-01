//
// Created by coolj on 12/29/2025.
//
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>


/* Date (Using Chrono) , Minutes Elapsed , Total Milage , Tips, Flat Earnings , Total Deliveries */

struct DashSessionStats{
long minutes;
unsigned short int milage;
float tips;
float flat_pay;
char total_deliveries;
};
// Reminder to exception handle before final choice is processed and sent to dash_logger!!!
int choice() {
    short number;
    std::cout << "Enter the number corresponding to the choice.\n";
    std::cout << "Earn by Offer (1) or Earn by Time (2)?\n";
    std::cin >> number;
bool doloop{true};
    while (doloop) {
        if (number == 1)
        break;
        if (number == 2)
            break;

    }

        std::cout << "Invalid Number. Please Try Again.";
    }
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
    int num {choice()};
    if  (num == 1) {
        statFile << "Earn by Offer";

    }
    else if (num == 2) {
        statFile << "Earn by Time";
    }
    else {
        std::cout << "Error in Choice: dash_logger";

        }
        statFile << Stats.minutes << "\n" << Stats.milage << "\n " << Stats.tips << "\n" << Stats.flat_pay << "\n" << Stats.total_deliveries << "\n";
        statFile.close();


    }

int main() {
DashSessionStats Stats;

dash_logger(Stats);

return 0;
}