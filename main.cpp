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
    char Earn_Method;
};

int choice() {
    short number;
    bool valid = false;
    while (!valid) {
    std::cout << "Enter the number corresponding to the choice\n";
std::cout << " Earn by Time (1) or Earn by Offer (2)?\n";



    }

}

void dash_logger(DashSessionStats &Stats){
   std::ofstream statFile;
   statFile.open("d_log.csv", std::ios::app);

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
   std::cout << "Earn by Time (1) or Earn by Offer (2)?\n";
   if (std::cin == 1) {
       std::cout << "Earn by Time";
       if (std::cin == 2);
       std::cout << "Earn by Offer";
   }

   statFile << Stats.minutes << "\n" << Stats.milage << "\n " << Stats.tips << "\n" << Stats.flat_pay << "\n" << Stats.total_deliveries << "\n";
   statFile.close();

}


int main() {
DashSessionStats Stats;

dash_logger(Stats);

return 0;
}