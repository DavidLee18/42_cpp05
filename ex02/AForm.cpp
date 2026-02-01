#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>

AForm::AForm()
    : _name("AForm 1"), _signed(false), _sign_grade(150), _exec_grade(150),
      _target("John Doe") {}
AForm::AForm(std::string const &name, const unsigned char sign_grade,
             const unsigned char exec_grade,
             std::string const &target) throw(GradeTooHighException,
                                              GradeTooLowException)
    : _name(name), _signed(false),
      _sign_grade(sign_grade > 150 ? throw GradeTooLowException()
                  : sign_grade < 1 ? throw GradeTooHighException()
                                   : sign_grade),
      _exec_grade(exec_grade > 150 ? throw GradeTooLowException()
                  : exec_grade < 1 ? throw GradeTooHighException()
                                   : exec_grade),
      _target(target) {}
AForm::AForm(AForm const &other)
    : _name(other._name), _signed(other._signed),
      _sign_grade(other._sign_grade), _exec_grade(other._exec_grade) {}
AForm &AForm::operator=(AForm const &other) {
  std::cout << "copying const fields is impossible, hence skipping..."
            << std::endl;
  _signed = other._signed;
  return *this;
}
AForm::~AForm() {}

std::string const &AForm::getName() const { return _name; }
bool AForm::getSigned() const { return _signed; }
unsigned char AForm::getSignGrade() const { return _sign_grade; }
unsigned char AForm::getExecGrade() const { return _exec_grade; }
std::string const &AForm::getTarget() const { return _target; }

void AForm::beSigned(Bureaucrat const &br) throw(GradeTooLowException,
                                                 AlreadySignedException) {
  if (_sign_grade < br.getGrade())
    throw GradeTooLowException();
  else if (_signed)
    throw AlreadySignedException();
  _signed = true;
}

void AForm::validate_exec(Bureaucrat const &br) const
    throw(GradeTooLowException, NotSignedException) {
  if (br.getGrade() > _exec_grade)
    throw GradeTooLowException();
  else if (!_signed)
    throw NotSignedException();
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "the grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "the grade is too low";
}

const char *AForm::AlreadySignedException::what() const throw() {
  return "this form is already signed; cannot sign twice";
}

const char *AForm::NotSignedException::what() const throw() {
  return "this form is not yet signed, but called to be executed";
}

std::ostream &operator<<(std::ostream &os, AForm const &form) {
  os << form.getName() << " (" << (form.getSigned() ? "signed" : "not signed")
     << "), grade to sign: " << static_cast<int>(form.getSignGrade())
     << ", grade to execute: " << static_cast<int>(form.getExecGrade())
     << ", target: " << form.getTarget();
  return os;
}
