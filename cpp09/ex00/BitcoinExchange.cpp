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

BitcoinExchange::BitcoinExchange(const DateTree &db_tree, const std::vector<DateData> &input)
: input_max_val_(1000), db_tree_(db_tree), input_(input)
{
  std::cout << "Default BitcoinExchange constructor called\n";
}

BitcoinExchange::~BitcoinExchange() {
  std::cout << "Default BitcoinExchange destructor called\n";
}

/*
  TODO:

  If the date used in the input does not exist in your DB then you
  must use the closest date contained in your DB. Be careful to use the
  lower date and not the upper one.
*/
template <typename TreeBranch, int MapDepth>
double BitcoinExchange::GetDateValue(
  TreeBranch &date_tree, const std::vector<int> &tree_keys)
{
  typedef typename TreeBranch::mapped_type MappedType;

  typename TreeBranch::iterator branch_it = date_tree.find(tree_keys[MapDepth]);
  if (branch_it == date_tree.end()) {
    double val = 
      GetDateValue<MappedType, MapDepth + 1>(date_tree.end()->second, tree_keys);
    return val;
  }
  return GetDateValue<MappedType, MapDepth + 1>(branch_it->second, tree_keys);
}

/*
  Base case for GetDateValue() template recursion lmao(IT'S SO CUTE, LUV IT)
*/
template <>
double BitcoinExchange::GetDateValue<DateData, 3>(DateData &data, const std::vector<int> &tree_keys) {
  tree_keys[0];
  if (data.first.empty()) {
    return std::numeric_limits<double>::max();
  }
  return data.second;
}

void BitcoinExchange::Exchange() {
  for (size_t i = 0; i < input_.size(); i++) {
    DateData &date = input_[i];

    try {
      IsDateDataValidInput(date);
      std::vector<int> tree_keys = extract_keys_from_date(date.first);
      double db_value = GetDateValue<DateTree, 0>(db_tree_, tree_keys);
      std::cout << "db_value: " << db_value << std::endl;
      std::cout << date.first << " => " << date.second << " = "
                << date.second * db_value <<  std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << " => " << date.first << std::endl;
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

void BitcoinExchange::IsDateDataValidInput(const DateData &date) {
  if (date.second < 0) {
    throw NegativeNumberException();
  } else if (date.second > input_max_val_) {
    throw BigNumberException();
  } else if (!validate_date(date.first)) {
    throw BadInputException();
  }
}
