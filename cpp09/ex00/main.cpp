#include "BitcoinExchange.hpp"
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <fstream>

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

bool is_number(const std::string &str) {
  std::string::const_iterator it = str.begin();

  while (it != str.end() && std::isdigit(*it)) {
    ++it;
  }

  return !str.empty() && it == str.end();
}

std::string load_file(const std::string &file_name, const std::string &delim)
{
  std::ifstream fstream(file_name.c_str(), std::ios::ate);

  if (!fstream.is_open()) {
    std::cout << "Cannot open data base" << std::endl;
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
  
  if (sd.size() != 3 || !is_number(sd[0]) || !is_number(sd[1]) || !is_number(sd[2])) {
    return false;
  }

  year = atoi(sd[0].c_str());
  month = atoi(sd[1].c_str());
  day = atoi(sd[2].c_str());

  return (year < BTC_YEAR && year <= 2025)
      && (month >= 1 && month <= 12)
      && (day >= 1 && day <= 31);
}

DateData extract_date_data(
  const std::string &d, size_t start, size_t end, const std::string &delim)
{
  size_t pos = 0;

  if (pos = d.find(delim, start), pos != std::string::npos) {
    std::string key(d.begin() + start, d.begin() + pos);
    double value = atof(std::string(d.begin() + pos, d.begin() + end).c_str());
    return std::make_pair(key, value);
  }
  return std::make_pair("", 0);
}

bool validate_file(
  const std::string &data, const std::string &delim, double val_max)
{
  if (data.empty()) {
    std::cout << "Error! file is empty" << std::endl;
    return false;
  }
  
  size_t pos = 0, pos_delim = 0;

  while (true) {
    if (pos_delim = data.find('\n', pos), pos_delim == std::string::npos) {
      pos_delim = data.end() - data.begin();
    }

    DateData date = extract_date_data(data, pos, pos_delim, delim);
    pos = pos_delim + delim.length();

    if (date.first == "date") {
      continue;
    } else if (date.first.empty() || !validate_date(date.first)
      || (date.second < 0 || date.second > val_max))
    {
      return false;
    }
  }
}

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Error! Incorrect amount of arguments given to the program.\n"
              << "Try: ./" << PROGRAM_NAME << " input.txt" << std::endl;
  }

  std::string input_file = load_file(std::string(av[1]), "|");
  std::string db_file = load_file("data.csv", ",");
  
  if (!validate_file(input_file, " | ", 1000)
    || !validate_file(db_file, ",", 100000))
  {
    return -1;
  }

  BitcoinExchange btc(db_file, input_file);
  return 0;
} 