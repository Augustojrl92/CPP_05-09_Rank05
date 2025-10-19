/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:54:00 by aurodrig          #+#    #+#             */
/*   Updated: 2025/08/18 21:48:38 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include <climits>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <cstdlib>

static void fail() {
    std::cerr << "Error" << std::endl;
    std::exit(1);
}
static bool parsePositiveInt(const std::string& s, int& out) {
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '+') i = 1;
    if (i >= s.size()) return false;
    long long v = 0;
    for (; i < s.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (!std::isdigit(c)) return false;
        v = v * 10 + (s[i] - '0');
        if (v > INT_MAX) return false;
    }
    if (v <= 0) return false;
    out = static_cast<int>(v);
    return true;
}

static void splitArg(const char* arg, std::vector<int>& out) {
    std::string s(arg);
    std::istringstream iss(s);
    std::string tok;
    bool any = false;
    while (iss >> tok) {
        int val;
        if (!parsePositiveInt(tok, val)) fail();
        out.push_back(val);
        any = true;
    }
    if (!any) fail();
}

template <typename It>
static void printRange(const std::string& label, It first, It last) {
    std::cout << label;
    for (It it = first; it != last; ++it) std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 2) fail();
    std::vector<int> nums;
    for (int i = 1; i < argc; ++i) splitArg(argv[i], nums);
    if (nums.empty()) fail();
    printRange("Before: ", nums.begin(), nums.end());
    std::vector<int> v(nums.begin(), nums.end());
    std::deque<int>  d(nums.begin(), nums.end());
    std::clock_t t0 = std::clock();
    PmergeMe::sortVector(v);
    std::clock_t t1 = std::clock();
    std::clock_t t2 = std::clock();
    PmergeMe::sortDeque(d);
    std::clock_t t3 = std::clock();
    printRange("After:  ", v.begin(), v.end());
    double usVec = (double)(t1 - t0) * 1000000.0 / (double)CLOCKS_PER_SEC;
    double usDeq = (double)(t3 - t2) * 1000000.0 / (double)CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << nums.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(2)
              << usVec << " us" << std::endl;

    std::cout << "Time to process a range of " << nums.size()
              << " elements with std::deque  : " << std::fixed << std::setprecision(2)
              << usDeq << " us" << std::endl;

    return 0;
}
