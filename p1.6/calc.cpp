#include <iostream>
#include <stdexcept>
#include <string>


void error(std::string s)
{
    throw std::runtime_error(s);
}


class Token {
public:
    char kind;
    double value;
    Token(char k, double v = 0.0): kind {k}, value {v} {}
};


class Token_stream {
public:
    Token_stream(): full{false}, buffer(0) {}
    Token get();
    void putback(Token t);
private:
    bool full {false};
    Token buffer;
};


Token Token_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    std::cin >> ch;
    switch (ch) {
    case ';':
    case 'q':
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token{ch};
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9': {
        std::cin.putback(ch);
        double val;
        std::cin >> val;
        return Token{'8', val};
    }
    default:
        error("Bad token");
    }
}


void Token_stream::putback(Token t)
{
    if (full) error("putback() into full buffer");
    buffer = t;
    full = true;
}


Token_stream ts;
double expression();


double primary()
{
    Token t {ts.get()};
    switch (t.kind) {
    case '(': {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' was expected");
        return d;
    }
    case '8':
        return t.value;
    default:
        error("primary expected");
    }
}


double term()
{
    double left {primary()};
    Token t {ts.get()};
    while (true) {
        switch (t.kind) {
        case '*': {
            left *= primary();
            t = ts.get();
            break;
        }
        case '/': {
            double d = primary();
            if (d==0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}


double expression()
{
    double left {term()};
    Token t {ts.get()};
    while (true) {
        switch (t.kind) {
        case '+': {
            left += term();
            t = ts.get();
            break;
        }
        case '-': {
            left -= term();
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}


int main()
try {
    double val = 0;
    while (std::cin) {
        Token t = ts.get();
        std::cout << t.kind << '\n';
        if (t.kind == 'q') break;
        if (t.kind == ';')
            std::cout << "= " << val <<'\n';
        else
            ts.putback(t);
        val = expression();
    }
    return 0;
}
catch (std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
}
catch (...) {
    std::cerr << "Exception \n";
    return 2;
}