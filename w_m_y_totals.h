#pragma once
#include <chrono>
#include <ctime>

inline std::tm getLocalTimeNow() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    return *std::localtime(&t);
}

// Encapsulation used. New class used for determining (Week, Month, Year)
class WeeklyTotal {
private:
    int year;
    int week;
    float total;

public:
    WeeklyTotal() : year(0), week(0), total(0.0) {}
    void add(float amount) {
        const std::tm local = getLocalTimeNow();

        int currentYear = local.tm_year + 1900;
        int currentWeek = local.tm_yday / 7;

        if (year != currentYear || week != currentWeek) {
            year = currentYear;
            week = currentWeek;
            total = 0.0;
        }
total += amount;
    }
    float get() const {
        return total;
    }
    void set(float value) {
        const std::tm local = getLocalTimeNow();
        year = local.tm_year + 1900;
        week = local.tm_yday / 7;
        total = value;
    }
};

class MonthlyTotal {
private:
    int year;
    int month;
    float total;

public:
    MonthlyTotal() : year(0), month(0), total(0.0) {}
    void add(float amount) {
        const std::tm local = getLocalTimeNow();
        int currentYear = local.tm_year + 1900;
        int currentMonth = local.tm_mon;

        if (year != currentYear || month != currentMonth) {
            year = currentYear;
            month = currentMonth;
            total = 0.0;
        }
        total += amount;
    }
   float get() const {
        return total;
    }
    void set(float value){
        const std::tm local = getLocalTimeNow();
        year = local.tm_year + 1900;
        month = local.tm_mon;
        total = value;
    }
};
class YearlyTotal {
private:
    int year;
    float total;

public:
    YearlyTotal() : year(0), total(0.0) {}
    void add(float amount) {
        const std::tm local = getLocalTimeNow();
        int currentYear = local.tm_year + 1900;

        if (year != currentYear) {
            year = currentYear;
            total = 0.0;
        }
        total += amount;
    }
    float get() const {
        return total;
    }
    void set(float value) {
        const std::tm local = getLocalTimeNow();
        year = local.tm_year + 1900;
        total = value;
    }
};
