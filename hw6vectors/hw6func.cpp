

#include<iostream>
#include<cmath>
#include "hw6vect.h"

using namespace std;

void choose()
{ 
  vector vect_1;
  vector vect_2;
  short choice;
  string reply;
  vector def;
  def.m_xVar = 0, def.m_yVar = 0, def.m_zVar = 0;
  vect_1 = def;
  vect_2 = def;
  bool bool_vect_1 = false;
  bool bool_vect_2 = false;
    
  do
  {
    cout << endl << endl <<"Option: ";
    cin >> choice;
    switch(choice)
    {
      case 1:
        bool retry;
        vect_1 = get_vect();
        bool_vect_1 = true;
        cout << "You entered ";
        show_Vect(vect_1);
        cout << " for vector 1" << endl;
        cout << "Would you like to input a second vector value? (y/n)  ";
        do       
        {        
          cin >> reply;
          if(reply == "y")
          {
            vect_2 = get_vect();
            bool_vect_2 = true;
            cout << "You entered ";
            show_Vect(vect_2);
            cout << " for vector 2" << endl;
            retry = false;
          }
          else if(reply == "n")
            retry = false;
          else
          {   
            cout << "Please enter (y/n)" << endl;
            retry = true;
          }
        }while(retry == true);
        break;
      case 2: 
        if(bool_vect_1 == true && bool_vect_2 == true)
        {     
          cout << "The vector sum is:  ";
          show_Vect(sum_Vect(vect_1, vect_2));
        }
        else
          cout << "Error: vector not entered, enter vector first";
        break;
      case 3: 
        if(bool_vect_1 == true)
          cout << "The magnitude of vector 1 is:  " << mag_Vect(vect_1);
        else
          cout << "ERROR: please enter a value for vector 1" << endl;
        if(bool_vect_2 == true)
          cout << endl << "The magnitude of vector 2 is:  " << mag_Vect(vect_2)
          << endl;
        break;
      case 4: 
        if(bool_vect_1 == true && bool_vect_2 == true)
          cout << "The dot product is:  " << dot_Vect(vect_1, vect_2) << endl;
        else
          cout << "ERROR: enter a value for vector 1 or 2" << endl;
        break;
      case 5: 
        if(bool_vect_1 == true && bool_vect_2 == true)
        {
          cout << "The cross product is:  ";
          show_Vect(cross_Vect(vect_1, vect_2));
        }
        else
          cout << "ERROR: enter a value for vector 1 or 2" << endl;
        break;
      case 6: 
        break;
      default:
        cout << endl << "Please enter a value (1-6)" << endl;
        break;
    }
  }while(choice != 6);
  return;         
}

void show_Vect(const vector & VECT)
{
  cout << "< " << VECT.m_xVar << ", " << VECT.m_yVar << ", " << VECT.m_zVar
  << " >";
}
 
vector get_vect()
{
  vector vect;
  cout << endl << endl << "Enter the vectors:\nX: ";
  cin >> vect.m_xVar;
  cout << "\nY:  ";
  cin >> vect.m_yVar;
  cout << "\nZ:  ";
  cin >> vect.m_zVar;                    
  return vect;
}
 
vector sum_Vect(const vector & VECT1, const vector & VECT2)
{
  vector vectSum;
  vectSum.m_xVar = (VECT1.m_xVar + VECT2.m_xVar);
  vectSum.m_yVar = (VECT1.m_yVar + VECT2.m_yVar);
  vectSum.m_zVar = (VECT1.m_zVar + VECT2.m_zVar);
  return vectSum;
}
 
double mag_Vect(const vector & VECT1)
{
  return (sqrt((VECT1.m_xVar*VECT1.m_xVar)+(VECT1.m_yVar*VECT1.m_yVar)
  + (VECT1.m_zVar*VECT1.m_zVar)));
}
 
float dot_Vect(const vector & VECT1, const vector & VECT2)
{
  return ((VECT1.m_xVar*VECT2.m_xVar) + (VECT1.m_yVar*VECT2.m_yVar)
  + (VECT1.m_zVar*VECT2.m_zVar));
}

vector cross_Vect(const vector & VECT1, const vector & VECT2)
{
  vector cross;
  cross.m_xVar = ((VECT1.m_yVar*VECT2.m_zVar) - (VECT2.m_yVar*VECT1.m_zVar));
  cross.m_yVar = ((VECT1.m_xVar*VECT2.m_zVar) - (VECT2.m_xVar*VECT1.m_zVar));
  cross.m_zVar = ((VECT1.m_xVar*VECT2.m_yVar) - (VECT2.m_xVar*VECT1.m_yVar));
  return cross;
}
 
void show_menu()
{
  cout << endl << endl << "Vector Menu:" << endl << endl;
  cout << "1 - Enter Vectors" << endl;
  cout << "2 - Sum of Vectors" << endl;
  cout << "3 - Magnitude of Vectors" << endl;
  cout << "4 - Dot Product of Vectors" << endl;
  cout << "5 - Cross Product of Vectors" << endl;
  cout << "6 - Quit" << endl << endl;
  return;
}
