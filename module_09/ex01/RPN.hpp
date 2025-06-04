/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:59:54 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/28 15:52:49 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN {
    private:
        int _result;
        std::stack<int> _stack;
    public:
        RPN();
        RPN(RPN const &other);
        RPN &operator=(RPN const &other);
        ~RPN();
        void fillStack(char *argv);
        void execute(std::string str);
};