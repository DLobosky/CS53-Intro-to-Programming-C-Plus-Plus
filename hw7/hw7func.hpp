// Programmer: Dalton Lobosky             Date: 03/18/2013
// File: hw7func.hpp                      Section C:
// Purpose:

#include "hw7header.h"

using namespace std;

template <typename T>
float add(const T &num1, const T &num2)
{
  float sum;

  sum = num1 + num2;

  cout << "\n\nYour sum is: " << sum << endl;
 
  return sum;
}

template <typename T>
float multiply(const T &num1, const T &num2)
{
  float prod;
  
  prod = num1 * num2;

  cout << "\n\nYour product is: " << prod << endl;

  return prod;
}

