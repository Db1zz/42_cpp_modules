#include "RPN.hpp"
#include <stack>
#include <cctype>
#include <cstdlib>
#include <iostream>

const char *RPN::InvalidInputException::what() const throw() {
  return "Invalid input";
}

bool RPN::IsOperator(char c) {
  return c == '-' || c == '/' || c == '+' || c == '*';
}

char RPN::GetToken(StrCIt &it) {
  char token;

  token = *it;
  ++it;
  if (*it != ' ' && *it != 0) {
    throw InvalidInputException();
  }
  ++it;
  return token;
}

int RPN::PerformOperation(int left, int right, char op) {
  if (op == '-') {
    return left - right;
  } else if (op == '/') {
    return left / right;
  } else if (op == '+') {
    return left + right;
  } else if (op == '*') {
    return left * right;
  }
  return 0;
}

/*
  Negative numbers are not explicitly stated in the subject, so I think I don't need to
  handle them, only numbers in range n >= 0 and n <= 9. (I'll ask comrades in slack to clarify this xdd)
*/

int RPN::Solve(const std::string &expression) {
  if (expression.empty()) {
    throw InvalidInputException();
  }

  std::stack<int> values;
  StrCIt it = expression.begin();
  int expression_result = 0;

  while (it != expression.end()) {
    char token = GetToken(it);

    if (values.size() >= 2 && values.size() <= 3 && IsOperator(token)) {
      int right = values.top(); values.pop();
      int left = values.top(); values.pop();
      values.push(PerformOperation(left, right, token));
    } else if (values.size() < 3 && isdigit(token)) {
      values.push(static_cast<int>(token - '0'));
    } else if (token == 0) {
      break;
    } else {
      throw InvalidInputException();
    }
  }
  expression_result = values.top();
  return expression_result;
}