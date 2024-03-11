
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

/*
Grammar:
Calculation:
	Statement
	Print
	Quit
	Calculation Statement

Statement:
	Declaration
	Expression

Declaration:
	"let" Name "=" Expression

Expression:
	Term
	Expression "+" Term
	Expression "-" Term

Term:
	Secondary
	Term "*" Secondary
	Term "/" Secondary
	Term "%" Secondary

Secondary:
	Primary

Primary:
	Number
	"(" Expression ")"
	"-" Primary
	"+" Secondary
	"sqrt(" Expression ")"
	"pow(" Expression "," Expression ")"

Number:
	Floating-point literal
*/

#include "../std_lib_facilities.h"

struct Token {
	// Each Token has a kind, value and name are optional
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string s) :kind(ch), name(s) { }  // Add string constructor
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

// chars for token.kind to indicate type of token
const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_root = '$';
const char power = '^';

// keywords
const string quit_keyword = "exit";

Token Token_stream::get()
{
	// First check if buffer us full
	if (full) { full = false; return buffer; }

	// Otherwise get next Token
	char ch;
	cin >> ch;
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
		cin.unget();
		double val;
		cin >> val;
		return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			// If token is not recognised, add chars into string
			// Can either be to do with variable, or quit command.
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch; // Add missing '+'
			cin.unget();
			if (s == quit_keyword) return Token(quit);
			if (s == "sqrt") return Token(square_root);
			if (s == "pow") return Token(power);
			return Token(name, s);
		}
		error("Bad token");
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
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	// Every variable has a name and value
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> var_names;

double get_value(string s)
{
	// Get the value of a given name string
	for (int i = 0; i < var_names.size(); ++i)
		if (var_names[i].name == s) return var_names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	// Change the value of a variable that already exists
	for (int i = 0; i < var_names.size(); ++i)  // change <= to <
		if (var_names[i].name == s) {
			var_names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	// Check if a variable name exists
	for (int i = 0; i < var_names.size(); ++i)
		if (var_names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d; // added missing return
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case square_root:
	{
		double d = expression();
		if (d < 0) error("Can only sqrt non-negative numbers");
		return sqrt(d);
	}
	case power:
	{
		t = ts.get();
		if (t.kind != '(') error("pow: expected '('");
		double base = expression();
		t = ts.get();
		if (t.kind != ',') error("pow: expected ','");
		double exponent;
		try {
			exponent = narrow_cast<int>(expression());
		} 
		catch (exception& e) {
			error("Exponent must be an integer");
		}
		t = ts.get();
		if (t.kind != ')') error("pow: expected ')'");
		return pow(base, exponent);
	}
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case '%':
		{
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(primary());
			if (i2 == 0) error("%: divide by zero");
			left = i1 % i2;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;
	if (is_declared(var_name)) error(var_name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);
	double d = expression();
	var_names.push_back(Variable(var_name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	var_names.push_back(Variable("k", 1000));
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}


/*
Test Inputs:

0;
-1;
2+1;
2-1;
2*3;
2/4;
-2*-2;
2*-3*(3-5);
let var1 = 20;
-999999999999999999999999;
9999999999999999999999999;
hello;
let quit = 20;

*/