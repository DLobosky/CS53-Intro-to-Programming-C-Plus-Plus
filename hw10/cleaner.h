//Programmers: Jason Beard, Dalton Lobosky, Carl Garrett Herrmann
//Date: 05/07/2013
//File: cleaner.h                 
//Class: CS 53
//Purpose: cleaner class header file.

//cleaner(string obj_name, int x_coor = 0, int y_coor = 0)
//discription:     cleaner constructor
//preconditions:   none.
//postconditions:  an instance of a cleaner has been created with a name,
//                 location, and initial stress level of 0.

//void calc_stress(house house1)
//discription:     calculates stress level.
//preconditions:   trash can not be 0.
//postconditions:  sets the stress level of the calling cleaner object.


//string getName()
//discription:     returns a name.
//preconditions:   none.
//postconditions:  returns the name of the calling object.


//void setLocation(const int x, const int y)
//discription:     sets location.
//preconditions:   x and y must be positive.
//postconditions:  sets the locaion of the cleaner object.


//int getStress()
//discription:     returns stress level.
//preconditions:   none.
//postconditions:  returns the stress level of the calling object.


//friend ostream& operator<<(ostream& os, const cleaner& fm)
//discription:     overloaded insertion operator.
//preconditions:   must be passed an ostream on the left and a cleaner
//                 on the right.
//postconditions:  the information about a cleaner will be printed to
//                 the screen.


#ifndef CLEANER_H
#define CLEANER_H

using namespace std;
#include <iostream>
#include "hw9.h"
#include "vacuum.h"
#include "trash.h"  

class house;

class cleaner
{
  public:
    cleaner(string obj_name, int x_coor = 0, int y_coor = 0);
    void calc_stress(house house1, const bool alive[]);
    string getName();
    void setLocation(const int x, const int y);
    int getStress();
    bool getAlive();
    void step(house & h1);
                      
    friend ostream& operator << (ostream& os, const cleaner cl);
                          
  private:
    string name;
    int stress;
    point location;
    vacuum dyson;
    bool alive;
    bool aneurism;
};
#endif
