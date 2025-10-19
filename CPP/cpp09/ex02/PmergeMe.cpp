/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:59:36 by aurodrig          #+#    #+#             */
/*   Updated: 2025/08/18 21:50:09 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) { return *this; }
PmergeMe::~PmergeMe() {}

// =======================
//        VECTOR
// =======================

void PmergeMe::sortVector(std::vector<int>& input) {
    if (input.size() <= 1) return;
    mergeInsertSort(input);
}

void PmergeMe::mergeInsertSort(std::vector<int>& input) {
    std::vector<int> mainChain;
    std::vector<int> pendings;

    for (std::size_t i = 0; i + 1 < input.size(); i += 2) {
        int a = input[i], b = input[i + 1];
        if (a < b) { pendings.push_back(a); mainChain.push_back(b); }
        else       { pendings.push_back(b); mainChain.push_back(a); }
    }
    if (input.size() % 2 != 0)
        pendings.push_back(input.back());

    std::sort(mainChain.begin(), mainChain.end());
    insertUsingJacobsthalVector(mainChain, pendings);
    input = mainChain;
}

void PmergeMe::insertUsingJacobsthalVector(std::vector<int>& mainChain,
                                           const std::vector<int>& pendings) {
    if (pendings.empty()) return;

    std::vector<std::size_t> indices = generateJacobsthalIndicesVector(pendings.size());

    for (std::size_t i = 0; i < indices.size(); ++i) {
        std::size_t idx = indices[i];
         if (idx >= pendings.size()) continue;
        int value = pendings[idx];
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }
}

std::vector<std::size_t> PmergeMe::generateJacobsthalIndicesVector(std::size_t size) {
    std::vector<std::size_t> indices;
    if (size == 0) return indices;
    std::vector<std::size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < size) {
        std::size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    std::vector<char> seen(size, 0);
    for (std::size_t i = 1; i < jacob.size(); ++i) {
        std::size_t hi = jacob[i]   > size ? size : jacob[i];
        std::size_t lo = jacob[i-1] > size ? size : jacob[i-1];
        for (std::size_t j = hi; j > lo; --j) {
            std::size_t idx = j - 1;
            if (!seen[idx]) {
                indices.push_back(idx);
                seen[idx] = 1;
            }
        }
    }
    for (std::size_t i = 0; i < size; ++i)
        if (!seen[i]) indices.push_back(i);

    return indices;
}

// =======================
//         DEQUE
// =======================

void PmergeMe::sortDeque(std::deque<int>& input) {
    if (input.size() <= 1) return;
    mergeInsertSort(input);
}

void PmergeMe::mergeInsertSort(std::deque<int>& input) {
    std::deque<int> mainChain;
    std::deque<int> pendings;

    for (std::size_t i = 0; i + 1 < input.size(); i += 2) {
        int a = input[i], b = input[i + 1];
        if (a < b) { pendings.push_back(a); mainChain.push_back(b); }
        else       { pendings.push_back(b); mainChain.push_back(a); }
    }
    if (input.size() % 2 != 0)
        pendings.push_back(input.back());
    std::sort(mainChain.begin(), mainChain.end());
    insertUsingJacobsthalDeque(mainChain, pendings);
    input.assign(mainChain.begin(), mainChain.end());
}

void PmergeMe::insertUsingJacobsthalDeque(std::deque<int>& mainChain,
                                          const std::deque<int>& pendings) {
    if (pendings.empty()) return;

    std::deque<std::size_t> indices = generateJacobsthalIndicesDeque(pendings.size());

    for (std::size_t i = 0; i < indices.size(); ++i) {
        std::size_t idx = indices[i];
        if (idx >= pendings.size()) continue;
        int value = pendings[idx];
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }
}

std::deque<std::size_t> PmergeMe::generateJacobsthalIndicesDeque(std::size_t size) {
    std::deque<std::size_t> indices;
    if (size == 0) return indices;

    std::deque<std::size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < size) {
        std::size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    std::deque<char> seen(size, 0);
    for (std::size_t i = 1; i < jacob.size(); ++i) {
        std::size_t hi = jacob[i]   > size ? size : jacob[i];
        std::size_t lo = jacob[i-1] > size ? size : jacob[i-1];
        for (std::size_t j = hi; j > lo; --j) {
            std::size_t idx = j - 1;
            if (!seen[idx]) {
                indices.push_back(idx);
                seen[idx] = 1;
            }
        }
    }
    for (std::size_t i = 0; i < size; ++i)
        if (!seen[i]) indices.push_back(i);
    return indices;
}

