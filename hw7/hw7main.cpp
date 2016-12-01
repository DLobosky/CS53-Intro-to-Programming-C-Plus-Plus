// Programmer: Dalton Lobosky                   Date: 03/18/2013
// File: hw7main.cpp                                  Section: C
// Purpose: 


#include<iostream>
#include "hw7header.h"

using namespace std;

int main()
{
  int option_2, inum1, inum2;
  bool quit = false;
  vector vectSum;
  float fnum1, fnum2;
  
  greeting();
  
  do
  {
    menu_1(quit, vectSum, option_2, fnum1, fnum2, inum1, inum2);
    
  }while(quit == false);
  
  goodbye();
  
  return 0;
}
