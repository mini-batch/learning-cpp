#ifndef TOKEN_H
#define TOKEN_H

#include <string>


// chars for token.kind to indicate type of token
const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_root = '$';
const char power = '^';

// keywords
const std::string quit_keyword = "exit";


struct Token {
    // Each Token has a char 'kind' indicating its type
    // value and name are optional
    char kind;
    double value;
    std::string name;
    Token(char ch) :kind(ch), value(0) { }
    Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, std::string s) :kind(ch), name(s) { }
};


class Token_stream {
    bool full;  // Indicates whether the buffer is full
    Token buffer;  // Contains a Token which is to be read next
public:
    // Initialise empty stream
    Token_stream() :full(0), buffer(0) { }

    Token get();
    void unget(Token t) { buffer = t; full = true; };

    // Ignore input until a certain character is seen
    void ignore(char);
};


struct Variable {
    // Every variable has a name and value
    std::string name;
    double value;
    Variable(std::string n, double v) :name(n), value(v) { }
};


#endif // TOKEN_H