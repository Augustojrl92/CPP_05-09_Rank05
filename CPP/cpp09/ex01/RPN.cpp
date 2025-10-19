/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:58:00 by aurodrig          #+#    #+#             */
/*   Updated: 2025/08/17 23:35:32 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <iostream> 

RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: Division by zero");
            return a / b;
        default:
            throw std::runtime_error("Error: Unknown operator");
    }
}

int RPN::evaluate(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string tok;
    while (iss >> tok) {
        if (tok.size() != 1) {
            throw std::runtime_error("Error: Invalid token size");
        }
        char c = tok[0];
        unsigned char u = static_cast<unsigned char>(c);

        if (std::isdigit(u)) {
            stack.push(c - '0');
        }
        else if (isOperator(c)) {
            if (stack.size() < 2)
                throw std::runtime_error("Error: Not enough operands");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result = applyOperator(a, b, c);
            stack.push(result);
        }
        else {
            throw std::runtime_error("Error: Invalid token");
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error: Invalid expression");
    return stack.top();
}
