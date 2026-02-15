#pragma once

#include <fstream>
#include <string>
#include "totals_io.h"
// Header file for storing value of totals outside of program so they can be called back later during execution.

inline void loadTotals(float& weekly, float& monthly, float& yearly) {
    std::ifstream in("totals.dat");
    if (!in.is_open()) return;

    std::string label;
    in >> label >> weekly;
    in >> label >> monthly;
    in >> label >> yearly;
}

inline void saveTotals(float weekly, float monthly, float yearly) {
    std::ofstream out("totals.dat", std::ios::trunc);
    out << "weekly " << weekly << "\n" << "monthly " << monthly <<
        "\n" << "yearly " << yearly << "\n";
}