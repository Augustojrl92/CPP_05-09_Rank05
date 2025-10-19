/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:59:31 by aurodrig          #+#    #+#             */
/*   Updated: 2025/08/26 19:19:53 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>

class PmergeMe {
public:
    static void sortVector(std::vector<int>& input);
    static void sortDeque (std::deque<int>&  input);

private:
    PmergeMe();
    PmergeMe(const PmergeMe&);
    PmergeMe& operator=(const PmergeMe&);
    ~PmergeMe();

    // vector
    static void mergeInsertSort(std::vector<int>& input);
    static void insertUsingJacobsthalVector(std::vector<int>&       mainChain,
                                            const std::vector<int>& pendings);

    // deque
    static void mergeInsertSort(std::deque<int>& input);
    static void insertUsingJacobsthalDeque (std::deque<int>&        mainChain,
                                            const std::deque<int>&  pendings);

    // Jacobsthal para cada rama (dos versiones separadas)
    static std::vector<std::size_t> generateJacobsthalIndicesVector(std::size_t size);
    static std::deque<std::size_t>  generateJacobsthalIndicesDeque (std::size_t size);
};

#endif

 
