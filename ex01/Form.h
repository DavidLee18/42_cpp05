#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.h"
#include <exception>
#include <ostream>
#include <string>

class Form {
  const std::string _name;
  bool _signed;
  const unsigned char _sign_grade;
  const unsigned char _exec_grade;

public:
  Form();
  Form(std::string const &, const unsigned char,
       const unsigned char) throw(GradeTooHighException, GradeTooLowException);
  Form(Form const &);
  Form &operator=(Form const &);
  ~Form();

  std::string const &getName() const;
  bool getSigned() const;
  unsigned char getSignGrade() const;
  unsigned char getExecGrade() const;

  void beSigned(Bureaucrat const &) throw(GradeTooLowException,
                                          AlreadySignedException);

  class GradeTooHighException : public std::exception {
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };
  class AlreadySignedException : public std::exception {
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &, Form const &);

#endif
