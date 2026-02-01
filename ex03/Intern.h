#ifndef INTERN_H
#define INTERN_H

#include "AForm.h"
#include <string>

typedef AForm *(*Generator)(std::string const &);

class Intern {
  Generator funcs[5];

  static AForm *makeNothing(std::string const &);
  static AForm *makeShrubberyCreationForm(std::string const &);
  static AForm *makeRobotomyRequestForm(std::string const &);
  static AForm *makePresidentialPardonForm(std::string const &);

public:
  Intern();
  Intern(Intern const &);
  Intern &operator=(Intern const &);
  ~Intern();

  AForm *makeForm(std::string const &, std::string const &);
};

#endif
