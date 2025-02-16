#include "BitcoinExchange.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

#define YEAR_INDEX 0
#define MONTH_INDEX 5
#define DAY_INDEX 8

template <typename TreeBranch, int index>
int BitcoinExchange::GetDateData(TreeBranch &date_tree, std::vector<int> date) {
  typename TreeBranch::iterator branch_it = date_tree.find(date[index]);
  if (branch_it == date_tree.end()) {
    return INT_MIN;
  } else if (index == 0) {
    return branch_it.second.second;
  } else {
    return GetDateData<TreeBranch, index - 1>((*branch_it).second, date);
  }
}

bool BitcoinExchange::AddValue(DateTree &date_tree, DateData date_data) {
  std::vector<int> date = ExtractDateFromAString(date_data.first);

}

bool BitcoinExchange::RemoveValue(DateTree &date_tree, DateData date_data) {

}

std::vector<int> BitcoinExchange::ExtractDateFromAString(const std::string &date) {
  std::vector<int> year_month_day;
  size_t pos = 0;

  year_month_day.push_back(atoi(date.c_str()));
  while ((pos = date.find('-', pos)) != std::string::npos) {
    ++pos;
    year_month_day.push_back(atoi(date.c_str() + pos));
  }

  return year_month_day;
}