// This program has been copied for understanding from: https://developers.google.com/edu/c++/getting-started

// get_input.cpp: Maggie Johnson
// Description: Illustrate the use of cin to get input.

//Update Ex02_01.cpp: Yash Joshi.

#include <iostream>

#include <ios>
#include <limits>

int main() {
  int input_var = 0;

  // Enter the do while loop and stay there until either
  // a non-numeric is entered, or -1 is entered. Note that
  // cin will accept any integer, 4, 40, 400, etc.
  do {
    std::cout << "Enter a number (-1 = quit): ";

    // The following line accepts input from the keyboard into
    // variable input_var.
    // cin returns false if an input operation fails, that is, if
    // something other than an int (the type of input_var) is entered.
    if (!(std::cin >> input_var)) {
      std::cout << "You entered a non-numeric. Please Retry..." << std::endl;
      
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }else if (input_var != -1) {
      std::cout << "You entered " << input_var << std::endl;
    }

  } while (input_var != -1);

  std::cout << "All done." << std::endl;
  return 0;
}
