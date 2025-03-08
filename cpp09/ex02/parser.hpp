#ifndef PARSER_HPP
# define PARSER_HPP

#include "Error.hpp"
#include <vector>

void parse_input(const char **num_str_array, int size, std::vector<int> &result);
void display_error(const Error &e);

#endif  // PARSER_HPP