//Programmers: Jason Beard, Dalton Lobosky, Carl Garrett Herrmann
//Date: 05/07/2013
//File: family_member.h                 
//Class: CS 53
//Purpose: header file for family_member class.

//family_member()
//discription:     default family_member constructor.
//preconditions:   none.
//postconditions:  an instance of a family_member is created with a name, 
//                 location, and sloppiness factor.

//friend ostream& operator<<(ostream& os, const family_member& fm)
//discription:     overloaded insertion operator.
//preconditions:   must be passed an ostream on the left and a family
//                 member on the right.
//postconditions:  the information about a family member will be printed to 
//                 the screen.


//string getName()
//discription:     returns a name.
//preconditions:   none.
//postconditions:  returns the name of the calling object.


//void setLocation(const int x, const int y)
//discription:     sets location.
//preconditions:   x and y must be positive.
//postconditions:  sets the locaion of the calling object.


//void step(house & h1)
//discription:     Moves person 1 unit if possible
//preconditions:   None
//postconditions:  increments movement my 1 unit


//bool drop_trash(house & h1)
//discription:     drops a piece of trash at random
//preconditions:   None
//postconditions:  returns true or false for drop


//bool getAlive()
//discription:     returns whether or not alive
//preconditions:   None
//postconditions:  returns true or false for alive

#ifndef FAMILY_MEMBER_H
#define FAMILY_MEMBER_H

using namespace std;
#include <iostream>
#include "hw9.h"
#include "house.h"
#include "cleaner.h"
#include "trash.h"
#include "vacuum.h"

class house;
class cleaner;
class trash;
class vacuum;


class family_member
{
  public:
    family_member();
    friend ostream& operator<<(ostream& os, const family_member fm[]);
    string getName();
    void setLocation(const int x, const int y);
    void step(house & h1);
    bool drop_trash(house & h1);
    bool getAlive();
	
    static int next_fm;
              
  private:
    string name;
    int sloppiness_factor;
    point location;
    bool alive;
///    static int next_fm;
};
                    
#endif
