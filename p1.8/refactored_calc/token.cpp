#include "token.h"

#include <iostream>
#include <stdexcept>


Token Token_stream::get()
{
    // If buffer is full, return buffer
    if (full) {
        full = false;
        return buffer;
    }

    // Otherwise get next Token
    char ch;
    std::cin >> ch;
    switch (ch) {
    case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case let:
	case print:
	case '=':
	case ',':
		return Token(ch);
	case '.': 
	case '0': case '1':	case '2': case '3':	case '4':
	case '5': case '6': case '7': case '8':	case '9':
	{	
		// If char is a digit, putback and get whole number
		std::cin.unget();
		double val;
		std::cin >> val;
		return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			// If token is not recognised, add chars into string
			// Can either be to do with variable, quit command, or other functions.
			std::string s;
			s += ch;
			while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch; // Add missing '+'
			std::cin.unget();
			if (s == quit_keyword) return Token(quit);
			if (s == "sqrt") return Token(square_root);
			if (s == "pow") return Token(power);
			return Token(name, s);
		}
		throw std::runtime_error("Bad token");
    }
}


void Token_stream::ignore(char c)
{
	// Ignore all input up until first instance of c
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;
    char ch;
    while (std::cin >> ch)
        if (ch = c) return;
}
