#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include "AForm.h"
#include "Bureaucrat.h"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string const &);
  PresidentialPardonForm(PresidentialPardonForm const &);
  PresidentialPardonForm &operator=(PresidentialPardonForm const &);
  ~PresidentialPardonForm();

  void execute(Bureaucrat const &) const
      throw(AForm::GradeTooLowException, AForm::NotSignedException);
};

#endif
