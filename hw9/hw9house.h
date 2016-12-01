// Programmer: Dalton Lobosky                   Date: 04/19/2013
// File: hw9house.h                             Section: C
// Purpose: Function prototypes for the house class
//*****************************************************************************


#ifndef hw9house_h
#define hw9house_h
#include "hw9lib.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


class cleaner;
class family_member;

const unsigned short FLOOR_MAX = 25;
const char EMPTY = ' ';
const char TRASH = 't';


class house
{
  public:
    //Pre:
    //Post: 
    //Description: 
    house(const unsigned int &size_row, const unsigned int &size_col,
          const unsigned int &trash, cleaner &c, family_member & fm);
    //Pre:
    //Post: this sets the value of m_row
    //Description: this sets the value of m_row
    void set_size_row(const unsigned int &size);
    
    //Pre:
    //Post: this sets the value of m_col
    //Description: this sets the value of m_col
    void set_size_col(const unsigned int &size);
    
    //Pre:
    //Post: this sets the value of m_trash
    //Description: this sets the value of m_trash
    void set_trash(const int &size);
    
    char get_floor(const int i, const int j);

    //Pre:
    //Post: this returns the value of m_row
    //Description: this returns the value of m_row
    unsigned short get_row();

    //Pre:
    //Post: this returns the value of m_col
    //Description: this returns the value of m_col
    unsigned short get_col();

    //Pre:
    //Post: this returns the value of m_trash
    //Description: this returns the value of m_trash
    unsigned short get_trash();

    //Pre:
    //Post: this outputs a house in a readable format
    //Description: this outputs a house in a readable format
    friend ostream& operator<<(ostream& out, const house& h);

  private:
    char m_floor[FLOOR_MAX][FLOOR_MAX];
    unsigned short m_row;
    unsigned short m_col;
    unsigned short m_trash;
    
    //Pre: row and col must be less than or equal to m_row and m_col 
    //     respectively and both must be greater than zero
    //Post: places an object in a certain location of the house
    //Description: places an object in a certain location of the house
    void put_obj(const int row, const int col, const char & name);

    //Pre:
    //Post: randomly places trash in a house
    //Description: randomly places trash
    void scatter_trash();

    //Pre:
    //Post: this fills a 2D array (m_floor) with blanks
    //Description: m_floor is filled with blanks
    void make_house();

    //Pre: 
    //Post: puts an object randomly into m_floor
    //Description: puts an object randomly into m_floor
    void place_obj_random(const char &obj);
};
#endif
