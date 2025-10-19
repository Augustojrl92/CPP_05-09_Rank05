/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:23:20 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/10 13:06:35 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Colores (ANSI)
#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define YELLOW  "\033[33m"

void	test(std::string test_type, std::string name, int grade) {
	if (test_type == "range")
		std::cout << CYAN << "🧪 Creating " << name << " with a grade of " << grade << ":\t" << RESET;
	else if (test_type == "increment")
		std::cout << CYAN << "⬆️  Incrementing " << name << " (prev_grade = " << grade << "):\t" << RESET;
	else if (test_type == "decrement")
		std::cout << CYAN << "⬇️  Decrementing " << name << " (prev_grade = " << grade << "):\t" << RESET;
}

int	main() 
{
	std::string name;
	int			grade;

	std::cout << YELLOW << "\n========== TESTING GRADE RANGES ==========\n" << RESET;
	
		try 
		{
			name = "Bill";
			grade = 10;
			test("range", name, grade);
			Bureaucrat bill(name, grade);
			std::cout << GREEN << "✅  " << RESET << bill << std::endl;
		} 
		catch (std::exception &e) 
		{
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try 
		{
			name = "Alex";
			grade = 150;
			test("range", name, grade);
			Bureaucrat alex(name, grade);
			std::cout << GREEN << "✅  " << RESET << alex << std::endl;
		} 
		catch (std::exception &e) 
		{
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try
		{
			name = "John";
			grade = -10;
			test("range", name, grade);
			Bureaucrat john(name, grade);
			std::cout << GREEN << "✅  " << RESET << john << std::endl;
		} 
		catch (std::exception &e) 
		{
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try 
		{
			name = "Carl";
			grade = 151;
			test("range", name, grade);
			Bureaucrat carl(name, grade);
			std::cout << GREEN << "✅  " << RESET << carl << std::endl;
		} 
		catch (std::exception &e)
		{
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}
	

		std::cout << YELLOW << "\n========== TESTING INCREMENTATION ==========\n" << RESET;
	
		try 
		{
			name = "Kate";
			grade = 10;
			test("increment", name, grade);
			Bureaucrat kate(name, grade);
			kate.incrementGrade();
			std::cout << GREEN << "✅  " << RESET << kate << std::endl;
		} 
		catch (std::exception &e) 
		{
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try 
		{
			name = "Jack";
			grade = 1;
			test("increment", name, grade);
			Bureaucrat jack(name, grade);
			jack.incrementGrade();
			std::cout << GREEN << "✅  " << RESET << jack << std::endl;
		} 
		catch (std::exception &e) 
		{
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}
	

		std::cout << YELLOW << "\n========== TESTING DECREMENTATION ==========\n" << RESET;
	
		try 
		{
			name = "Anna";
			grade = 10;
			test("decrement", name, grade);
			Bureaucrat anna(name, grade);
			anna.decrementGrade();
			std::cout << GREEN << "✅  " << RESET << anna << std::endl;
		} 
		catch (std::exception &e) 
		{
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}

		try 
		{
			name = "Buck";
			grade = 150;
			test("decrement", name, grade);
			Bureaucrat buck(name, grade);
			buck.decrementGrade();
			std::cout << GREEN << "✅  " << RESET << buck << std::endl;
		} 
		catch (std::exception &e) 
		{
			std::cout << RED << "❌  --->  (" << e.what() << ")" << RESET << std::endl;
		}
	

	std::cout << std::endl;
	return 0;
}
