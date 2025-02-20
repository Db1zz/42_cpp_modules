#include "BitcoinExchange.hpp"
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

std::vector<std::string> split(
  const std::string &str, const std::string &delim)
{
  std::vector<std::string> tokens;
  std::string token;
  size_t pos = 0, delim_pos = 0;

  while ((delim_pos = str.find(delim, pos)) != std::string::npos) {
    token = std::string(str.begin() + pos, str.begin() + delim_pos);
    tokens.push_back(token);
    pos = delim_pos + delim.length();
  }

  tokens.push_back(std::string(str.begin() + pos, str.end()));
  return tokens;
}

bool is_float(const std::string &str) {
  float f;

  std::istringstream iss(str);
  iss >> std::noskipws >> f;
  return iss.eof() && !iss.fail(); 
}

std::string load_file(const std::string &file_name)
{
  std::ifstream fstream(file_name.c_str(), std::ios::ate);

  if (!fstream.is_open()) {
    std::cerr << "Cannot open data base: " << file_name << std::endl;
    return "";
  }

  size_t db_size = fstream.tellg();
  fstream.seekg(0);
  std::string db_buff(db_size, '\0');
  fstream.read(&db_buff[0], db_size);
  fstream.close();
  return db_buff;
}

bool validate_date(const std::string &date) {
  std::vector<std::string> sd = split(date, "-");
  int year, month, day;
  
  if (sd.size() != 3 || !is_float(sd[0]) || !is_float(sd[1]) || !is_float(sd[2])) {
    return false;
  }

  year = atoi(sd[0].c_str());
  month = atoi(sd[1].c_str());
  day = atoi(sd[2].c_str());

  return (year >= BTC_YEAR && year <= 2025)
      && (month >= 1 && month <= 12)
      && (day >= 1 && day <= 31);
}

DateData extract_date_data(
  const std::string &d, size_t start, size_t end, const std::string &delim)
{
  size_t pos = 0;
  std::string key, val_str;
  double value;

  if (pos = d.find(delim, start), pos != std::string::npos && pos < end) {
    key = std::string(d.begin() + start, d.begin() + pos);
    val_str = std::string(d.begin() + pos + delim.length(), d.begin() + end);
    value = atof(val_str.c_str());
    if (is_float(val_str))
      return std::make_pair(key, value);
  }

  return std::make_pair("", -1);
}

std::vector<int> extract_keys_from_date(const std::string &date) {
  std::vector<int> year_month_day;
  size_t pos = 0;

  year_month_day.push_back(atoi(date.c_str()));
  while ((pos = date.find('-', pos)) != std::string::npos) {
    ++pos;
    year_month_day.push_back(atoi(date.c_str() + pos));
  }

  return year_month_day;
}

template <typename Container>
void add_date(Container &container, DateData &date_data) {
  container.push_back(date_data);
}

template <>
void add_date<DateTree>(DateTree &tree, DateData &date_data) {
  std::vector<int> tree_keys = extract_keys_from_date(date_data.first);
  tree[tree_keys[0]][tree_keys[1]][tree_keys[2]] = date_data;
}

template<typename Container>
bool parse_file(
  const std::string &data, const std::string &delim, Container &container)
{

  if (data.empty()) {
    std::cerr << "Error! File is empty" << std::endl;
    return false;
  }

  size_t newline_pos = data.find('\n');
  if (newline_pos == std::string::npos) {
    std::cerr << "Error! Invalid file format: missing header" << std::endl;
    return false;
  }

  std::string header(data.begin(), data.begin() + newline_pos);
  if (header != "date,exchange_rate" && header != "date | value") {
    std::cerr << "Error! Invalid header: " << header << std::endl;
    return false;
  }

  size_t pos = newline_pos + 1;

  while (pos < data.size()) {
    newline_pos = data.find('\n', pos);
    if (newline_pos == std::string::npos) {
      newline_pos = data.size();
    }

    DateData date = extract_date_data(data, pos, newline_pos, delim);
    pos = newline_pos + 1;

    if (date.first.empty() || !validate_date(date.first) || date.second < 0) {
      std::cerr << "Error! Invalid date or value in file." << std::endl;
      return false;
    }
    add_date(container, date);
  }

  return true;
}

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Error! Incorrect amount of arguments given to the program\n"
              << "Try: ./" << PROGRAM_NAME << " input.txt" << std::endl;
    return -1;
  }

  DateTree db_tree;
  std::vector<DateData> input_vector;

  std::string input_file = load_file(std::string(av[1]));
  std::string db_file = load_file("data.csv");
  
  if (!parse_file(input_file, " | ", input_vector)
    || !parse_file(db_file, ",", db_tree))
  {
    std::cerr << "Error! One of the input files is not valid" << std::endl;
    return -1;
  }

  BitcoinExchange btc(db_tree, input_vector);
  btc.Exchange();
  return 0;
} 