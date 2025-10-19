/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 09:42:31 by aurodrig          #+#    #+#             */
/*   Updated: 2025/08/25 19:20:11 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(const std::string& str);

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    loadData(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _marketData(other._marketData) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _marketData = other._marketData;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file)
        throw std::runtime_error("Error: could not open database file.");
    std::string line;
    int lineNum = 0;
    if (!std::getline(file, line))
        throw std::runtime_error("Error: database file is empty.");
    ++lineNum;
    std::string header = trim(line);
    if (header != "date,exchange_rate") {
        throw std::runtime_error("Error: missing or invalid header in database file.");
    }
    while (std::getline(file, line)) {
        ++lineNum;
        std::stringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr)) {
            std::cerr << "Warning: línea inválida en " << filename
                      << " línea " << lineNum << ": " << line << std::endl;
            continue;
        }

        date = trim(date);
        valueStr = trim(valueStr);

        if (!isValidDate(date)) {
            std::cerr << "Warning: fecha inválida en línea "
                      << lineNum << ": " << date << std::endl;
            continue;
        }

        char* endptr;
        double value = std::strtod(valueStr.c_str(), &endptr);
        if (*endptr != '\0') {
            std::cerr << "Warning: valor no numérico en línea "
                      << lineNum << ": " << valueStr << std::endl;
            continue;
        }

        if (_marketData.find(date) != _marketData.end()) {
            std::cerr << "Warning: fecha duplicada en línea "
                      << lineNum << ": " << date << std::endl;
            continue;
        }

        _marketData[date] = value;
    }

    if (_marketData.empty())
        throw std::runtime_error("Error: no se cargaron datos válidos desde la base.");
}


    double BitcoinExchange::getRateForDate(const std::string& date) const {
        std::map<std::string, double>::const_iterator it = _marketData.lower_bound(date);
        if (it != _marketData.end() && it->first == date)
            return it->second;
        if (it == _marketData.begin())
            throw std::runtime_error("Error: date too early.");
        --it;
        return it->second;
    }

    bool BitcoinExchange::isValidDate(const std::string& date) const {
        if (date.size() != 10 || date[4] != '-' || date[7] != '-')
            return false;
    
        std::string yearStr = date.substr(0, 4);
        std::string monthStr = date.substr(5, 2);
        std::string dayStr = date.substr(8, 2);
    
        for (size_t i = 0; i < yearStr.size(); ++i)
            if (!isdigit(yearStr[i]))
                return false;
        for (size_t i = 0; i < monthStr.size(); ++i)
            if (!isdigit(monthStr[i]))
                return false;
        for (size_t i = 0; i < dayStr.size(); ++i)
            if (!isdigit(dayStr[i]))
                return false;
    
        int year = atoi(yearStr.c_str());
        int month = atoi(monthStr.c_str());
        int day = atoi(dayStr.c_str());
    
        if (month < 1 || month > 12 || day < 1)
            return false;
    
        int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month == 2 &&
            ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
            daysInMonth[1] = 29;
    
        if (day > daysInMonth[month - 1])
            return false;
    
        return true;
    }
    





