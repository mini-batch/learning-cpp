#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

#include "token.h"


// error() simply disguises throws:
inline void error(const std::string& s)
{
	throw std::runtime_error(s);
}


inline void error(const std::string& s, const std::string& s2)
{
	error(s + s2);
}


// run-time checked narrowing cast (type conversion). See ???.
template<class R, class A> R narrow_cast(const A& a)
{
	R r = R(a);
	if (A(r) != a) error(std::string("info loss"));
	return r;
}


// Store name and value pairs
std::vector<Variable> var_names;


// Get the value of a given name from var_names
double get_value(std::string s)
{
    for (int i = 0; i < var_names.size(); ++i)
        if (var_names[i].name == s) return var_names[i].value;
    throw std::runtime_error("get: undefined name " + s);
}


// Set the value for a given name in var_names
void set_value(std::string s, double d)
{
	for (int i = 0; i < var_names.size(); ++i)
		if (var_names[i].name == s) {
			var_names[i].value = d;
			return;
		}
	throw std::runtime_error("set: undefined name " + s);
}


// Check if a variable name exists in var_names
bool is_declared(std::string s)
{
	for (int i = 0; i < var_names.size(); ++i)
		if (var_names[i].name == s) return true;
	return false;
}


Token_stream ts;


double expression(Token_stream& ts);


double primary(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression(ts);
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d; // added missing return
	}
	case '-':
		return -primary(ts);
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case square_root:
	{
		double d = expression(ts);
		if (d < 0) error("Can only sqrt non-negative numbers");
		return sqrt(d);
	}
	case power:
	{
		t = ts.get();
		if (t.kind != '(') error("pow: expected '('");
		double base = expression(ts);
		t = ts.get();
		if (t.kind != ',') error("pow: expected ','");
		double exponent;
		try {
			exponent = narrow_cast<int>(expression(ts));
		} 
		catch (std::exception& e) {
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


double term(Token_stream& ts)
{
	double left = primary(ts);
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary(ts);
			break;
		case '/':
		{	
			double d = primary(ts);
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case '%':
		{
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(primary(ts));
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


double expression(Token_stream& ts)
{
	double left = term(ts);
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term(ts);
			break;
		case '-':
			left -= term(ts);
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}


double declaration(Token_stream& ts)
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	std::string var_name = t.name;
	if (is_declared(var_name)) error(var_name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);
	double d = expression(ts);
	var_names.push_back(Variable(var_name, d));
	return d;
}


double statement(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration(ts);
	default:
		ts.unget(t);
		return expression(ts);
	}
}


void clean_up_mess()
{
	ts.ignore(print);
}


const std::string prompt = "> ";
const std::string result = "= ";

void calculate(Token_stream& ts)
{
	while (true) try {
		std::cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		std::cout << result << statement(ts) << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		clean_up_mess();
	}
}


int main()

try {
	var_names.push_back(Variable("k", 1000));
	calculate(ts);
	return 0;
}
catch (std::exception& e) {
	std::cerr << "exception: " << e.what() << std::endl;
	char c;
	while (std::cin >> c && c != ';');
	return 1;
}
catch (...) {
	std::cerr << "exception\n";
	char c;
	while (std::cin >> c && c != ';');
	return 2;
}