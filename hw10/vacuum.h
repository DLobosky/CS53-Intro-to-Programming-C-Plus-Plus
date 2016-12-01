//Programmers: Jason Beard, Dalton Lobosky, Carl Garrett Herrmann
//Date: 05/07/2013
//File: vacuum.h                 
//Class: CS 53
//Purpose: vacuum class header file.


//vacuum()
//discription:     Default vacuum constructor
//preconditions:   None
//postconditions:  sets default values for tinbag, exploded, and shorted


//void vac(trash t1)
//discription:     Determoines what happens to the bag based on certain 
//                 conditions
//preconditions:   None
//postconditions:  Sets exploded or shorted to true as needed


//void empty()
//discription:     Outputs which trash items were put into the trashcan
//preconditions:   None
//postconditions:  couts each name of the piece trash int the trashcan


//bool isExploded()
//discription:     returns whether or not the bag exploded
//preconditions:   none.
//postconditions:  returns whether the variable exploded is true or false


//bool isSparky()
//discription:     returns whether or not the vacuum shorted
//preconditions:   none.
//postconditions:  returns whether the variable shorted is true or false

#ifndef VACUUM_H
#define VACUUM_H

using namespace std;
#include <iostream>
#include "hw9.h"
#include "trash.h"

const int bag_size = 35;

class vacuum
{  
  public:
    vacuum();
    void vac(trash t1);  
    void empty();
    bool isExploded();
    bool isSparky();
    
  private:
    trash bag[bag_size];
    int tinbag;
    bool shorted;
    bool exploded;
};

#endif
