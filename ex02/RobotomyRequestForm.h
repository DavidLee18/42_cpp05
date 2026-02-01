#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include "AForm.h"
#include "Bureaucrat.h"

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string const &);
  RobotomyRequestForm(RobotomyRequestForm const &);
  RobotomyRequestForm &operator=(RobotomyRequestForm const &);
  ~RobotomyRequestForm();

  void execute(Bureaucrat const &) const
      throw(AForm::GradeTooLowException, AForm::NotSignedException);
};

#endif
