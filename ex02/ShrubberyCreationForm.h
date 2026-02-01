#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

#include "AForm.h"
#include "Bureaucrat.h"
#include <ios>

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string const &);
  ShrubberyCreationForm(ShrubberyCreationForm const &);
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat const &) const
      throw(AForm::GradeTooLowException, AForm::NotSignedException,
            std::ios_base::failure);
};

#endif
