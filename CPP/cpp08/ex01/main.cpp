/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:17:45 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/23 21:49:11 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>

// // Helper function to print a vector
// void printVector(const std::vector<int>& v) {
//     std::cout << "[ ";
//     for (size_t i = 0; i < v.size(); ++i)
//         std::cout << v[i] << " ";
//     std::cout << "]" << std::endl;
// }

// int main() {
//     std::srand(static_cast<unsigned int>(std::time(0)));

//     // ========================================================
//     // BASIC TEST WITH SMALL DATASET
//     // ========================================================
//     std::cout << "=== Basic Test with 5 numbers ===" << std::endl;
//     Span sp(5);

//     try {
//         std::vector<int> addedNumbers;
//         addedNumbers.push_back(6);
//         addedNumbers.push_back(3);
//         addedNumbers.push_back(17);
//         addedNumbers.push_back(9);
//         addedNumbers.push_back(11);

//         // Add all numbers at once using addRange
//         sp.addRange(addedNumbers.begin(), addedNumbers.end());

//         std::cout << "Span content: ";
//         printVector(addedNumbers);

//         std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
//         std::cout << "Longest span: " << sp.longestSpan() << std::endl;

//         // Trying to add a number beyond the limit
//         sp.addNumber(42);
//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     // ========================================================
//     // TEST WITH ONLY ONE NUMBER
//     // ========================================================
//     std::cout << "\n=== Test with only 1 number ===" << std::endl;
//     Span one(1);
//     try {
//         one.addNumber(5);
//         std::cout << "Trying shortestSpan() with only one number..." << std::endl;
//         std::cout << one.shortestSpan() << std::endl; // Should throw exception
//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     // ========================================================
//     // TEST WITH 10 NUMBERS (VISIBLE CONTENT)
//     // ========================================================
//     std::cout << "\n=== Test with 10 random numbers ===" << std::endl;
//     Span smallSpan(10);
//     try {
//         std::vector<int> values;
//         for (int i = 0; i < 10; ++i)
//             values.push_back(std::rand() % 100); // Random numbers between 0 and 99

//         smallSpan.addRange(values.begin(), values.end());

//         std::cout << "Span content: ";
//         printVector(values);

//         std::cout << "Shortest span: " << smallSpan.shortestSpan() << std::endl;
//         std::cout << "Longest span: " << smallSpan.longestSpan() << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     // ========================================================
//     // PERFORMANCE TEST WITH 10,000 NUMBERS
//     // ========================================================
//     std::cout << "\n=== Test with 10,000 random numbers ===" << std::endl;
//     Span bigSpan(10000);
//     try {
//         for (int i = 0; i < 10000; ++i)
//             bigSpan.addNumber(std::rand());

//         // We only print the spans, not the content
//         std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
//         std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }

int main()
{
   try
   {
    Span sp = Span(10);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

   }
   catch (std::exception &e)
   {
   std::cout << e.what() << std::endl;
   }
   return 0;
}