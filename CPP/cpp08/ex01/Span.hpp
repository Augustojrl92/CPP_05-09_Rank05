/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:50:39 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/23 21:46:33 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm> // Para std::distance

class Span {
private:
    std::vector<int> _numbers;
    unsigned int _maxSize;

public:
    Span(unsigned int N);
    ~Span();
    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    template<typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        if (std::distance(begin, end) + _numbers.size() > _maxSize)
            throw FullSpanException();
        _numbers.insert(_numbers.end(), begin, end);
    }

    class FullSpanException : public std::exception {
    public:
        const char* what() const throw();
    };

    class NotEnoughNumbersException : public std::exception {
    public:
        const char* what() const throw();
    };
};

#endif



