#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <climits>
#include <limits>
#include <exception>

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(
  const std::string &db_buffer,
  const std::string &buffer_delimeter,
  const std::string &buffer_header)
{
  std::cout << "Default BitcoinExchange constructor called\n";
  if (!parseBuffer(db_buffer, buffer_delimeter, buffer_header, db_dates_)) {
    throw std::runtime_error("Invalid database file format, date or header");
  }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
  std::cout << "BitcoinExchange copy constructor called\n";
  *this = copy;
}

BitcoinExchange::~BitcoinExchange() {
  std::cout << "Default BitcoinExchange destructor called\n";
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
  std::cout << "BitcoinExchange copy operator called\n";

  if (this == &copy) {
    return *this;
  }

  db_dates_ = copy.db_dates_;
  return *this;
}

size_t BitcoinExchange::checkBufferHeader(
  const std::string &buffer, const std::string &buffer_header) {

  if (buffer.empty()) {
    std::cerr << "Error! File is empty" << std::endl;
    return std::string::npos;
  }

  size_t newline_pos = buffer.find('\n');
  if (newline_pos == std::string::npos) {
    std::cerr << "Error! Invalid file format: missing header" << std::endl;
    return std::string::npos;
  }

  std::string header(buffer.begin(), buffer.begin() + newline_pos);
  if (header != buffer_header) {
    std::cout << buffer_header << std::endl;
    std::cerr << "Error! Invalid header: " << header << std::endl;
    return std::string::npos;
  }
  return newline_pos + 1;
}

template <typename Container>
bool BitcoinExchange::parseBuffer(
  const std::string &buffer,
  const std::string &buffer_delimeter,
  const std::string &buffer_header,
  Container &output_container)
{
  Date date;
  size_t newline_pos = 0;
  size_t pos = checkBufferHeader(buffer, buffer_header);
  if (pos == std::string::npos) {
    return false;
  }

  while (pos < buffer.size()) {
    newline_pos = buffer.find('\n', pos);
    if (newline_pos == std::string::npos) {
      newline_pos = buffer.size();
    }
    if (newline_pos - pos > 1) {
      date = extractDate(buffer, pos, newline_pos, buffer_delimeter);

      if (!addDate(output_container, date)) {
        std::cerr << "Error! Invalid date or value in file." << std::endl;
        return false;
      }
    }
    pos = newline_pos + 1;
  }

  return true;
}

template <typename TreeBranch, int MapDepth>
Date BitcoinExchange::getDate(
  TreeBranch &date_tree, const std::vector<int> &date_keys)
{
  typedef typename TreeBranch::mapped_type MappedType;

  typename TreeBranch::iterator branch_it = date_tree.find(date_keys[MapDepth]);
  if (branch_it == date_tree.end()) {
    while (branch_it != date_tree.begin()) {
      --branch_it;
      Date date = 
        getDate<MappedType, MapDepth + 1>(branch_it->second, date_keys);

      if (!date.date_str.empty()) {
        return date;
      }
    }
  }
  return getDate<MappedType, MapDepth + 1>(branch_it->second, date_keys);
}

template <>
Date BitcoinExchange::getDate<Date, 3>(
    Date &date, const std::vector<int> &date_keys)
{
  if (areKeysLessOrEqual(date.date_keys, date_keys)) {
    return date;
  }
  return Date();
}

void BitcoinExchange::exchange(
  const std::string &input_buffer,
  const std::string &buffer_delimeter,
  const std::string &buffer_header)
{
  std::vector<Date> input_dates;
  if (!parseBuffer(input_buffer, buffer_delimeter, buffer_header, input_dates)) {
    return;
  }

  for (size_t i = 0; i < input_dates.size(); i++) {
    Date &input_date = input_dates[i];

    try {
      isDateValidInput(input_date);
      Date date = getDate<DateTree, 0>(db_dates_, input_date.date_keys);
      std::cout << input_date.date_str << " => "
                << input_date.date_value << " = "
                << input_date.date_value * date.date_value <<  std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
      continue;
    }
  }
}

Date BitcoinExchange::extractDate(
  const std::string &d, size_t start, size_t end, const std::string &delim)
{
  size_t pos = 0;
  std::string date_str, value_str;
  std::vector<int> date_keys;
  double date_value;

  if (pos = d.find(delim, start), pos != std::string::npos && pos < end) {
    value_str = std::string(d.begin() + pos + delim.length(), d.begin() + end);
    date_value = atof(value_str.c_str());
    date_str = std::string(d.begin() + start, d.begin() + pos);
    date_keys = extractKeysFromDate(date_str);
    return Date(date_str, value_str, date_keys, date_value);
  }
  date_str = std::string(d.begin() + start, d.begin() + end);
  return Date(date_str, "", std::vector<int>(), 0);
}

std::vector<int> BitcoinExchange::extractKeysFromDate(const std::string &date) {
  std::vector<int> year_month_day;
  size_t pos = 0;

  year_month_day.push_back(atoi(date.c_str()));
  while ((pos = date.find('-', pos)) != std::string::npos) {
    ++pos;
    year_month_day.push_back(atoi(date.c_str() + pos));
  }

  return year_month_day;
}

bool BitcoinExchange::areKeysLessOrEqual(
  const std::vector<int> date_keys1, const std::vector<int> &date_keys2)
{
  if (date_keys1.size() < 3 || date_keys2.size() < 3) {
    return false;
  }

  if (date_keys1[0] < date_keys2[0]) return true;
  if (date_keys1[0] > date_keys2[0]) return false;
  
  if (date_keys1[1] < date_keys2[1]) return true;
  if (date_keys1[1] > date_keys2[1]) return false;

  return date_keys1[2] <= date_keys2[2];
}

void BitcoinExchange::isDateValidInput(const Date &date) {
  if (!validateDate(date.date_str)) {
    throw std::runtime_error("Bad input => " + date.date_str);
  } else if (!utils::isFloat(date.value_str)) {
    throw std::runtime_error("Bad input => " + date.value_str);
  } else if (date.date_value < 0) {
    throw std::runtime_error("Number is not positive");
  } else if (date.date_value > 1000) {
    throw std::runtime_error("Number is too big");
  }
}

bool BitcoinExchange::validateDate(const std::string &date) {
  std::vector<std::string> sd = utils::split(date, "-");
  int year, month, day;
  
  if (sd.size() != 3 || !utils::isFloat(sd[0])
    || !utils::isFloat(sd[1]) || !utils::isFloat(sd[2]))
  {
    return false;
  }

  year = atoi(sd[0].c_str());
  month = atoi(sd[1].c_str());
  day = atoi(sd[2].c_str());

  return (year >= BTC_YEAR && year <= 2025)
      && (month >= 1 && month <= 12)
      && (day >= 1 && day <= 31);
}

bool BitcoinExchange::addDate(DateTree &date_tree, Date &date) {
  if (date.date_str.empty() || !validateDate(date.date_str)
    || date.date_value < 0 || !utils::isFloat(date.value_str))
  {
    return false;
  }

  return addDate<DateTree, 0>(date_tree, date);
}

template<typename TreeBranch, int MapDepth>
bool BitcoinExchange::addDate(TreeBranch &tree, Date &date) {
  typedef typename TreeBranch::mapped_type MappedType;
  typedef typename TreeBranch::iterator BranchIt;

  BranchIt it = tree.find(date.date_keys[MapDepth]);
  if (it != tree.end()) {
    return addDate<MappedType, MapDepth + 1>(it->second, date);
  } else {
    std::pair<BranchIt, bool> ins_it =
      tree.insert(std::make_pair(date.date_keys[MapDepth], MappedType()));
    return addDate<MappedType, MapDepth + 1>(ins_it.first->second, date);
  }
}

template <>
bool BitcoinExchange::addDate<DayMap, 2>(DayMap &day_map, Date &date) {
  DayMap::iterator it = day_map.find(date.date_keys[2]);
  if (it == day_map.end()) {
    day_map.insert(std::make_pair(date.date_keys[2], date));
    return true;
  }
  return false;
}

bool BitcoinExchange::addDate(std::vector<Date> &date_container, Date &date) {
  date_container.push_back(date);
  return true;
}
