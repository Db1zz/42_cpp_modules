#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <assert.h>

const std::string ShrubberyCreationForm::kFormName = "ShrubberyCreationForm";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
  : AForm(target, kFormName, kSignGrade, kExecGrade) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
  : AForm(form.target_, kFormName, kSignGrade, kExecGrade) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::Enforcement() const {
  std::ifstream in_stream("Art.txt", std::ios::ate);
  std::ofstream out_stream((target_ + "_shrubbery").c_str());
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