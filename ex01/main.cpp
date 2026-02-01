#include "Bureaucrat.h"
#include "Form.h"
#include <exception>
#include <iostream>

int main() {
  Form form1("Form 1", 4, 42);
  std::cout << "Test #1: " << form1 << std::endl;

  try {
    std::cout << "Test #2: try to create a form with a too-high grade"
              << std::endl;
    std::cout << Form("Form 2", 0, 1) << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::cout << "Test #3: try to create a form with a too-low grade"
              << std::endl;
    std::cout << Form("Form 3", 12, 151) << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat jane("Jane Doe", 5);
    std::cout << "Test #4: try to sign the form with " << jane << std::endl;
    jane.signForm(form1);
    std::cout
        << "Test #5: try to sign the form after incrementing the grade of "
        << jane << std::endl;
    jane.incrementGrade();
    jane.signForm(form1);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat john("John Doe", 4);
    std::cout << "Test #6: try to sign an already signed form with " << john
              << std::endl;
    john.signForm(form1);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
