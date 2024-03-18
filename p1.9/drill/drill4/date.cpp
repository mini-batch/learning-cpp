#include "date.h"
#include <iostream>
#include "../../../std_lib_facilities.h"


Date::Date()
    :y{default_date().year()},
    m{default_date().month()},
    d{default_date().day()}
{
}

Date::Date(int yy, Month mm, int dd)
    :y{yy}, m{mm}, d{dd}
{
    if (!is_valid_date(y, m, d)) throw Invalid();
}

int Date::day() const
{
    return d;
}

Month Date::month() const
{
    return m;
}

int Date::year() const
{
    return y;
}

void Date::add_day(int n)
{
    if (d + n > 31) error("Function doesn't handle incrementing month/year");
    d += n;
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << '(' << d.year()
                << ',' << int(d.month())
                << ',' << d.day() << ')';
}

const Date& default_date()
{
    static Date dd{2000, Month::jan, 1};
    return dd;
}

bool is_valid_date(int y, Month m, int d)
{
    if (y < 0) return false;
    if (int(m) < 1 || int(m) > 12) return false;
    if (d < 1 || d > 31) return false;
    return true;
}


int main()
{
    Date dd {};
    Date today {1978, Month::jun, 25};
    // Date test {2004, Month::jan, -5};  // Invalid
    Date tomorrow = today;
    tomorrow.add_day(1);
    std::cout << "Default: " << dd << '\n';
    std::cout << "Today: " << today << '\n';
    std::cout << "Tomorrow: " << tomorrow << '\n';
}