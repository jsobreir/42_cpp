#pragma once

#include <iostream>
#include <sstream>

#define NONE 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

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
		
		ScalarConverter();
	public:
		ScalarConverter(std::string string);
		ScalarConverter(ScalarConverter const & other);
		ScalarConverter operator=(ScalarConverter const & other);
		~ScalarConverter();
		static void convert (const std::string string);
};