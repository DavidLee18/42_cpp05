#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <exception>
#include <ostream>
#include <string>

class AForm;

class Bureaucrat {
  const std::string _name;
  unsigned char _grade;

public:
  Bureaucrat();
  Bureaucrat(std::string const &, unsigned char) throw(GradeTooHighException,
                                                       GradeTooLowException);
  Bureaucrat(Bureaucrat const &);
  Bureaucrat &operator=(Bureaucrat const &);
  ~Bureaucrat();

  std::string const &getName() const;
  unsigned char getGrade() const;

  void incrementGrade() throw(GradeTooHighException);
  void decrementGrade() throw(GradeTooLowException);

  void signForm(AForm &);
  void executeForm(AForm const &) const;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &, Bureaucrat const &);

#endif
