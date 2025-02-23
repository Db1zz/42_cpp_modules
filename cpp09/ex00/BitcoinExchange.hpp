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

struct Date {
  std::string date_str;
  std::vector<int> date_keys;
  double date_value;

  Date(const std::string &date_str,
          const std::vector<int> &date_keys, double date_value)
    : date_str(date_str), date_keys(date_keys), date_value(date_value) {};
  Date() : date_str(""), date_keys(), date_value(0) {};
};

typedef std::map<int, Date> DayMap;

template <typename MapKey, typename MapValue, int MapDepth>
struct MapCreator {
  typedef std::map<MapKey, typename MapCreator<MapKey, MapValue, MapDepth - 1>::type> type;
};

template <typename MapKey, typename MapValue>
struct MapCreator<MapKey, MapValue, 0> {
  typedef std::map<MapKey, MapValue> type;
};

typedef MapCreator<int, Date, 2>::type DateTree;

class BitcoinExchange {
  public:
  BitcoinExchange(const DateTree &db_tree, const std::vector<Date> &input);
  ~BitcoinExchange();

  template <typename TreeBranch, int MapDepth>
  Date GetDate(TreeBranch &date_tree, const std::vector<int> &date_keys);

  void Exchange();

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

private:
  bool AreKeysLessOrEqual(
    const std::vector<int> date_keys1, const std::vector<int> &date_keys2);

  void IsDateValidInput(const Date &date);

  const int input_max_val_;
  DateTree db_tree_;
  std::vector<Date> input_;
};

#endif  // BITCOIN_EXCHANGE_HPP
