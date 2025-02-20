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
  BitcoinExchange(const DateTree &db_tree, const std::vector<DateData> &input);
  ~BitcoinExchange();

  template <typename TreeBranch, int MapDepth>
  double GetDateValue(TreeBranch &date_tree, const std::vector<int> &tree_keys);

  void Exchange();

private:
  class NegativeNumberException : public std::exception {
  public:
    const char *what() const throw();
  };

  class BigNumberException : public std::exception {
    public:
      const char *what() const throw();
  };

  class BadInputException : public std::exception {
    public:
      const char *what() const throw();
  };

  void IsDateDataValidInput(const DateData &date);

  const int input_max_val_;
  DateTree db_tree_;
  std::vector<DateData> input_;
};

#endif  // BITCOIN_EXCHANGE_HPP
