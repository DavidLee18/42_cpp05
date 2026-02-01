#include "Form.h"
#include "Bureaucrat.h"
#include <iostream>

Form::Form()
    : _name("Form 1"), _signed(false), _sign_grade(150), _exec_grade(150) {}
Form::Form(std::string const &name, const unsigned char sign_grade,
           const unsigned char exec_grade) throw(GradeTooHighException,
                                                 GradeTooLowException)
    : _name(name), _signed(false),
      _sign_grade(sign_grade > 150 ? throw GradeTooLowException()
                  : sign_grade < 1 ? throw GradeTooHighException()
                                   : sign_grade),
      _exec_grade(exec_grade > 150 ? throw GradeTooLowException()
                  : exec_grade < 1 ? throw GradeTooHighException()
                                   : exec_grade) {}
Form::Form(Form const &other)
    : _name(other._name), _signed(other._signed),
      _sign_grade(other._sign_grade), _exec_grade(other._exec_grade) {}
Form &Form::operator=(Form const &other) {
  std::cout << "copying const fields is impossible, hence skipping..."
            << std::endl;
  _signed = other._signed;
  return *this;
}
Form::~Form() {}

std::string const &Form::getName() const { return _name; }
bool Form::getSigned() const { return _signed; }
unsigned char Form::getSignGrade() const { return _sign_grade; }
unsigned char Form::getExecGrade() const { return _exec_grade; }

void Form::beSigned(Bureaucrat const &br) throw(GradeTooLowException,
                                                AlreadySignedException) {
  if (_sign_grade < br.getGrade())
    throw GradeTooLowException();
  else if (_signed)
    throw AlreadySignedException();
  _signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "the grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "the grade is too low";
}

const char *Form::AlreadySignedException::what() const throw() {
  return "this form is already signed; cannot sign twice";
}

std::ostream &operator<<(std::ostream &os, Form const &form) {
  os << form.getName() << " (" << (form.getSigned() ? "signed" : "not signed")
     << "), grade to sign: " << static_cast<int>(form.getSignGrade())
     << ", grade to execute: " << static_cast<int>(form.getExecGrade());
  return os;
}
