#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5, "John Doe") {}
PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("PresidentialPardonForm", 25, 5, target) {}
PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &other)
    : AForm(other) {}
PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
  dynamic_cast<AForm &>(*this) = dynamic_cast<AForm const &>(other);
  return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &br) const
    throw(AForm::GradeTooLowException, AForm::NotSignedException) {
  validate_exec(br);
  std::cout << getTarget() << " has now been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
