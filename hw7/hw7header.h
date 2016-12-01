// Programmer: Dalton Lobosky             Date: 03/18/2013
// File: hw7header.h                                  Section C:
// Purpose: 


#ifndef hw7header_h
#define hw7header_h

using namespace std;
struct vector   
{               
  float m_xVar; 
  float m_yVar; 
  float m_zVar; 
};

template <typename T>
//Pre: none
//Post: 
//Description: 
float add(const T &num1, const T &num2);

template <typename T>
//Pre: none
//Post:
//Description:();
float multiply(const T &num1, const T &num2);

//Pre: none
//Post:
//Description:();
float multiply(const vector &vect_1, const vector &vect_2);

//Pre: none
//Post:
//Description:();
vector add(const vector &vect_1, const vector &vect_2);

//Pre: none
//Post: Outputs a greeting to the user
//Description: Greets the user
void greeting();

//Pre: none
//Post: Outputs a goodbye statement to the user
//Description: Lets the user know the program is over
void goodbye();

//Pre: none
//Post:
//Description:
vector get_Vect();

//Pre: none
//Post:
//Description:
void menu_1(bool &quit, const vector &vectSum, int &option_2,const float
           &fnum1, const float &fnum2, const int &inum1, const int &inum1);

//Pre: none
//Post:
//Description:
void menu_2(int &option_2, bool &quit, const vector &vectSum, const float
            &fnum1, const float &fnum2, const int inum1, const int inum2);

//Pre: none
//Post:
//Description:
void show_Vect(const vector &vectSum);

#include "hw7func.hpp"

#endif
