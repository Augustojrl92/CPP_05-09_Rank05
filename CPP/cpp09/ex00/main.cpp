/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:11:35 by aurodrig          #+#    #+#             */
/*   Updated: 2025/08/25 19:19:45 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

bool isValidValue(const std::string& valueStr, double& value) {
    std::istringstream ss(valueStr);
    ss >> value;
    return !ss.fail() && ss.eof() && value >= 0 && value <= 1000;
}

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == std::string::npos || end == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

bool parseLine(const std::string& line, std::string& date, std::string& valueStr) {
    size_t sep = line.find('|');
    if (sep == std::string::npos)
        return false;

    date = trim(line.substr(0, sep));
    valueStr = trim(line.substr(sep + 1));
    return true;
}

void processLine(const std::string& line, const BitcoinExchange& btc) {
    std::string date, valueStr;
    if (!parseLine(line, date, valueStr)) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    if (!btc.isValidDate(date)) {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }

    double value;
    if (!isValidValue(valueStr, value)) {
        if (valueStr.empty() || value < 0)
            std::cerr << "Error: not a positive number." << std::endl;
        else
            std::cerr << "Error: too large a number." << std::endl;
        return;
    }

    try {
        double rate = btc.getRateForDate(date);
        std::cout << date << " => " << value << " = "
                  << std::fixed << std::setprecision(2) << value * rate << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc("data.csv");
        std::string header;
        if (!std::getline(input, header) || header != "date | value") {
            std::cerr << "Error: encabezado inválido en archivo de entrada. "
                      << "Debe ser: date | value" << std::endl;
            return 1;
        }
        std::string line;
        while (std::getline(input, line)) {
            if (!line.empty())
                processLine(line, btc);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}


