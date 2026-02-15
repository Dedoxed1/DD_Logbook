//
// Created by Dedoxed1 on 12/29/2025.
//
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include "date.h"
#include "w_m_y_totals.h"
#include "totals_io.h"
#include "temps.h"


struct DashSessionStats{
short int minutes;
unsigned short int milage;
unsigned short int total_deliveries;
float tips;
float flat_pay;
float dollar_per_mile;
float dollar_per_delivery;
float dollar_per_hour;
};


// Function checking validation and returning it back to dash_logger()
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
// Similar function to choice() but used for Stats.csv
short choice2() {
    short number2;
    while (true) {
        std::cout << "Would you like to write the data to Stats.csv?\n";
        std::cout << "Yes (1) or No (2)?\n";

        if (!readValue(number2)) {
            std::cout << "Invalid Input.";
            continue;
        }
        if (number2 == 1 || number2 == 2) {
            return number2;
        }
    }
}

// Static used to retain value.
static WeeklyTotal weeklyEarnings;
static MonthlyTotal monthlyEarnings;
static YearlyTotal yearlyEarnings;
static bool totalsLoaded = false;




// Function for recording dash metrics.
void dash_logger(DashSessionStats &Stats) {

if (!totalsLoaded) {
    float w = 0, m = 0, y = 0;
    loadTotals(w,m,y);

        weeklyEarnings.set(w);
        monthlyEarnings.set(m);
        yearlyEarnings.set(y);
    totalsLoaded = true;
}

    std::ofstream statFile("d_log.txt", std::ios::app);

    if (!statFile.is_open()) {
        std::cout << "ERROR OPENING d_log.txt!!!\n";
        return;
    }
    statFile << getCurrentDate() << "\n";

//Simplified. Checks input then returns value to respective struct member.
checkInput("Minutes:\n", Stats.minutes);
checkInput("Milage:\n", Stats.milage);
checkInput("Tips:\n$", Stats.tips);
checkInput("Flat Pay:\n$", Stats.flat_pay);
checkInput("Deliveries:\n", Stats.total_deliveries);

// Calculate to assign values to respective struct member .
Stats.dollar_per_mile = (Stats.flat_pay + Stats.tips) / static_cast<float>(Stats.milage);
Stats.dollar_per_delivery = (Stats.flat_pay + Stats.tips) / static_cast<float>(Stats.total_deliveries);
Stats.dollar_per_hour = (Stats.flat_pay + Stats.tips) / static_cast<float>(Stats.minutes / 60.0f);

// Receive number from short choice() and output either EbO or EBT
  const short num{choice()};
    if (num == 1) {
        std::cout << "Earn by Offer\n";
    }
    if (num == 2) {
        std::cout << "Earn by Time\n";

    }
// Add flat_pay and tips to earnings.
float earnings{Stats.flat_pay + Stats.tips};
    weeklyEarnings.add(earnings);
    monthlyEarnings.add(earnings);
    yearlyEarnings.add(earnings);

    // Output ONLY to d_log and NOT IN CSV format!

    statFile << "Minutes: " << Stats.minutes << "\n" << "Milage: " << Stats.milage << " mi\n" << "Total Deliveries: " <<  Stats.total_deliveries << "\n" << "Tips: $" << std::fixed << std::setprecision(2) << Stats.tips << "\n"
    << "Flat Pay: $" << Stats.flat_pay << "\n" << "Dollar per Mile: $" << Stats.dollar_per_mile << "\n" << "Dollar per Delivery: $" << Stats.dollar_per_delivery << "\n" << "Estimated Dollar per Hour: $" << Stats.dollar_per_hour << "\n" << "\n";
        statFile.close();

    // Output earnings to Earnings.txt

    std::ofstream earnFile("Earnings.txt", std::ios::app);
    earnFile << getCurrentDate() << "\n";
    earnFile << std::fixed << std::setprecision(2);
    earnFile << "Weekly Earnings: $" << weeklyEarnings.get() << "\n";
    earnFile << "Monthly Earnings: $" << monthlyEarnings.get() << "\n";
    earnFile << "Yearly Earnings: $" << yearlyEarnings.get() << "\n" << "\n";
    earnFile.close();


// Receives num2 from choice2() and either writes to Stats.csv or to skip.

const short num2{choice2()};
    if (num2 == 1) {
        std::ofstream csvFile ("Stats.csv", std::ios::app);
        csvFile << getCurrentDatenoT() << "," << Stats.minutes << "," << Stats.milage << "," <<  Stats.total_deliveries << "," << std::fixed << std::setprecision(2) << Stats.tips << ","
            << Stats.flat_pay << "," << Stats.dollar_per_mile << "," << Stats.dollar_per_delivery << "," <<  Stats.dollar_per_hour << "\n";
csvFile.close();
std::cout << "Data has been written to Stats.csv";
    }
    saveTotals(weeklyEarnings.get(), monthlyEarnings.get(),yearlyEarnings.get());
}

// Function for receiving input from user, check validation, and returning it back to menuHandler

int getMenuChoice() {
    int choice;
    while (true) {
        std::cout << "Enter Choice (1-4)\n";
        readValue(choice);
        if (choice >= 1 && choice <=4)
            return choice;

        std::cout << "Invalid Input.";
    }
}
// Function for opening and reading of files.

void displayFile(const std::string& actualFile) {
    std::ifstream file(actualFile);

    if (!file.is_open()) {
        std::cout << "Error Opening File.\n";
        return;
    }
    std::string line;
    while (std::getline(file,line)) {
std::cout << line << "\n";
    }
    file.close();
}
//Switch used for handling menu Output.

bool menuHandler(int base) {
    switch (base) {
        case 1: {
            DashSessionStats Stats{};
            dash_logger(Stats);
            break;
        }
        case 2: {
            displayFile("Earnings.txt");
            break;
        }
        case 3: {
            displayFile("d_log.txt");
        }
        case 4: {
            return false;
        }
    }
    return true;
}
int main() {
// Found in date.h
WelcomeScreen();
// Might need optimization... / clean up
std::cout << "Would you like to:\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "(1) Record a recent Dash.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "(2) View Weekly/Monthly/YTD Earnings\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "(3) View previously logged Dashes\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "(4) Exit\n";

menuHandler(getMenuChoice());


return 0;
}


