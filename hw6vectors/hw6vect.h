// Programmer: Dalton Lobosky                   Date: 03/09/2013
// Class: CS53                                  Section: C
// Purpose: to write a program that will read in vector values
//          from the user and then compute several vector calculations.

#ifndef hw6vect_H
#define hw6vect_H

using namespace std;
struct vector    //  a vector structure 
{                //
  float m_xVar;  //  consists of an X
  float m_yVar;  //              a Y and
  float m_zVar;  //             a Z variable
};
      
//Pre: none
//Post: takes in data from user
//Description: this function performs a menu choice that is chosen by user
void choose();
      
//Pre: none
//Post: outputs readable vector to screen
//Description: displays a given input vector
void show_Vect(const vector & VECT);

//Pre: none
//Post: returns a vector object value input by user
//Description: prompts user for vector and returns the vector value
vector get_vect();
     
//Pre: none
//Post: Returns a vector object for the sum
//Description: Takes two vector values and returns the sum as a vector
vector sum_Vect(const vector & VECT1, const vector & VECT2);  

//Pre: none
//Post: Returns a double vector value for magnitude
//Description: Takes a vector and returns magnitude as a double
double mag_Vect(const vector & VECT1);

//Pre: none
//Post: Returns float value for the dot product
//Description: The dot product of two vectors is calculated and returned
float dot_Vect(const vector & VECT1, const vector & VECT2);

//Pre: none
//Post: returns a vector of cross product
//Description: computes cross product of two vectors and returns the value
vector cross_Vect(const vector & VECT1, const vector & VECT2);

//Pre: none
//Post: displays menu for user
//Description: displays a menu with a list of options
void show_menu();
    
#endif
