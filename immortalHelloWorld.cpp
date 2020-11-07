// This program has been copied for understanding from: https://developers.google.com/edu/c++/getting-started

// hello2.cpp: Maggie Johnson
// Description: a program that prints the immortal saying "hello world"
// many times

#include <iostream>
// we need the following include for setw() in some c++ implementations
#include <iomanip>
using namespace std;

int main() {
  // the first for-loop will handle the rows
  for (int i = 0; i < 6; i++) {
    // the second for loop will handle the columns
    for (int j = 0;  j < 4 ; j++)
      // setw(int) sets the column width
      cout << setw(17) << "Hello World!";
    // this  next line is a part of the first for loop
    // and causes the new line
    cout << endl;
  }
  return 0;
}
