#include "Array.hpp"

#define MAX_VAL 750
int main(int, char **)
{
  // subject test
  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++)
  {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++)
  {
    if (mirror[i] != numbers[i])
    {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try
  {
    numbers[-2] = 0;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
  try
  {
    numbers[MAX_VAL] = 0;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++)
  {
    numbers[i] = rand();
  }
  delete[] mirror;

  // additional test for char
  // numbers.printArray();
  // {
  //   srand(time(NULL));
  //   Array<char> chars(MAX_VAL);
  //   char *mirror = new char[MAX_VAL];
  //   srand(time(NULL));
  //   for (int i = 0; i < MAX_VAL; i++)
  //   {
  //     // const char value = rand() % 26 + 97;
  //     const char value = "abcdefghijklmnopqrstuvwxyz"[rand() % 26];
  //     chars[i] = value;
  //     mirror[i] = value;
  //   }

  //   for (int i = 0; i < MAX_VAL; i++)
  //   {
  //     if (mirror[i] != chars[i])
  //     {
  //       std::cerr << "didn't save the same value!!" << std::endl;
  //       return 1;
  //     }
  //   }

  //   chars.printArray();
  //   delete[] mirror;
  // }
}