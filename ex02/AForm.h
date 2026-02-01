#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.h"
#include <exception>
#include <ios>
#include <ostream>
#include <string>

class AForm {
  const std::string _name;
  bool _signed;
  const unsigned char _sign_grade;
  const unsigned char _exec_grade;
  const std::string _target;

protected:
  void validate_exec(Bureaucrat const &) const
      throw(GradeTooLowException, NotSignedException);

public:
  AForm();
  AForm(std::string const &, const unsigned char, const unsigned char,
        std::string const &) throw(GradeTooHighException, GradeTooLowException);
  AForm(AForm const &);
  AForm &operator=(AForm const &);
  ~AForm();

  std::string const &getName() const;
  bool getSigned() const;
  unsigned char getSignGrade() const;
  unsigned char getExecGrade() const;
  std::string const &getTarget() const;

  void beSigned(Bureaucrat const &) throw(GradeTooLowException,
                                          AlreadySignedException);
  virtual void execute(Bureaucrat const &) const
      throw(GradeTooLowException, NotSignedException,
            std::ios_base::failure) = 0;

  class GradeTooHighException : public std::exception {
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };
  class AlreadySignedException : public std::exception {
    const char *what() const throw();
  };
  class NotSignedException : public std::exception {
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &, AForm const &);

#endif
