/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:37:10 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/03 12:57:26 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) 
    {

    }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) 
    {

    }

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) 
{
    if (this != &src) 
    {
        this->target = src.target;
    }
    return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm() 
{

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const 
{
    checkExecutability(executor);

    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open()) {
        std::cerr << "Could not open file to write shrubbery.\n";
        return;
    }

    file << "       _-_\n"
         << "    /~~   ~~\\\n"
         << " /~~         ~~\\\n"
         << "{               }\n"
         << " \\  _-     -_  /\n"
         << "   ~  \\\\ //  ~\n"
         << "_- -   | | _- _\n"
         << "  _ -  | |   -_\n"
         << "       | |\n";

    file.close();
}
