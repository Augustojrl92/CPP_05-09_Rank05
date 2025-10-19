/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:07:47 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/21 20:46:10 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm> 
#include <limits> 

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span() {}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw FullSpanException();
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();

    std::vector<int> copy = _numbers;
    std::sort(copy.begin(), copy.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i < copy.size() - 1; ++i) {
        int diff = copy[i + 1] - copy[i];
        if (diff < minSpan)
            minSpan = diff;
    }

    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}

const char* Span::FullSpanException::what() const throw() {
    return "Span is full: cannot add more numbers.";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
    return "Not enough numbers to calculate span.";
}
