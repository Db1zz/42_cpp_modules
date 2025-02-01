#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cassert>

void test_empty_target_name() {
  std::cout << "\n======= Empty Target Name Test =======" << std::endl;
  try {
    Bureaucrat aboba("Aboba", 137);
    ShrubberyCreationForm tree("");
    aboba.SignForm(tree);
    aboba.ExecuteForm(tree);
  } catch (const std::exception &error) {
    std::cout << "Exception: " << error.what() << std::endl;
  }
}

void test_low_grade_to_sign() {
  std::cout << "\n======= Low Grade to Sign Test =======" << std::endl;
  try {
    Bureaucrat aboba("Aboba", 150);
    ShrubberyCreationForm tree("AYAYAYA");
    aboba.SignForm(tree);
    aboba.ExecuteForm(tree);
  } catch (const std::exception &error) {
    std::cout << "Exception: " << error.what() << std::endl;
  }
}

void test_low_grade_to_execute() {
  std::cout << "\n======= Low Grade to Execute Test =======" << std::endl;
  try {
    Bureaucrat aboba("Aboba", 138);
    ShrubberyCreationForm tree("AYAYAYA");
    aboba.SignForm(tree);
    aboba.ExecuteForm(tree);
  } catch (const std::exception &error) {
    std::cout << "Exception: " << error.what() << std::endl;
  }
}

void test_normal_operation() {
  std::cout << "\n======= Normal Operation Test =======" << std::endl;
  try {
    Bureaucrat aboba("Aboba", 1);
    ShrubberyCreationForm tree("AYAYAYA");
    aboba.SignForm(tree);
    aboba.ExecuteForm(tree);
  } catch (const std::exception &error) {
    std::cout << "Exception: " << error.what() << std::endl;
  }
}

void test_already_signed_form() {
  std::cout << "\n======= Already Signed Form Test =======" << std::endl;
  Bureaucrat aboba("Aboba", 1);
  ShrubberyCreationForm tree("AYAYAYA");
  try {
    aboba.SignForm(tree);
    aboba.SignForm(tree);
  } catch (const std::exception &error) {
    std::cout << "Exception: " << error.what() << std::endl;
  }
}

void test_unsigned_form_execution() {
  std::cout << "\n======= Unsigned Form Execution Test =======" << std::endl;
  Bureaucrat aboba("Aboba", 1);
  ShrubberyCreationForm tree("AYAYAYA");
  try {
    aboba.ExecuteForm(tree);
  } catch (const std::exception &error) {
    std::cout << "Exception: " << error.what() << std::endl;
  }
}

void shrubbery_tests() {
  test_empty_target_name();
  test_low_grade_to_sign();
  test_low_grade_to_execute();
  test_normal_operation();
  test_already_signed_form();
  test_unsigned_form_execution();
}

void test_random() {
  try {
    std::cout << "\n======= Randomizer Test =======" << std::endl;
    Bureaucrat aboba("Aboba", 1);
    RobotomyRequestForm robot("4elik");
    aboba.SignForm(robot);
    aboba.ExecuteForm(robot);
  } catch (const std::exception &error) {
    std::cout << "Exception: " << error.what() << std::endl;
  }
}

void robotomy_tests() {
  test_random();
}

void pardon_test() {
  try {
    std::cout << "\n======= Pardon Test =======" << std::endl;
    Bureaucrat aboba("Aboba", 5);
    PresidentialPardonForm robot("4elik");
    aboba.SignForm(robot);
    aboba.ExecuteForm(robot);
  } catch (const std::exception &error) {
    std::cout << "Exception: " << error.what() << std::endl;
  }
}

void presidential_tests() {
  pardon_test();
}

int main() {
  // shrubbery_tests();
  // robotomy_tests();
  presidential_tests();
  return 0;
}