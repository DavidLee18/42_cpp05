#include "ShrubberyCreationForm.h"
#include "Bureaucrat.h"
#include <fstream>
#include <ios>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137, "John Doe") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other) {}
ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
  dynamic_cast<AForm &>(*this) = dynamic_cast<AForm const &>(other);
  return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &br) const
    throw(AForm::GradeTooLowException, AForm::NotSignedException,
          std::ios_base::failure) {
  validate_exec(br);
  std::string outf_name(getTarget());
  outf_name += "_shrubbery";
  std::ofstream outf(outf_name.c_str());
  if (!outf.is_open())
    throw std::ios_base::failure("out file open failed");
  outf << "     ccee88oo" << std::endl;
  outf << "  C8O8O8Q8PoOb o8oo" << std::endl;
  outf << " dOB69QO8PdUOpugoO9bD" << std::endl;
  outf << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
  outf << "    6OuU  /p u gcoUodpP" << std::endl;
  outf << "      \\\\\\//  /douUP" << std::endl;
  outf << "        \\\\\\////" << std::endl;
  outf << "         |||/\\" << std::endl;
  outf << "         |||\\/" << std::endl;
  outf << "         |||||" << std::endl;
  outf << "   .....//||||\\...." << std::endl;

  std::cout << "successfully planted shrubbery to " << getTarget() << std::endl;
}
