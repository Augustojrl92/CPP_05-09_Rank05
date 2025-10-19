/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:23:20 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/15 20:22:38 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

void test(const std::string& test_type, const std::string& name, int grade, const std::string& form) {
	if (test_type == "creating")
		std::cout << "🛠️  Intern is creating form for " << name << "...\n";
	else if (test_type == "b_range")
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

int main() {
	std::string name, target;
	int grade;

	std::cout << YELLOW << "\n========== TESTING INTERN ==========\n" << RESET;
	{
		try {
			name = "John";
			grade = 20;
			Intern intern;
			Bureaucrat burr(name, grade);
			std::cout << CYAN << burr << RESET;
			test("creating", name, 0, "");
			AForm *form = intern.makeForm("presidential pardon", "Bob");
			if (form) {
				test("signing", name, form->getGradeToSign(), "Presidential Pardon");
				burr.signForm(*form);
				test("executing", name, form->getGradeToExecute(), "Presidential Pardon");
				burr.executeForm(*form);
				delete form;
			}
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}

		try {
			name = "Anne";
			grade = 40;
			Intern intern;
			Bureaucrat burr(name, grade);
			std::cout << CYAN << burr << RESET;
			test("creating", name, 0, "");
			AForm *form = intern.makeForm("robotomy request", "Doll");
			if (form) {
				test("signing", name, form->getGradeToSign(), "Robotomy Request");
				burr.signForm(*form);
				test("executing", name, form->getGradeToExecute(), "Robotomy Request");
				burr.executeForm(*form);
				delete form;
			}
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}

		try {
			name = "Paul";
			grade = 140;
			Intern intern;
			Bureaucrat burr(name, grade);
			std::cout << CYAN << burr << RESET;
			test("creating", name, 0, "");
			AForm *form = intern.makeForm("shrubbery creation", "home");
			if (form) {
				test("signing", name, form->getGradeToSign(), "Shrubbery Creation");
				burr.signForm(*form);
				test("executing", name, form->getGradeToExecute(), "Shrubbery Creation");
				burr.executeForm(*form);
				delete form;
			}
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}

		try {
			name = "Invalid";
			grade = 30;
			Intern intern;
			Bureaucrat burr(name, grade);
			std::cout << CYAN << burr << RESET;
			test("creating", name, 0, "");
			AForm *form = intern.makeForm("random form", "Bob");
			if (form) {
				test("signing", name, form->getGradeToSign(), "Unknown Form");
				burr.signForm(*form);
				test("executing", name, form->getGradeToExecute(), "Unknown Form");
				burr.executeForm(*form);
				delete form;
			}
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	return 0;
}
