#ifndef DATE_MAP_HPP
# define DATE_MAP_HPP

# include "MyCoolArray.hpp"

# include <map>
# include <string>

struct Date {
  std::string date_str;
  std::string value_str;
  MyCoolArray<int> date_keys;
  double date_value;

  Date(const std::string &date_str, const std::string &value_str,
          const MyCoolArray<int> &date_keys, double date_value)
      : date_str(date_str), value_str(value_str), date_keys(date_keys), date_value(date_value) {};
  Date() : date_str(""), value_str(""), date_keys(), date_value(0) {};
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

#endif  // DATE_MAP_HPP