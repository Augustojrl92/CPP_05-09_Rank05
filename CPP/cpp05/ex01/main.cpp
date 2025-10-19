/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:23:20 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/15 15:56:18 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// ANSI color macros
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

void test(std::string test_type, std::string name, int grade, std::string form) {
	if (test_type == "b_range")
		std::cout << CYAN << "Creating " << name << " with a grade of " << grade << ":\t" << RESET;
	else if (test_type == "increment")
		std::cout << CYAN << "Incrementing " << name << " (prev_grade = " << grade << "):\t" << RESET;
	else if (test_type == "decrement")
		std::cout << CYAN << "Decrementing " << name << " (prev_grade = " << grade << "):\t" << RESET;
	else if (test_type == "signing")
		std::cout << CYAN << name << " signing " << form << " with grade " << grade << ":\t" << RESET;
}

int main() {
	std::string name, form_name;
	int grade, sign_grade, exec_grade;

	std::cout << YELLOW << "\n========== TESTING GRADE RANGES ==========\n" << RESET;
	{
		try {
			name = "Bill"; grade = 10;
			test("b_range", name, grade, "(nil)");
			Bureaucrat bill(name, grade);
			std::cout << GREEN << "✅" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try {
			name = "Alex"; grade = 150;
			test("b_range", name, grade, "(nil)");
			Bureaucrat alex(name, grade);
			std::cout << GREEN << "✅" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try {
			name = "John"; grade = -10;
			test("b_range", name, grade, "(nil)");
			Bureaucrat john(name, grade);
			std::cout << GREEN << "✅" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try {
			name = "Carl"; grade = 151;
			test("b_range", name, grade, "(nil)");
			Bureaucrat carl(name, grade);
			std::cout << GREEN << "✅" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try {
			name = "ValidForm";
			test("b_range", name, 10, "(nil)");
			Form form(name, 10, 20);
			std::cout << GREEN << "✅" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try {
			name = "InvalidForm1";
			test("b_range", name, -10, "(nil)");
			Form form(name, -10, 20);
			std::cout << GREEN << "✅" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try {
			name = "InvalidForm2";
			test("b_range", name, 200, "(nil)");
			Form form(name, 10, 200);
			std::cout << GREEN << "✅" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}
	}

	std::cout << YELLOW << "\n========== TESTING INCREMENTATION ==========\n" << RESET;
	{
		try {
			name = "Kate"; grade = 10;
			test("increment", name, grade, "(nil)");
			Bureaucrat b(name, grade);
			b.incrementGrade();
			std::cout << GREEN << "✅" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try {
			name = "Jack"; grade = 1;
			test("increment", name, grade, "(nil)");
			Bureaucrat b(name, grade);
			b.incrementGrade();
			std::cout << GREEN << "✅" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}
	}

	std::cout << YELLOW << "\n========== TESTING DECREMENTATION ==========\n" << RESET;
	{
		try {
			name = "Anna"; grade = 10;
			test("decrement", name, grade, "(nil)");
			Bureaucrat b(name, grade);
			b.decrementGrade();
			std::cout << GREEN << "✅" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try {
			name = "Buck"; grade = 150;
			test("decrement", name, grade, "(nil)");
			Bureaucrat b(name, grade);
			b.decrementGrade();
			std::cout << GREEN << "✅" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}
	}

	std::cout << YELLOW << "\n========== TESTING FORM SIGNING ==========\n" << RESET;
	{
		{
			name = "Liam"; grade = 10;
			form_name = "NJ-3592"; sign_grade = 11; exec_grade = 1;
			test("signing", name, grade, form_name);
			Bureaucrat b(name, grade);
			Form f(form_name, sign_grade, exec_grade);
			b.signForm(f);
			std::cout << f << std::endl;
		}

		{
			name = "Noah"; grade = 10;
			form_name = "GD-412"; sign_grade = 5; exec_grade = 1;
			test("signing", name, grade, form_name);
			Bureaucrat b(name, grade);
			Form f(form_name, sign_grade, exec_grade);
			b.signForm(f);
			std::cout << f << std::endl;
		}

		{
			name = "Olivia"; grade = 5;
			form_name = "XD-888"; sign_grade = 10; exec_grade = 5;
			test("signing", name, grade, form_name);
			Bureaucrat b(name, grade);
			Form f(form_name, sign_grade, exec_grade);
			b.signForm(f);
			std::cout << f << std::endl;
		}
	}

	std::cout << std::endl;
	return 0;
}

