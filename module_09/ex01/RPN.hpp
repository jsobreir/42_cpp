/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:59:54 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/22 13:24:03 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN {
    private:
        int _result;
        std::stack<char> _stack;
    public:
        RPN();
        RPN(RPN const &other);
        RPN &operator=(RPN const &other);
        ~RPN();
        void fillStack(char *argv);
        void execute(std::stack<int> stack);
};