// Programmer: Dalton Lobosky                   Date: 03/18/2013
// File: hw7func.cpp                                  Section: C
// Purpose: 


#include<iostream>
#include<cmath>
#include "hw7header.h"

using namespace std;

void greeting()
{
  cout << "\n\nWelcome to your personal calculator!" << endl;

  return;
}

void goodbye()
{
  cout << "\n\nGoodbye!" << endl << endl << endl << endl;

  return;
}

vector get_Vect()
{
  vector vect;
  
  cout << endl << endl << "Enter the vectors \"X, Y, Z\"" << endl;
  cout << "X:";
  cin >> vect.m_xVar;
  
  cout << "Y:";
  cin >> vect.m_yVar;
  
  cout << "Z:";
  cin >> vect.m_zVar;
  
  return vect;

}

void show_Vect(const vector &vectSum)
{
   cout << "< " << vectSum.m_xVar << ", " << vectSum.m_yVar << ", " 
   << vectSum.m_zVar << " >";
}

void menu_1(bool &quit, const vector &vectSum, int &option_2, const float
            &fnum1, const float &fnum2, const int inum1, const int inum2)
{
  int option_1;
  vector vect_1, vect_2;

  

  cout << endl << endl << "Please make a selection: " << endl;
  cout << "\n1: Enter 2 values" << endl;
  cout << "2: Add values" << endl;
  cout << "3: Multiply values" << endl;
  cout << "4: Quit" << endl;
  cin >> option_1;
  
  do
  {
    switch (option_1)
    {
      case 1:
      {
        cout << endl << endl << "Please make another selection: " << endl;
        cout << "\n1: Floating Point Numbers" << endl;
        cout << "2: Integer Numbers" << endl;
        cout << "3: Vectors" << endl;
        cin >> option_2;

        menu_2(option_2, quit, vectSum, fnum1, fnum2, inum1, inum2);
      }
      break;
    
      case 2:
      {
        if (option_2 == 1)
        {
          add(fnum1, fnum2);
        }
        
        else
        {
          cout << "ERROR: No data entered." << endl;
        }
        
        if (option_2 == 2)
        {
          add(inum1, inum2);
        }

        else
        {
          cout << "ERROR: No data entered." << endl;
        }

        if (option_2 == 3)
        {
          add(vect_1, vect_2);
          show_Vect(vectSum);
        }
        
        else
        {
          cout << "ERROR: No data entered." << endl;
        }

      }
      break;
    
      case 3:
      {
         if (option_2 == 1)
        {
          multiply(fnum1, fnum2);
        }

        else
        {
          cout << "ERROR: No data entered." << endl;
        }

        if (option_2 == 2)
        {
          multiply(inum1, inum2);
        }

        else
        {
          cout << "ERROR: No data entered." << endl;
        }

        if (option_2 == 3)
        {
          multiply(vect_1, vect_2);
        }

        else
        {
          cout << "ERROR: No data entered." << endl;
        }

      }
      break;
    
      case 4:
      {
        quit = true;
      }
      break;
    }
  }while(option_1 <= 0 || option_1 > 4);
  
  return;
}

void menu_2(int &option_2, bool &quit, const vector &vectSum, const float
            &fnum1, const float &fnum2, const int inum1, const int inum2)
{
  vector vect_1, vect_2;
  
  do
  {
    switch (option_2)
    {
      case 1:
      {
        cout << "\n\nPlease enter your two floating point numbers." << endl;
      
        cout << "Number 1: " << endl;
        cin >> fnum1;
      
        cout << "Number 2: " << endl;
        cin >> fnum2;
      
        menu_1(quit, vectSum, option_2, fnum1, fnum2, inum1, inum2);
      }
      break;

      case 2:
      {
        cout << "\n\nPlease enter your two integer numbers." << endl;

        cout << "Number 1: " << endl;
        cin >> inum1;

        cout << "Number 2: " << endl;
        cin >> inum2;
        
        menu_1(quit, vectSum, option_2, fnum1, fnum2, inum1, inum2);
      }
      break;

      case 3:
      {
        cout << "\n\nPlease enter your two vectors." << endl;

        cout << "Vector 1: " << endl;
        vect_1 = get_Vect();

        cout << "Vector 2: " << endl;
        vect_2 = get_Vect();
        
        menu_1(quit, vectSum, option_2, fnum1, fnum2, inum1, inum2);
      }
      break;
    }
  }while(option_2 > 0 && option_2 < 4);
  
  return;
}

float multiply(const vector &vect_1, const vector &vect_2)
{
    return ((vect_1.m_xVar*vect_2.m_xVar) + (vect_1.m_yVar*vect_2.m_yVar)
      + (vect_1.m_zVar*vect_2.m_zVar));
}

vector add(const vector &vect_1, const vector &vect_2)
{
  vector vectSum;
 
  vectSum.m_xVar = (vect_1.m_xVar + vect_2.m_xVar);
  vectSum.m_yVar = (vect_1.m_yVar + vect_2.m_yVar);
  vectSum.m_zVar = (vect_1.m_zVar + vect_2.m_zVar);
  
  return vectSum;
}         

