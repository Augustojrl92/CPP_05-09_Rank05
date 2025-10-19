/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:23:20 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/15 18:22:03 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

void test(const std::string& test_type, const std::string& name, int grade, const std::string& form) {
	if (test_type == "b_range")
		std::cout << "🧪 Creating Bureaucrat \"" << name << "\" with grade " << grade << ":\t";
	else if (test_type == "increment")
		std::cout << "⬆️  Incrementing \"" << name << "\" (previous grade: " << grade << "):\t";
	else if (test_type == "decrement")
		std::cout << "⬇️  Decrementing \"" << name << "\" (previous grade: " << grade << "):\t";
	else if (test_type == "signing")
		std::cout << "\n🖋️  Attempting to sign \"" << form << "\" (requires grade: " << grade << ")\n";
	else if (test_type == "executing")
		std::cout << "\n🚀 Attempting to execute \"" << form << "\" (requires grade: " << grade << ")\n";
}





int	main() 
{
	std::string name;
	std::string target;
	int			grade;


	

		std::cout << YELLOW << "\n========== TESTING PRESIDENTIAL PARDON ==========\n" << RESET;
	{
		try {
			name = "Liam";
			grade = 10;
			target = "Billy";
			Bureaucrat burr(name, grade);
			PresidentialPardonForm form(target);
			std::cout << CYAN << burr << RESET;
			test("signing", name, form.getGradeToSign(), "Presidential Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Presidential Form");
			burr.executeForm(form);
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}

		try {
			name = "Noah";
			grade = 2;
			target = "Billy";
			Bureaucrat burr(name, grade);
			PresidentialPardonForm form(target);
			std::cout << CYAN << burr << RESET;
			test("signing", name, form.getGradeToSign(), "Presidential Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Presidential Form");
			burr.executeForm(form);
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}

		try {
			name = "Anna";
			grade = 30;
			target = "Billy";
			Bureaucrat burr(name, grade);
			PresidentialPardonForm form(target);
			std::cout << CYAN << burr << RESET;
			test("signing", name, form.getGradeToSign(), "Presidential Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Presidential Form");
			burr.executeForm(form);
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}

		try 
		{
			name = "Joce";
			grade = 6;
			target = "Billy";
			Bureaucrat burr(name, grade);
			PresidentialPardonForm form(target);
			std::cout << CYAN << burr << RESET;
			test("signing", name, form.getGradeToSign(), "Presidential Form");
			burr.signForm(form);
			test("signing", name, form.getGradeToSign(), "Presidential Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Presidential Form");
			burr.executeForm(form);
			std::cout << std::endl;
		} 
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}


	std::cout << YELLOW << "\n========== TESTING ROBOTOMY FORM ==========\n" << RESET;
	{
		try {
			name = "Doug";
			grade = 6;
			target = "Rudy";
			Bureaucrat burr(name, grade);
			RobotomyRequestForm form(target);
			std::cout << CYAN << burr << RESET;
			test("signing", name, form.getGradeToSign(), "Robotomy Request");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Robotomy Request");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}

		try {
			name = "Ryan";
			grade = 50;
			target = "Jack";
			Bureaucrat burr(name, grade);
			RobotomyRequestForm form(target);
			std::cout << CYAN << burr << RESET;
			test("signing", name, form.getGradeToSign(), "Robotomy Request");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Robotomy Request");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}

		try {
			name = "Luke";
			grade = 80;
			target = "Robo";
			Bureaucrat burr(name, grade);
			RobotomyRequestForm form(target);
			std::cout << CYAN << burr << RESET;
			test("signing", name, form.getGradeToSign(), "Robotomy Request");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Robotomy Request");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << YELLOW << "\n========== TESTING SHRUBBERY FORM ==========\n" << RESET;
	{
		try {
			name = "Ralf";
			grade = 140;
			target = "home";
			Bureaucrat burr(name, grade);
			ShrubberyCreationForm form(target);
			std::cout << CYAN << burr << RESET;
			test("signing", name, form.getGradeToSign(), "Shrubbery Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Shrubbery Form");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}

		try {
			name = "Adam";
			grade = 150;
			target = "irrelevant";
			Bureaucrat burr(name, grade);
			ShrubberyCreationForm form(target);
			std::cout << CYAN << burr << RESET;
			test("signing", name, form.getGradeToSign(), "Shrubbery Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Shrubbery Form");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}

		try {
			name = "Jade";
			grade = 80;
			target = "Robo";
			Bureaucrat burr(name, grade);
			ShrubberyCreationForm form(target);
			std::cout << CYAN << burr << RESET;
			test("signing", name, form.getGradeToSign(), "Shrubbery Form");
			burr.signForm(form);
			test("executing", name, form.getGradeToExecute(), "Shrubbery Form");
			burr.executeForm(form);
			std::cout << "\n" << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	return 0;
}

