//Programmers: Jason Beard, Dalton Lobosky, Carl Garrett Herrmann
//Date: 05/07/2013
//File: trash.h                 
//Class: CS 53
//Purpose: trash class header file.


//trash()
//discription:   default trash() constructor  
//preconditions:   None
//postconditions:  creates an instance to get the name of trash


//string getName()
//discription:     returns a name.
//preconditions:   none.
//postconditions:  returns the name of the calling object.  


// int getpotential()
//discription:     returns potential.
//preconditions:   None
//postconditions:  returns the potential of the calling object.  


//void setLocation(const int x, const int y)
//discription:     sets location.
//preconditions:   x and y must be positive.
//postconditions:  sets the locaion of the calling object.  



#ifndef TRASH_H
#define TRASH_H
#include <iostream>
#include "hw9.h"
using namespace std;

class trash
{
  public:
    trash();
    string getname() const;
    int getpotential() const;
    void setLocation(const int x, const int y);
         
  private:
    string name;
    int potential;
    point location;
};

#endif



