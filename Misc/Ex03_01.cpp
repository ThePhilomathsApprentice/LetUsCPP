// This program has been copied for understanding from: https://developers.google.com/edu/c++/getting-started

//Update Ex03_01.cpp: Yash Joshi.
//Prints Table of numbers 1 to 9.

#include <iostream>

int main() {

  std::cout << "   1\t2\t3\t4\t5\t6\t7\t8\t9" << std::endl << "" << std::endl;

  for (int c = 1; c < 10; c++) {
    std::cout << c << "| ";
    for (int i = 1; i < 10; i++) {
      std::cout << i * c << '\t';
    }
    std::cout << std::endl;
  }

  return 0;
} 
