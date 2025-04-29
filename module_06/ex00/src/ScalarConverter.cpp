/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:00:12 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/21 13:11:27 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::_c_ret;
int ScalarConverter::_i_ret;
float ScalarConverter::_f_ret;
double ScalarConverter::_d_ret;
int ScalarConverter::_type;

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(const std::string &string) {
	convert(string);
}

ScalarConverter::ScalarConverter(ScalarConverter const & other) {
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    if (this != &other) {
		_d_ret = other._d_ret;
		_i_ret = other._i_ret;
		_f_ret = other._f_ret;
		_d_ret = other._d_ret;
		_type = other._type;
    }
    return *this;
}

ScalarConverter::~ScalarConverter() { }

void ScalarConverter::convertChar(std::string string) {

	_c_ret = string[0];
	_i_ret = string[0];
	_f_ret = static_cast <float> (_i_ret);
	_d_ret = static_cast <double> (_i_ret);
}

void ScalarConverter::convertInt(std::string string) {

	// Create input string stream from string and extract the int part.	
	std::istringstream(string) >> _i_ret;
	_c_ret = _i_ret;
	_f_ret = static_cast <float> (_i_ret);
	_d_ret = static_cast <double> (_i_ret);
}

void ScalarConverter::convertFloat(std::string string) {
	
	std::istringstream(string) >> _f_ret;
	_i_ret = static_cast <int> (_f_ret);
	_c_ret = _i_ret;
	_d_ret = static_cast <double> (_f_ret);
}

void ScalarConverter::convertDouble(std::string string) {
	
	std::istringstream(string) >> _d_ret;
	_f_ret = static_cast <float> (_d_ret);
	_i_ret = static_cast <int> (_f_ret);
	_c_ret = _i_ret;
}


void ScalarConverter::convert(const std::string &string) {

	_type = detectType(string);
	
	if (_type == CHAR)
		convertChar(string);
	else if (_type == INT)
		convertInt(string);
	else if (_type == FLOAT)
		convertFloat(string);
	else if (_type == DOUBLE)
		convertDouble(string);

	if (_c_ret == 0 && _type != NAN)
		std::cout << "char: Non displayable" << std::endl;
	else if (!isprint(_c_ret))
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << _c_ret << "'" << std::endl;
	
	if (_type == NAN || _type == INF || _type == MINUS_INF)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _i_ret << std::endl;

	if (_type == NAN || _type == INF || _type == MINUS_INF)
		std::cout << "float: nanf" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << _f_ret << "f" << std::endl;
	
	if (_type == NAN || _type == INF || _type == MINUS_INF)
		std::cout << "double: nan" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << _d_ret << std::endl;
}

int	ScalarConverter::detectType(std::string in) {

	if (isChar(in))
		return CHAR;
	else if (isInt(in))
		return INT;
	else if (isFloat(in))
		return FLOAT;
	else if (isDouble(in))
		return DOUBLE;
	else if (in == "nan")
		return NAN;
	else if (in == "inff" || in == "-inff")
		return INF;
	return NONE;
}

bool ScalarConverter::isChar(std::string in) {

	if (in.size() > 1)
		return false;
	if (in.size() == 1 && std::isalpha(in[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(std::string in) {

	std::stringstream ss;
	ss << in;
	int	i;
	ss >> i;
	if (i && ss.eof()) {
		_i_ret = i;
		return true;
	}
	return false;
}

bool ScalarConverter::isFloat(std::string in) {

	std::stringstream ss;
	std::string floatPart;
	if (in.size() > 1 && in[in.size() - 1] == 'f') {
		floatPart = in.substr(0, in.size() - 1);
	}
	else if (in[in.size() - 1] != 'f') {
		floatPart = in;
	}
	ss << floatPart;
	float f;
	if ((ss >> f)) {
		_f_ret = f;
		return true;
	}
	return false;
}

bool ScalarConverter::isDouble(std::string in) {

	std::stringstream ss;
	ss << in;
	double d;
	if ((ss >> d) && (ss.eof())) {
		_d_ret = d;
		return true;
	}
	return false;
}

