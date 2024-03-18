#include "../../std_lib_facilities.h"
#include <iostream>


struct Date {
    int y, m, d;
    Date(int y, int m, int d);
    void add_day(int n);
};


Date::Date(int year, int month, int day)
    :y{year}, m{month}, d{day}
{
    if (year < 0) error("Invalid date: year must be non-negative");
    if (month < 1 || month > 12) error("Invalid date: month must be betwen 1 and 12");
    if (day < 1 || day > 31) error("Invalid date: day must be between 1 and 31");
}


void Date::add_day(int n)
{
    if (n < 0) error("Must be a non-negative number of days");
    if (d + n > 31) error("Function doesn't handle incrementing month or year");
    d += n;
}


std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << '(' << d.y
                << ',' << d.m
                << ',' << d.d << ')';
}


int main()
{
    Date today {1978, 6, 25};
    // Date test {2004, 13, -5};  // Invalid date
    Date tomorrow = today;
    tomorrow.add_day(1);
    std::cout << "Today: " << today << '\n';
    std::cout << "Tomorrow: " << tomorrow << '\n';
}