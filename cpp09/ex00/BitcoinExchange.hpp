#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# define PROGRAM_NAME "btc"
# define BTC_MIN 0
# define BTC_MAX 100000

# define BTC_YEAR 2009
# define BTC_MONTH 1
# define BTC_DAY 3

#include <map>
#include <utility>
#include <string>
#include <vector>
#include <exception>

typedef std::pair<std::string, double> DateData;
typedef std::map<int, DateData> DayMap;

template <typename MapKey, typename MapValue, int MapDepth>
struct MapCreator {
  typedef std::map<MapKey, typename MapCreator<MapKey, MapValue, MapDepth - 1>::type> type;
};

template <typename MapKey, typename MapValue>
struct MapCreator<MapKey, MapValue, 0> {
  typedef std::map<MapKey, MapValue> type;
};

typedef MapCreator<int, DateData, 2>::type DateTree;

class BitcoinExchange {
public:
  BitcoinExchange(const std::string &db_file, const std::string &input_file);
  ~BitcoinExchange();

  template <typename TreeBranch, int MapDepth>
  int GetDateData(TreeBranch &date_tree, std::vector<int> date);

  bool AddValue(DateData date_data);

  void DisplayMap();

private:
  template <typename TreeBranch, int MapDepth>
  void PrintValues(TreeBranch &branch);

  template <>
  void PrintValues<DayMap, 0>(DayMap &branch);

  DateTree date_tree_;
  const int date_tree_size_;
};

#endif  // BITCOIN_EXCHANGE_HPP
