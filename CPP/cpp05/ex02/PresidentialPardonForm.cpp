/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:50:30 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/03 11:02:21 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target)
     {

     }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target) 
    {

    }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) 
{
    if (this != &src) 
    {
        this->target = src.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() 
{

}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const 
{
    checkExecutability(executor);
    std::cout << "🕊️  " << target << " has been pardoned by Zaphod Beeblebrox.\n";
}
