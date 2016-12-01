//Programmers: Jason Beard, Dalton Lobosky, Carl Garrett Herrmann
//Date: 05/07/2013
//File: house.h                 
//Class: CS 53
//Purpose: header file for house class.

//house(int house_size, short trash_num, cleaner & house_cleaner,
//      family_member & fam)
//discripton:      house constructor.
//preconditions:   none.
//postconditions:  an instance of a house has been created with deminsions
//                 and a number of pieces of trahs on the ground.

//friend ostream& operator<<(ostream& os, const house& fm)
//discription:     overloaded insertion operator.
//preconditions:   must be passed an ostream on the left and a house
//                 on the right.
//postconditions:  the information about a house will be printed to
//                 the screen.


//int getSize()
//discripton:      returns a size.
//preconditions:   none.
//postconditions:  returns the size of the calling object.


//char getFloorSpace(const int x, const int y)
//discripton:      returns what is on the floor at (x,y).
//preconditions:   x and y must be positive.
//postconditions:  returns the char at [x][y] in a house array.


//void trash_dec()
//discription:     Decreases trash by 1
//preconditions:   none
//postconditions:  Decrements the value of trash by 1


//void trash_add()
//discription:     Increases trash by 1
//preconditions:   None
//postconditions:  Increments the value of trash by 1 


//int getTrash()
//discription:     returns how much trash there is
//preconditions:   None
//postconditions:  returns the value of trash


//void setFloorSpace(const int x, const int y, const char n)
//discription:     Sets the size of the floor space
//preconditions:   None
//postconditions:  Sets the 2D array to n


#ifndef HOUSE_H
#define HOUSE_H
#include "cleaner.h"
#include "family_member.h"

using namespace std;

const int floor_size = 25;

class family_member;

class house
{
  public:
    house(int house_size, short trash_num, cleaner & house_cleaner,
          family_member fam[], int fam_num);
    friend ostream& operator<<(ostream& os, const house& h);
    int getSize();
    char getFloorSpace(const int x, const int y);
    void trash_dec();
    void trash_add();
    int getTrash();
    void setFloorSpace(const int x, const int y, const char n);        
            
  private:
    void scatter_trash();
                
    char floor[floor_size][floor_size];
    unsigned short size;
    unsigned short trash;
};
                        
#endif
