#include <iostream>
#include <cstring>
#include <cctype>

int main(int argc, char **argv)
{
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  else
  {
    for (int j = 1; j < argc; j++)
    {
      for (size_t i = 0; i < strlen(argv[j]); i++)
      {
        if (argv[j][i] == '\"')
          continue;
        else if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
          std::cout << (char)std::toupper((unsigned char)argv[j][i]);
        else
          std::cout << argv[j][i];
      }
    }
    std::cout << std::endl;
  }
  return 0;
}

