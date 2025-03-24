#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>

#define NONE 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define NAN 5
#define INF 6
#define MINUS_INF 7

class ScalarConverter {
	private:
		static char _c_ret;
		static int _i_ret;
		static float _f_ret;
		static double _d_ret;
		static int _type;
		static bool isChar(std::string in);
		static bool isInt(std::string in);
		static bool isFloat(std::string in);
		static bool isDouble(std::string in);
		static int	detectType(std::string in);
		static void convertChar(std::string string);
		static void convertInt(std::string string);
		static void convertFloat(std::string string);
		static void convertDouble(std::string string);
	public:
		ScalarConverter();
		ScalarConverter(const std::string &string);
		ScalarConverter(ScalarConverter const & other);
		ScalarConverter &operator=(ScalarConverter const & other);
		~ScalarConverter();
		static void convert (const std::string &string);
};