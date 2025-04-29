/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:02:29 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/22 13:27:44 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {

}

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

RPN::~RPN() {

}

void RPN::fillStack(char *argv) {
    std::string string(argv);
    for (std::string::size_type i = 0; i < string.size(); i++) {
        _stack.push(string[string.size() - i - 1]);
    }
    std::array<char>::iterator it;
    for (it.begin())
    std::cout << _stack.top() << " ";
}

void RPN::execute(std::stack<int> stack) {
    (void)stack;
}
