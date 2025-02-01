#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void shrubbery_tests() {
  try {
    std::cout << "\n======= Empty name Test =======" << std::endl;
    Bureaucrat aboba("Aboba)", 137);
    ShrubberyCreationForm tree("");
    aboba.SignForm(tree);
    aboba.ExecuteForm(tree);
  } catch (const std::exception &error) {
    std::cout << "Error! " << error.what() << std::endl; 
  }
  try {
    std::cout << "\n======= Low Grade Test =======" << std::endl;
    Bureaucrat aboba("Aboba)", 150);
    ShrubberyCreationForm tree("AYAYAYA");
    aboba.SignForm(tree);
    aboba.ExecuteForm(tree);
  } catch (const std::exception &error) {
    std::cout << "Error! " << error.what() << std::endl; 
  }
  try {
    std::cout << "\n======= Low Exec. Grade Test =======" << std::endl;
    Bureaucrat aboba("Aboba)", 138);
    ShrubberyCreationForm tree("AYAYAYA");
    aboba.SignForm(tree);
    aboba.ExecuteForm(tree);
  } catch (const std::exception &error) {
    std::cout << "Error! " << error.what() << std::endl; 
  }
  try {
    std::cout << "\n======= Normal Test =======" << std::endl;
    Bureaucrat aboba("Aboba)", 0);
    ShrubberyCreationForm tree("AYAYAYA");
    aboba.SignForm(tree);
    aboba.ExecuteForm(tree);
  } catch (const std::exception &error) {
    std::cout << "Error! " << error.what() << std::endl; 
  }
}

void robotomy_tests() {

}

int main() {
  shrubbery_tests();
	return 0;
}
