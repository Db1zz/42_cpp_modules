#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <assert.h>

const std::string ShrubberyCreationForm::kFormName = "ShrubberyCreationForm";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
  : AForm(kFormName, kSignGrade, kExecGrade), target_(target)
{
  CheckTargetName();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
  : AForm(kFormName, kSignGrade, kExecGrade), target_(form.target_)
{
  CheckTargetName();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string &ShrubberyCreationForm::GetTarget() const {
  return target_;
}

void ShrubberyCreationForm::Execute(const Bureaucrat &bureaucrat) const {
  if (!IsSigned()) {
    throw UnsignedFormException();
  }
  if (!CanExecute(bureaucrat)) {
    throw GradeTooLowException();
  }

  std::ifstream in_stream("Art.txt", std::ios::ate);
  std::ofstream out_stream(target_ + "_shrubbery");
  if (!out_stream.is_open() || !in_stream.is_open()) {
    throw OpenFileException();
  }

  size_t in_stream_size = in_stream.tellg();
  std::string buffer(in_stream_size, '\0');
  in_stream.seekg(0);
  in_stream.read(&buffer[0], in_stream_size);
  out_stream.write(buffer.c_str(), buffer.size());

  in_stream.close();
  out_stream.close();
}

const char *ShrubberyCreationForm::OpenFileException::what() const throw() {
  return "ShrubberyCreationForm: Cannot open a file";
}

void ShrubberyCreationForm::CheckTargetName() const {
  try {
    if (target_.empty()) {
      throw EmptyTargetNameException();
    }
  } catch (const std::exception &error) {
    std::cout << "Error! " << error.what() << std::endl;
  }
}