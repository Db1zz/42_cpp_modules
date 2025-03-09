#ifndef PARSER_HPP
# define PARSER_HPP

#include "ParserError.hpp"

#include <vector>

void parse_input(const char **num_str_array, int size, std::vector<int> &result);

#endif  // PARSER_HPP