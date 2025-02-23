#include "BitcoinExchange.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <climits>
#include <limits>

extern bool validate_date(const std::string &date);
extern std::vector<int> extract_keys_from_date(const std::string &date);

BitcoinExchange::BitcoinExchange(const DateTree &db_tree, const std::vector<Date> &input)
: input_max_val_(1000), db_tree_(db_tree), input_(input)
{
  std::cout << "Default BitcoinExchange constructor called\n";
}

BitcoinExchange::~BitcoinExchange() {
  std::cout << "Default BitcoinExchange destructor called\n";
}

bool BitcoinExchange::AreKeysLessOrEqual(
  const std::vector<int> date_keys1, const std::vector<int> &date_keys2)
{
  if (date_keys1[0] < date_keys2[0]) return true;
  if (date_keys1[0] > date_keys2[0]) return false;
  
  if (date_keys1[1] < date_keys2[1]) return true;
  if (date_keys1[1] > date_keys2[1]) return false;

  return date_keys1[2] <= date_keys2[2];
}

template <typename TreeBranch, int MapDepth>
Date BitcoinExchange::GetDate(
  TreeBranch &date_tree, const std::vector<int> &date_keys)
{
  typedef typename TreeBranch::mapped_type MappedType;

  typename TreeBranch::iterator branch_it = date_tree.find(date_keys[MapDepth]);
  if (branch_it == date_tree.end()) {
    while (branch_it != date_tree.begin()) {
      --branch_it;
      Date date = 
        GetDate<MappedType, MapDepth + 1>(branch_it->second, date_keys);

      if (date.date_str.empty()) {
        continue;
      }

      return date;
    }
  }
  return GetDate<MappedType, MapDepth + 1>(branch_it->second, date_keys);
}

/*
  Base case for GetDate() template recursion lmao(IT'S SO CUTE, LUV IT)
*/
template <>
Date BitcoinExchange::GetDate<Date, 3>(
    Date &date, const std::vector<int> &date_keys)
{
  if (AreKeysLessOrEqual(date.date_keys, date_keys)) {
    return date;
  }
  return Date();
}

void BitcoinExchange::Exchange() {
  for (size_t i = 0; i < input_.size(); i++) {
    Date &input_date = input_[i];

    try {
      IsDateValidInput(input_date);

      Date date = GetDate<DateTree, 0>(db_tree_, input_date.date_keys);
      std::cout << input_date.date_str << " => "
                << input_date.date_value << " = "
                << input_date.date_value * date.date_value <<  std::endl;

    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << " => "
                << input_date.date_str << std::endl;
      continue;
    }
  }
}

const char *BitcoinExchange::NegativeNumberException::what() const throw() {
  return "Number is not positive";
}

const char *BitcoinExchange::BigNumberException::what() const throw() {
  return "Number is too big";
}

const char *BitcoinExchange::BadInputException::what() const throw() {
  return "Bad input";
}

void BitcoinExchange::IsDateValidInput(const Date &date) {
  if (date.date_value < 0) {
    throw NegativeNumberException();
  } else if (date.date_value > input_max_val_) {
    throw BigNumberException();
  } else if (!validate_date(date.date_str)) {
    throw BadInputException();
  }
}
