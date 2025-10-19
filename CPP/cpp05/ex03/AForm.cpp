/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:12:33 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/03 11:10:19 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(1), gradeToExecute(1) 
{

}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) 
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) 
{

}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() 
{

}

const std::string &AForm::getName() const 
{ 
    return name; 
}
bool AForm::getIsSigned() const 
{ 
    return isSigned; 
}
int AForm::getGradeToSign() const 
{ 
    return gradeToSign; 
}
int AForm::getGradeToExecute() const 
{ 
    return gradeToExecute; 
}

void AForm::beSigned(const Bureaucrat &b) 
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::checkExecutability(const Bureaucrat &executor) const 
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() 
{
    return "AForm: Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "AForm: Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "AForm: Form not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) 
{
    out << "AForm \"" << form.getName() << "\" [sign grade: "
        << form.getGradeToSign() << ", exec grade: "
        << form.getGradeToExecute() << "] — Signed: "
        << (form.getIsSigned() ? "✅ Yes" : "❌ No");
    return out;
}
