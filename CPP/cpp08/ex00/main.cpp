/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:00:37 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/21 16:05:17 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
    std::cout << "===== Vector Test =====" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Vector error: " << e.what() << std::endl;
    }

    try {
        easyfind(vec, 99);
    } catch (std::exception &e) {
        std::cerr << "Vector error: " << e.what() << std::endl;
    }

    std::cout << "\n===== List Test =====" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    try {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << "List error: " << e.what() << std::endl;
    }

    try {
        easyfind(lst, 100);
    } catch (std::exception &e) {
        std::cerr << "List error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Deque Test =====" << std::endl;
    std::deque<int> dq;
    dq.push_back(7);
    dq.push_back(14);
    dq.push_back(21);

    try {
        std::deque<int>::iterator it = easyfind(dq, 14);
        std::cout << "Found in deque: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Deque error: " << e.what() << std::endl;
    }

    try {
        easyfind(dq, 42);
    } catch (std::exception &e) {
        std::cerr << "Deque error: " << e.what() << std::endl;
    }

    return 0;
}
