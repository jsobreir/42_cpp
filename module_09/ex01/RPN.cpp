/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:02:29 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/28 15:57:28 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(RPN const &other) {
    *this = other;
}

RPN &RPN::operator=(RPN const &other) {
    if (this != &other) {
        _result = other._result;
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() { }

void RPN::fillStack(char *argv) {
    std::string string(argv);
    for (std::string::size_type i = 0; i < string.size(); i++)
        if (string[i] == ' ' || string[i] == '\t')
            string.erase(i, 1);
    for (std::string::size_type i = 0; i < string.size(); i++) {
        _stack.push(string[string.size() - i - 1]);
        // std::cout << _stack.top() << std::endl;
    }
}

void RPN::execute(std::string str) {
    for (std::string::iterator it = str.begin(); it != str.end(); ) {
        if (*it == ' ' || *it == '\t')
            it = str.erase(it);
        else
            ++it;
    }
    for (std::basic_string<char>::size_type i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            _stack.push(str[i] - '0');
        }
        else if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
            int res;
            if (_stack.size() < 2) {
                std::cerr << "Error: Not enough operands!" << std::endl;
                return ;
            }
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            switch (str[i]) {
                case '*' : res = a * b; break;
                case '-' : res = a - b; break;
                case '+' : res = a + b; break;
                case '/' : 
                    if (b == 0)
                    {
                        std::cerr << "Error: Division by zero!" << std::endl;
                        return ;
                    }
                    res = a / b; break;
            }
            _stack.push(res);
        }
        else
        {
            std::cerr << "Error: Invalid character." << std::endl;
            return ;
        }
    }
    if (_stack.size() > 1) {
        std::cout << "Error!" << std::endl;
        return ;
    }
    std::cout << _stack.top() << std::endl;_stack.pop();
}