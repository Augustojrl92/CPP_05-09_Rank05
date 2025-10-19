/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:23:16 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/18 08:31:41 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    std::srand(std::time(0));
    int r = std::rand() % 3;

    switch (r) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Identify by pointer: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identify by pointer: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identify by pointer: C" << std::endl;
    else
        std::cout << "Identify by pointer: Unknown type" << std::endl;
}


void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identify by reference: A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Identify by reference: B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identify by reference: C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Identify by reference: Unknown type" << std::endl;
}

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
    Base* obj = generate();

    std::cout << "Identify by pointer: ";
    identify(obj);

    std::cout << "Identify by reference: ";
    identify(*obj);

    // --- Caso de prueba forzado ---
    Base base;
    std::cout << "\nForced Unknown test:\n";
    identify(&base);
    identify(base);
    

    delete obj;
}

