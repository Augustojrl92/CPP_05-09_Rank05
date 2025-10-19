/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:03:30 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/16 15:44:55 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern() 
{

}
Intern::Intern(const Intern &other) 
{
     (void)other; 
}
Intern &Intern::operator=(const Intern &other) 
{
	(void)other;
	return *this;
}
Intern::~Intern() 
{


}

AForm *Intern::makePresidential(const std::string &target) 
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomy(const std::string &target) 
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubbery(const std::string &target) 
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &form_type, const std::string &target) 
{
	std::string types[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm *(Intern::*creators[3])(const std::string &) = {
		&Intern::makePresidential,
		&Intern::makeRobotomy,
		&Intern::makeShrubbery
	};

	for (int i = 0; i < 3; ++i) 
    {
		if (form_type == types[i]) 
        {
			std::cout << "Intern creates " << form_type << std::endl;
			return (this->*creators[i])(target);
		}
	}

	std::cerr << "Intern: unknown form type \"" << form_type << "\"" << std::endl;
	//throw std::invalid_argument("Intern: unknown form type \"random form\"");

	return NULL;
}
