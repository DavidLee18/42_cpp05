#include "AForm.h"
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <exception>
#include <iostream>
#include <unistd.h>

int main() {
  ShrubberyCreationForm form1("Cluster");
  std::cout << form1 << std::endl;
  Bureaucrat john;
  std::cout << "Test #1: try to sign a form with " << john << std::endl;
  john.signForm(form1);

  std::cout << "Test #2: try to execute a not-signed form" << std::endl;
  Bureaucrat jane("Jane Doe", 5);
  jane.executeForm(form1);

  RobotomyRequestForm form2("Cable");
  std::cout << "Test #3: try to execute a form with too-low grade" << std::endl;
  jane.signForm(form1);
  john.executeForm(form1);

  std::cout << "Test #4: execute each forms with " << jane << std::endl;

  try {
    std::cout << "ShrubberyCreationForm: " << std::endl;
    jane.executeForm(form1);
    jane.signForm(form2);
    for (size_t i = 0; i < 5; i++) {
      std::cout << "RobotomyRequestForm #" << (i + 1) << ": " << std::endl;
      jane.executeForm(form2);
    }
    std::cout << "PresidentialPardonForm: " << std::endl;
    PresidentialPardonForm form3("John Walker");
    jane.signForm(form3);
    jane.executeForm(form3);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
