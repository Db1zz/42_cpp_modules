#include <iostream>

void	print_capital_char_matrix(char **to_print)
{
	for (int i = 0; to_print[i]; i++) {
		for (int j = 0; to_print[i][j]; j++) {
				std::cout << (char)std::toupper(to_print[i][j]);
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		print_capital_char_matrix(av + 1);
	std::cout << std::endl;
	return (0);
}
