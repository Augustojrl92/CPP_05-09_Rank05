/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:09:58 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/03 11:00:31 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) 
{
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
    {

    }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
 {
    if (this != &src) 
    {
        this->target = src.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{

}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const 
{
    checkExecutability(executor);

    std::cout << "🤖 BrrrrrrrZZZZZTttt.... *taladro de robotomía*\n";
    if (std::rand() % 2 == 0)
        std::cout << "✅ " << target << " ha sido robotomizado exitosamente!\n";
    else
        std::cout << "❌ Falló la robotomización de " << target << "...\n";
}
