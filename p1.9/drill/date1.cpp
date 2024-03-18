#include "iostream"
#include "../../std_lib_facilities.h"


struct Date {
    int y;
    int m;
    int d;
};


class Invalid_date { };


void init_date(Date& date, int y, int m, int d)
{
    // Simple but incomplete check for valid date
    if (m < 1 || m > 12) throw Invalid_date();
    if (d < 0 || d > 31) throw Invalid_date();
    if (y < 0) throw Invalid_date();
    date.y = y;
    date.m = m;
    date.d = d;
}


void add_day(Date& d, int n)
{
    if (n < 0) error("Must be a non-negative number of days");
    if (d.d + n > 31) error("Function doesn't handle incrementing month or year");
    d.d += n;
}


std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << '(' << d.y
                << ',' << d.m
                << ',' << d.d << ')';
}


int main()
{
    Date today;
    // init_date(today, 2004, 13, -5); // Invalid
    init_date(today, 1978, 6, 25);
    Date tomorrow = today;
    add_day(tomorrow, 1);
    std::cout << "Today: " << today << '\n';
    std::cout << "Tomorrow: " << tomorrow << '\n';
}