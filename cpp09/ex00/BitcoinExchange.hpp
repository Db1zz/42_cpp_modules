#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# define PROGRAM_NAME "btc"
# define BTC_MIN 0
# define BTC_MAX 100000

# define BTC_YEAR 2009
# define BTC_MONTH 1
# define BTC_DAY 3

# include "date_map.hpp"
# include "MyCoolArray.hpp"

# include <utility>
# include <string>
# include <vector>

class BitcoinExchange {
  public:
  BitcoinExchange();
  BitcoinExchange(
    const std::string &db_buffer,
    const std::string &buffer_delimeter,
    const std::string &buffer_header);
  BitcoinExchange(const BitcoinExchange &copy);
  ~BitcoinExchange();
  BitcoinExchange &operator=(const BitcoinExchange &copy);

  void exchange(
    const std::string &input_buffer,
    const std::string &buffer_delimeter,
    const std::string &buffer_header);

private:
  size_t checkBufferHeader(
    const std::string &buffer, const std::string &buffer_header);

  template <typename Container>
  bool parseBuffer(
    const std::string &buffer,
    const std::string &buffer_delimeter,
    const std::string &buffer_header,
    Container &output_container);

  Date extractDate(
    const std::string &d, size_t start, size_t end, const std::string &delim);

  std::vector<int> extractKeysFromDate(const std::string &date);

  bool areKeysLessOrEqual(
    const std::vector<int> date_keys1, const std::vector<int> &date_keys2);

  void isDateValidInput(const Date &date);

  bool validateDate(const std::string &date);

  bool addDate(std::vector<Date> &date_container, Date &date);

  bool addDate(DateTree &date_tree, Date &date);

  template<typename TreeBranch, int MapDepth>
  bool addDate(TreeBranch &date_tree, Date &date);

  template <typename TreeBranch, int MapDepth>
  Date getDate(TreeBranch &date_tree, const std::vector<int> &date_keys);

  DateTree db_dates_;
};

#endif  // BITCOIN_EXCHANGE_HPP
