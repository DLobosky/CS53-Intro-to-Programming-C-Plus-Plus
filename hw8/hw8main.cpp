// Programmer: Dalton Lobosky                   Date: 04/10/2013
// File: hw8main.cpp                                  Section: C
// Purpose: The file drives the hw8func.cpp file
//
// File: hw8main.cpp
//*****************************************************************************


#include<iostream>
#include<string>
#include<cctype>
#include "hw8header.h"

using namespace std;

int main()
{
 int choice = 0;
  do
  {
  
    menu();
    cin >> choice;
      
      switch(choice)
    {
      case 1:
        english_l33t();
        break;
        
      case 2:
        l33t_english();
        break;
      
      case 3:
        cout << "Have a good day.";
        break;
    }
  }
  while(choice != 3);
  return 0;
}
