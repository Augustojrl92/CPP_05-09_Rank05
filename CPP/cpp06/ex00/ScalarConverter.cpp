/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:28:50 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/16 20:01:17 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

static bool isChar(const std::string& s) {
    return s.length() == 1 && !std::isdigit(s[0]);
}

static bool isInt(const std::string& s) {
    char* end;
    long val = std::strtol(s.c_str(), &end, 10);
    if (*end != '\0')
        return false;
    return val >= INT_MIN && val <= INT_MAX;
}


static bool isFloat(const std::string& s) {
    if (s == "nanf" || s == "+inff" || s == "-inff")
        return true;

    char* end;
    std::strtof(s.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

static bool isDouble(const std::string& s) {
    if (s == "nan" || s == "+inf" || s == "-inf")
        return true;

    char* end;
    std::strtod(s.c_str(), &end);
    return *end == '\0';
}

static void convertChar(char c) {
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << ".0f\n";
    std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

static void convertInt(int i) {
    std::cout << "char: ";
    if (i < 32 || i > 126) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    }

    std::cout << "int: " << i << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(i) << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(i) << std::endl;
}

static void convertFloat(float f) {
    std::cout << "char: ";
    if (std::isnan(f) || f < 32 || f > 126) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    }

    std::cout << "int: ";
    if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN) || std::isnan(f)){
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(f) << std::endl;
    }

    std::cout << "float: " << std::fixed << std::setprecision(1)
              << f << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(f) << std::endl;
}

static void convertDouble(double d) {
    std::cout << "char: ";
    if (std::isnan(d) || d < 32 || d > 126) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }

    std::cout << "int: ";
    if (d > INT_MAX || d < INT_MIN || std::isnan(d)) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }

    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(d) << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1)
              << d << std::endl;
}



void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
    std::cout << "Tipo no reconocido" << std::endl;
    return;
    }
    else if (isChar(literal)) {
        std::cout << "Tipo detectado: char" << std::endl;
        convertChar(literal[0]);
    }
    else if (isInt(literal)) {
        std::cout << "Tipo detectado: int" << std::endl;
        int value = std::atoi(literal.c_str());
        convertInt(value);
    }
    else if (isFloat(literal)) {
        std::cout << "Tipo detectado: float" << std::endl;
        float value = std::strtof(literal.c_str(), NULL);
        convertFloat(value);
    }
    else if (isDouble(literal)) {
        std::cout << "Tipo detectado: double" << std::endl;
         double value = std::strtod(literal.c_str(), NULL);
        convertDouble(value);
    }
    else {
        std::cout << "Tipo no reconocido" << std::endl;
    }
}






