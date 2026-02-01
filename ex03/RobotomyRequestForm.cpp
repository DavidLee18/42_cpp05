#include "RobotomyRequestForm.h"
#include "Bureaucrat.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45, "John Doe") {}
RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("RobotomyRequestForm", 72, 45, target) {}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other) {}
RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
  dynamic_cast<AForm &>(*this) = dynamic_cast<AForm const &>(other);
  return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &br) const
    throw(AForm::GradeTooLowException, AForm::NotSignedException) {
  validate_exec(br);
  std::srand(static_cast<unsigned int>(std::time(NULL)));
  if (std::rand() % 2 == 0)
    std::cout << "FAILED to robotomize " << getTarget() << std::endl;
  else
    std::cout << "SUCCEEDED to robotomize " << getTarget() << std::endl;
}
