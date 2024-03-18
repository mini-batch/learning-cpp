#ifndef DRILL4_DATE_H
#define DRILL4_DATE_H

#include<iostream>

enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
public:
    class Invalid { };
    Date();
    Date(int, Month, int);

    // Non-modifying member functions
    int day() const;
    Month month() const;
    int year() const;

    // Modifying member functions
    void add_day(int);
private:
    int y;
    Month m;
    int d;
};

std::ostream& operator<<(std::ostream&, const Date&);

const Date& default_date();

bool is_valid_date(int, Month, int);

#endif // DRILL4_DATE_H
