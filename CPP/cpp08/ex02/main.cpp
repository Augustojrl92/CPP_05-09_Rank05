/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:08:17 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/23 21:05:58 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "MutantStack.hpp"

// #include "iostream"


// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     while (it != ite) {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);

//     return 0;
// }

#include <iostream>
#include "MutantStack.hpp"
#include <vector>
#include <list>

// Generic function to test MutantStack with any container type
template <typename StackType>
void testStack(StackType &stack, const std::string &name) {
    std::cout << "\n=== Testing " << name << " ===" << std::endl;

    // Push some values
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    std::cout << "Top element: " << stack.top() << std::endl;
    std::cout << "Size: " << stack.size() << std::endl;

    // Normal iteration
    std::cout << "Elements (iterator): ";
    for (typename StackType::iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Reverse iteration
    std::cout << "Elements (reverse_iterator): ";
    for (typename StackType::reverse_iterator rit = stack.rbegin(); rit != stack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
}

int main() {
    // -------------------------------------------------------
    // 1. BASIC TEST (deque as underlying container)
    // -------------------------------------------------------
    std::cout << "=== Basic test with MutantStack (deque) ===" << std::endl;

    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);

    std::cout << "Top element: " << mstack.top() << std::endl; // Should print 40
    std::cout << "Size: " << mstack.size() << std::endl;       // Should print 4

    // ------------------------------------------------
    std::cout << "\n=== Iterating with iterator ===" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        *it += 1; // Modify elements
        std::cout << *it << " "; // Should print 11 21 31 41
    }
    std::cout << std::endl;

    // ------------------------------------------------
    std::cout << "\n=== Iterating with const_iterator ===" << std::endl;
    const MutantStack<int> constMstack = mstack; // Make a constant copy
    for (MutantStack<int>::const_iterator cit = constMstack.begin(); cit != constMstack.end(); ++cit) {
        std::cout << *cit << " "; // Read-only: 11 21 31 41
    }
    std::cout << std::endl;

    // ------------------------------------------------
    std::cout << "\n=== Iterating with reverse_iterator ===" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " "; // Prints reverse: 41 31 21 11
    }
    std::cout << std::endl;

    // ------------------------------------------------
    std::cout << "\n=== Iterating with const_reverse_iterator ===" << std::endl;
    for (MutantStack<int>::const_reverse_iterator crit = constMstack.rbegin(); crit != constMstack.rend(); ++crit) {
        std::cout << *crit << " "; // Prints reverse: 41 31 21 11
    }
    std::cout << std::endl;

    // ------------------------------------------------
    std::cout << "\n=== Comparing with std::stack ===" << std::endl;
    std::stack<int> s(mstack); // Convert MutantStack to std::stack
    std::cout << "Top element of std::stack: " << s.top() << std::endl; // 41

    // -------------------------------------------------------
    // 2. ADDITIONAL TESTS (vector and list)
    // -------------------------------------------------------
    MutantStack<int, std::vector<int> > mstackVector;
    testStack(mstackVector, "MutantStack<int, vector>");

    MutantStack<int, std::list<int> > mstackList;
    testStack(mstackList, "MutantStack<int, list>");

    return 0;
}

