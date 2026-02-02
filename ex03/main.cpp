#include "AForm.h"
#include "Bureaucrat.h"
#include "Intern.h"
#include <exception>
#include <iostream>
#include <unistd.h>

int main() {
  Intern mark;
  AForm *form1 = mark.makeForm("shrubbery creation", "Cluster");
  std::cout << *form1 << std::endl;
  Bureaucrat john;
  std::cout << "Test #1: try to sign a form with " << john << std::endl;
  john.signForm(*form1);

  std::cout << "Test #2: try to execute a not-signed form" << std::endl;
  Bureaucrat jane("Jane Doe", 5);
  jane.executeForm(*form1);

  AForm *form2 = mark.makeForm("robotomy request", "Cable");
  std::cout << "Test #3: try to execute a form with too-low grade" << std::endl;
  jane.signForm(*form1);
  john.executeForm(*form1);

  std::cout << "Test #4: execute each forms with " << jane << std::endl;

  AForm *form3;
  try {
    std::cout << "ShrubberyCreationForm: " << std::endl;
    jane.executeForm(*form1);
    jane.signForm(*form2);
    for (size_t i = 0; i < 5; i++) {
      std::cout << "RobotomyRequestForm #" << (i + 1) << ": " << std::endl;
      jane.executeForm(*form2);
    }
    std::cout << "PresidentialPardonForm: " << std::endl;
    form3 = mark.makeForm("presidential pardon", "John Walker");
    jane.signForm(*form3);
    jane.executeForm(*form3);

    std::cout << "Test #5: create a non-existent form" << std::endl;
    AForm *form4 = mark.makeForm("coffee brewing", "Mark");
    if (!form4)
      std::cout << "failed to create \"coffee brewing\" form for Mark!"
                << std::endl;
    else
      std::cout << "success! hey Mark, go brew coffee" << std::endl;
    if (form4)
      delete form4;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  delete form3;
  delete form2;
  delete form1;

  return 0;
}
