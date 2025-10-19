/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:56:56 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/23 13:26:24 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"

class Awesome {
public:
    Awesome() : _n(42) {}
    int get() const { return _n; }
private:
    int _n;
};

std::ostream& operator<<(std::ostream &os, Awesome const &a) {
    os << a.get();
    return os;
}


void printStr(const std::string &str) {
    std::cout << CYAN << "[string] " << str << RESET << std::endl;
}

template <typename T>
void printGeneric(const T &value) {
    std::cout << YELLOW << "[generic] " << value << RESET << std::endl;
}

int main() {
    std::cout << GREEN << "\n--- STRING TEST ---\n" << RESET;
    std::string arr[] = {"Hello", "World", "This", "Is", "CPP"};
    iter(arr, 5, printStr);

    std::cout << GREEN << "\n--- INT TEST ---\n" << RESET;
    int numbers[] = {1, 2, 3, 4, 5};
    iter(numbers, 5, printGeneric<int>);

    std::cout << GREEN << "\n--- FLOAT TEST ---\n" << RESET;
    float decimals[] = {3.14f, 2.71f, 1.618f};
    iter(decimals, 3, printGeneric<float>);

    std::cout << GREEN << "\n--- CHAR TEST ---\n" << RESET;
    char letters[] = {'A', 'B', 'C', 'D'};
    iter(letters, 4, printGeneric<char>);

    std::cout << GREEN << "\n--- AWESOME CLASS TEST ---\n" << RESET;
    Awesome awArr[5];
    iter(awArr, 5, printGeneric<Awesome>);


    return 0;
}


// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }