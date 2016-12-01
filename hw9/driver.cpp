// Programmer: Dalton Lobosky                   Date: 04/19/2013
// File: driver.cpp                                  Section: C
// Purpose: To drive and iniciate the whole program
//*****************************************************************************


#include "hw9lib.h"
#include <ctime>
#include "hw9familyMember.h"
#include "hw9cleaner.h"
#include "hw9house.h"
#include <iostream>
using namespace std;

int main()
{
  srand(time(NULL));

  family_member Bart;
  Bart.set_row(2);
  Bart.set_col(7);
  cleaner Marge("Marge",7,7);
  house the_simpsons(11,8,40, Marge, Bart);
  Marge.calc_stress(the_simpsons, Bart);
  cout << the_simpsons << endl << Marge << endl << Bart << endl << endl;
  return 0;
}
