#include "Bureaucrat.hpp"

        Bureaucrat:: Bureaucrat() : name("defaul"), grade(1)
        {

        }
        Bureaucrat:: Bureaucrat(std::string const &name, int grade): name(name)
        {
            if(grade < 1)
                throw GradeTooHighException();
            else if(grade>150)
                throw GradeTooLowException();
            this->grade = grade;
        } 
        Bureaucrat:: Bureaucrat(const Bureaucrat &other)
        {
            *this = other;
        }
        Bureaucrat &Bureaucrat ::operator=(Bureaucrat const &other)
        {
            if(this == &other)
                return(*this);
            this->grade = other.grade;
            return(*this);
        }


        Bureaucrat::~Bureaucrat()
        {
            
        }

        const std::string &Bureaucrat:: getName() const
        {
            return name;
        }
        int  Bureaucrat::getGrade() const
        {
            return grade;
        }

        void Bureaucrat::incrementGrade()
        {
            if(grade -1 < 1)
                throw GradeTooHighException();
            grade --;
        }
        void Bureaucrat::decrementGrade()
        {
            if(grade + 1 > 150)
                throw GradeTooLowException();
            grade ++;
        }

        std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
        {
            out<< obj.getName()<<", bureaucrat grade"<< obj.getGrade()<< std::endl;
            return( out);
        }

        const char *Bureaucrat::GradeTooHighException:: what() const throw()
        {
            return "Grade too high";
        }

        const char *Bureaucrat::GradeTooLowException:: what() const throw()
        {
            return "Grade too low";
        }

        void Bureaucrat::signForm(AForm &form)
        {
            try
            {
                form.beSigned(*this);
		        std::cout << "✅  --->  (" << name << " signed " << form.getName() << ")" << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "❌  --->  (" << name << " couldn't sign " << form.getName() << " because " << e.what() << ")" << std::endl;
            }
            
        }



        void Bureaucrat::executeForm(const AForm& form) const {
            try 
            {
                form.execute(*this);
                std::cout << "✅  --->  (" << name << " executed " << form.getName() << ")" << std::endl;
            } 
            catch (const std::exception& e) 
            {
                std::cout << "❌  --->  (" << name << " couldn't execute " << form.getName()
                        << " because " << e.what() << ")" << std::endl;
            }
        }
