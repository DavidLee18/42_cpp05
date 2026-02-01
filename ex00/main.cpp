#include "Bureaucrat.h"
#include <exception>
#include <iostream>

int main() {
  Bureaucrat john("John Doe", 149);
  std::cout << "Test #1: " << john << std::endl;

  try {
    std::cout << "Test #2: try to create a bureaucrat with a too-high grade"
              << std::endl;
    std::cout << Bureaucrat("Jane Doe", 0) << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::cout << "Test #3: try to create a bureaucrat with a too-low grade"
              << std::endl;
    std::cout << Bureaucrat("Max", 151) << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat jane("Jane Doe", 2);
    std::cout << "Test #4: try to increment the grade of " << jane << std::endl;
    jane.incrementGrade();
    std::cout << "successfully incremented the grade, now " << jane
              << std::endl;
    std::cout << "Test #5: try to increment the grade of " << jane << std::endl;
    jane.incrementGrade();
    std::cout << "successfully incremented the grade, now " << jane
              << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::cout << "Test #6: try to decrement the grade of " << john << std::endl;
    john.decrementGrade();
    std::cout << "successfully decremented the grade, now " << john
              << std::endl;
    std::cout << "Test #7: try to decrement the grade of " << john << std::endl;
    john.decrementGrade();
    std::cout << "successfully decremented the grade, now " << john
              << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
