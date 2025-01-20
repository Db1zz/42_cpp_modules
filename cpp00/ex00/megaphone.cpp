#include <iostream>
#include <string>

void print_capital_char_matrix(char **to_print)
{
  for (int i = 0; to_print[i]; i++) {
    std::string string = to_print[i];
    for (int j = 0; string[j]; j++) {
      std::cout << static_cast<char>(std::toupper(string[j]));
    }
  }
}

int main(int ac, char **av)
{
  if (ac == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else
    print_capital_char_matrix(av + 1);
  std::cout << std::endl;
  return (0);
}
