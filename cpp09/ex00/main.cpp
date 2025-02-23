#include "BitcoinExchange.hpp"
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

std::string load_file(const std::string &file_name)
{
  std::ifstream fstream(file_name.c_str(), std::ios::ate);

  if (!fstream.is_open()) {
    std::cerr << "Cannot open data base: " << file_name << std::endl;
    return "";
  }

  size_t buffer_size = fstream.tellg();
  fstream.seekg(0);
  std::string buffer(buffer_size, '\0');
  fstream.read(&buffer[0], buffer_size);
  fstream.close();

  return buffer;
}

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Error! Incorrect amount of arguments given to the program\n"
              << "Try: ./" << PROGRAM_NAME << " input.txt" << std::endl;
    return -1;
  }

  std::string input_buffer = load_file(std::string(av[1]));
  std::string db_buffer = load_file("data.csv");

  BitcoinExchange btc(db_buffer, "," ,"date,exchange_rate");
  btc.exchange(input_buffer, " | ", "date | value");

  return 0;
} 