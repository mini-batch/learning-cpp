#include <iostream>
#include <string>
#include <stdexcept>


Token get_token();
double expression();
double term();
double primary();


void error(std::string s) {
    throw std::runtime_error(s);
}


class Token {
public:
    char kind;
    double value;
};


double expression() {
    double left = term();
    Token t = get_token();
    while (true) {
        switch (t.kind) {
        case '+':
            left += term();
            t = get_token();
            break;
        case '-':
            left -= term();
            t = get_token();
            break;
        default:
            return left;
        }
    }
}


double term() {
    double left = primary();
    Token t = get_token();
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("Divide by zero");
            left /= d();
            t = get_token();
            break;
        }
            
        default:
            return left;
        }
    }
}


double primary() {
    Token t = get_token();
    switch (t.kind) {
    case '(':
    {
        double d = expression();
        t = get_token();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '8':
        return t.value;
    default:
        error("primary expected");
    }
}


int main() {
    try {
        while (std::cin) {
            std::cout << "= " << expression() << '\n';
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "exception\n";
        return 2;
    }
}


int first_main()
{
    Token t1 {'+'};
    std::cout << t1.kind << '\n';
    std::cout << "Please enter expression:\n";
    int lval {0};
    int rval;
    std::cin >> lval;
    if (!std::cin) error("No first operand");

    for (char op; std::cin >>op; ) {
        if (op != 'x') std::cin >> rval;
        switch(op) {
        case '+':
            lval += rval;
            break;
        case '-':
            lval -= rval;
            break;
        case '*':
            lval *= rval;
            break;
        case '/':
            lval /= rval;
            break;
        default:
            std::cout << "Result: " << lval << '\n';
            return 0;
        }
    }
    error("Bad expression");
}
