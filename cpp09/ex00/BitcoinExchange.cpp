#include "BitcoinExchange.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

#define YEAR_INDEX 0
#define MONTH_INDEX 5
#define DAY_INDEX 8

DateTreeIt BitcoinExchange::GetDateData(DateTree &date_tree, std::vector<int> date) {
  return GetDateData(date_tree, date, 3);
}

DateTreeIt BitcoinExchange::GetDateData(DateTree &date_tree, std::vector<int> date, int index) {
  DateTreeIt it = date_tree.find(date[index]);
  if (it == date_tree.end()) {
    return it;
  }
  return GetDateData((*it).second, date, index - 1);
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