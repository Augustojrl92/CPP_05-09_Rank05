/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:12:33 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/02 22:34:54 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(75), gradeToExecute(75) 
{

}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) 
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) 
{

}

Form &Form::operator=(const Form &other) {
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form() 
{

}

const std::string &Form::getName() const 
{ 
    return name; 
}
bool Form::getIsSigned() const 
{ 
    return isSigned; 
}
int Form::getGradeToSign() const 
{ 
    return gradeToSign; 
}
int Form::getGradeToExecute() const 
{ 
    return gradeToExecute; 
}

void Form::beSigned(const Bureaucrat &b) 
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() 
{
    return "Form: Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form: Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form) 
{
    out << "Form \"" << form.getName() << "\" [sign grade: "
        << form.getGradeToSign() << ", exec grade: "
        << form.getGradeToExecute() << "] — Signed: "
        << (form.getIsSigned() ? "✅ Yes" : "❌ No");
    return out;
}
