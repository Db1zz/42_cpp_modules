#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# ifndef PROGRAM_NAME
#  define PROGRAM_NAME "btc"
# endif  // PROGRAM_NAME

/*
  Ideas:
    1. Nested maps or vector to quickly access date and value
      - Efficiont but a bit complicated(ezy)
    2. Comparing everysingle input date and db date
      to find the similar or closest one.
      - For every single date from the input file we have to
        use costly iterations througth the db and perform expesnsive
        atoi operations. Super easy to implement, but extremely stupid(lazy) 
*/

/*
  Input Validator:
  1. Date
  2. Values (0...1000)
  3. Empty lines|files

  DB Validator:
  1. Date
  2. Price(Do we even need to check it?)

  Store values from DB and user input - Nested maps:
  the DB stores: date, price
  input provides: date, value(n = 0...1000)
  Year -> map -> Month -> map -> day -> std::pair<std::string, double>(date, value);
*/

#include <map>
#include <utility>
#include <string>
#include <vector>

typedef typename std::pair<std::string, double> DateData;
typedef typename std::multimap<int, std::multimap<int, std::multimap<int, DateData> > > DateTree;

class BitcoinExchange {
public:


private:
  bool AddValue(DateTree &date_tree, DateData date_data);
  bool RemoveValue(DateTree &date_tree, DateData date_data);
  
  std::vector<int> ExtractDateFromAString(const std::string &date);

  DateTree input_date_tree_;
  DateTree db_date_tree_;
};

#endif  // BITCOIN_EXCHANGE_HPP
