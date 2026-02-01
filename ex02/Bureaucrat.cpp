#include "Bureaucrat.h"
#include "AForm.h"
#include <exception>
#include <iostream>

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150) {}
Bureaucrat::Bureaucrat(std::string const &name,
                       unsigned char grade) throw(GradeTooHighException,
                                                  GradeTooLowException)
    : _name(name) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  _grade = grade;
}
Bureaucrat::Bureaucrat(Bureaucrat const &other)
    : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
  if (this != &other) {
    _grade = other._grade;
    std::cout << "Bureaucrat::operator=() called but _name is const... doing "
                 "nothing..."
              << std::endl;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string const &Bureaucrat::getName() const { return _name; }
unsigned char Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() throw(GradeTooHighException) {
  if (_grade == 1)
    throw GradeTooHighException();
  _grade--;
}
void Bureaucrat::decrementGrade() throw(GradeTooLowException) {
  if (_grade == 150)
    throw GradeTooLowException();
  _grade++;
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << _name << " successfully signed " << form.getName()
              << std::endl;
  } catch (std::exception &e) {
    std::cerr << _name << " couldn't sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) const {
  try {
    form.execute(*this);
    std::cout << _name << " executed " << form << std::endl;
  } catch (std::exception &e) {
    std::cerr << _name << " couldn't execute the form: " << e.what()
              << std::endl;
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "The grade is too high";
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "The grade is too low";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &br) {
  os << br.getName() << ", bureaucrat grade " << static_cast<int>(br.getGrade())
     << '.';
  return os;
}
