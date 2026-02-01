#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <iostream>

Intern::Intern() : funcs() {
  funcs[0] = &Intern::makeNothing;
  funcs[1] = &Intern::makeShrubberyCreationForm;
  funcs[2] = &Intern::makeRobotomyRequestForm;
  funcs[4] = &Intern::makePresidentialPardonForm;
}

Intern::Intern(Intern const &other) : funcs() {
  for (size_t i = 0; i < 5; i++) {
    funcs[i] = other.funcs[i];
  }
}

Intern &Intern::operator=(Intern const &other) {
  if (this != &other) {
    for (size_t i = 0; i < 5; i++) {
      funcs[i] = other.funcs[i];
    }
  }
  return *this;
}

Intern::~Intern() {}

AForm *Intern::makeNothing(std::string const &) { return NULL; }
AForm *Intern::makeShrubberyCreationForm(std::string const &target) {
  std::cout << "Intern creates a ShrubberyCreationForm" << std::endl;
  return new ShrubberyCreationForm(target);
}
AForm *Intern::makeRobotomyRequestForm(std::string const &target) {
  std::cout << "Intern creates a RobotomyRequestForm" << std::endl;
  return new RobotomyRequestForm(target);
}
AForm *Intern::makePresidentialPardonForm(std::string const &target) {
  std::cout << "Intern creates a PresidentialPardonForm" << std::endl;
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) {
  size_t i = (name == "shrubbery creation") +
             static_cast<size_t>((name == "robotomy request") << 1) +
             static_cast<size_t>((name == "presidential pardon") << 2);
  return funcs[i](target);
}
