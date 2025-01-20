#include <iostream>
#include <stdlib.h>
#include <fstream>

/*
  aaareplaceaaaaaaaasdfsdfgsdrrrrreplacefdjkjdfjlkj
*/
bool read_file(const std::string& filename, std::string& out) {
  std::ifstream in_stream(filename, std::ifstream::ate);
  if (!in_stream.is_open()) {
    std::cout << "Error! Failed to open a file." << std::endl;
    return false;
  }

  size_t file_size = in_stream.tellg();
  out = std::string(file_size, '\0');
  in_stream.seekg(0);
  if (!in_stream.read(&out[0], file_size)) {
    std::cout << "Error! Cannot read from a file\n" << std::endl;
    return false;
  }
  return true;
}

int main(int ac, char** av) {
  if (ac != 4) {
    std::cout << "Error! Incorrect amount of arguments.\n"
              << "Usage: [Filename, to_replace, replace_with]" << std::endl;
    return EXIT_FAILURE;
  }
  std::string to_replace(av[2]);
  std::string replace_with(av[3]);
  std::string in_filename(av[1]);
  std::string out_filename(in_filename + ".replace");
  std::ofstream out_stream(out_filename);
  std::string file_data;

  if (!read_file(in_filename, file_data)) {
    return EXIT_FAILURE;
  }
  for(size_t i = 0; i < file_data.size();) {
    size_t replace_index = file_data.find(to_replace, i);
    if (replace_index == std::string::npos) {
      out_stream.write(file_data.c_str() + i, file_data.size() - i);
      break ;
    }
    out_stream.write(file_data.c_str() + i, replace_index - i);
    out_stream.write(replace_with.c_str(), replace_with.size());
    i = replace_index + to_replace.length();
  }
  out_stream.close();
  return EXIT_SUCCESS;
}
