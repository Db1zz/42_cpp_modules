#include "BitcoinExchange.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>

BitcoinExchange::BitcoinExchange(const std::string &db_file, const std::string &input_file)
  : date_tree_size_(3)
{
  std::cout << "Default BitcoinExchange constructor called\n";
}

BitcoinExchange::~BitcoinExchange() {
  std::cout << "Default BitcoinExchange destructor called\n";
}

template <typename TreeBranch, int MapDepth>
int BitcoinExchange::GetDateData(TreeBranch &date_tree, std::vector<int> date) 
{
  typedef typename TreeBranch::mapped_type MappedType;

  typename TreeBranch::iterator branch_it = date_tree.find(date[MapDepth]);
  if (branch_it == date_tree.end()) {
    return INT_MIN;
  } else if (MapDepth == 0) {
    return branch_it.second.second;
  }
  return GetDateData<MappedType, MapDepth + 1>(branch_it->second, date);
}

bool BitcoinExchange::AddValue(DateData date_data) {
  std::vector<int> dates = ExtractDateFromAString(date_data.first);

  if (!Validate(date_data.first)
    || (date_data.second < 0 || date_data.second > 100000))
  {
    date_tree_[dates[0]][dates[1]][dates[2]] = date_data;
    return true;
  }
  return false;
}

template <typename TreeBranch, int MapDepth>
void BitcoinExchange::PrintValues(TreeBranch &branch) {
  for (size_t i = 0; i < branch.size(); i++) {
    PrintValues<typename TreeBranch::mapped_type, MapDepth - 1>(branch[i]);
  }
}

template <>
void BitcoinExchange::PrintValues<DayMap, 0>(DayMap &branch) {
  // DayMap::const_iterator it = branch.find(4);
  // std::cout << branch[i].first << std::endl;
  // std::cout << it->first << std::endl;
}

void BitcoinExchange::DisplayMap() {
  PrintValues<DateTree, 2>(date_tree_);
}
