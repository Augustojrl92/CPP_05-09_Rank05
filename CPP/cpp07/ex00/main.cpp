/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:07:02 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/23 13:28:41 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void) {
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "\033[1;34ma = " << a << ", b = " << b << "\033[0m" << std::endl;
    std::cout << "\033[1;32mmin(a, b) = " << ::min(a, b) << "\033[0m" << std::endl;
    std::cout << "\033[1;31mmax(a, b) = " << ::max(a, b) << "\033[0m" << std::endl;

    std::string c = "chainzy";
    std::string d = "chainyz";

    ::swap(c, d);
    std::cout << "\033[1;34mc = " << c << ", d = " << d << "\033[0m" << std::endl;
    std::cout << "\033[1;32mmin(c, d) = " << ::min(c, d) << "\033[0m" << std::endl;
    std::cout << "\033[1;31mmax(c, d) = " << ::max(c, d) << "\033[0m" << std::endl;

    float e = 1.5f;
    float f = 2.5f;

    ::swap(e, f);
    std::cout << "\033[1;34me = " << e << ", f = " << f << "\033[0m" << std::endl;
    std::cout << "\033[1;32mmin(e, f) = " << ::min(e, f) << "\033[0m" << std::endl;
    std::cout << "\033[1;31mmax(e, f) = " << ::max(e, f) << "\033[0m" << std::endl;

    char g = 'A';
    char h = 'B';
    ::swap(g, h);
    std::cout << "\033[1;34mg = " << g << ", h  = " << h << "\033[0m" << std::endl;
    std::cout << "\033[1;32mmin(g, h) = " << ::min(g, h) << "\033[0m" << std::endl;         
    std::cout << "\033[1;31mmax(g, h) = " << ::max(g, h) << "\033[0m" << std::endl;
    

    

    return 0;
}


// class Awesome
// {
//   public:
//     Awesome(void) : _n(0) {}
//     Awesome( int n ) : _n( n ) {}
//     Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
//     bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
//     bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
//     bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
//     bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
//     bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
//     bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
//     int get_n() const { return _n; }
//   private:
//     int _n;
// };
// std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

// int main(void)
// {
// 	Awesome a('a'), b('b');

//         swap(a, b);
//         std::cout << a << " " << b << std::endl;
//         std::cout << max(a, b) << std::endl;
//         std::cout << min(a, b) << std::endl;

//        Awesome c(4), d(2) ;
//        swap(c, d);
//         std::cout << c << " " << d << std::endl;
//         std::cout << max(c, d) << std::endl;
//         std::cout << min(c, d) << std::endl;

// std::cout << "\n--- PRUEBAS DE OPERADORES CON AWESOME ---" << std::endl;

// Awesome x(10), y(20);

// std::cout << "x = " << x << ", y = " << y << std::endl;

// if (x < y)
//     std::cout << "x < y" << std::endl;

// if (x <= y)
//     std::cout << "x <= y" << std::endl;

// if (y > x)
//     std::cout << "y > x" << std::endl;

// if (y >= x)
//     std::cout << "y >= x" << std::endl;

// if (x != y)
//     std::cout << "x != y" << std::endl;

// x = y;
// std::cout << "Después de x = y, x = " << x << ", y = " << y << std::endl;

// if (x == y)
//     std::cout << "x == y (ahora son iguales)" << std::endl;

//         return (0);
// }