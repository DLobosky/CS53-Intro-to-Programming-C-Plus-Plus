// Programmer: Dalton Lobosky                   Date: 04/19/2013
// File: hw9cleaner.cpp                                  Section: C
// Purpose: Function prototypes for the cleaner class
//*****************************************************************************


#ifndef hw9cleaner_h
#define hw9cleaner_h
#include <iostream>
#include <fstream>
#include <string>
#include "hw9lib.h"


using namespace std;

class house;
class cleaner
{
  public:
    
    //Pre:
    //Post: this sets set_stress and location to zero/(0,0) and sets the name
    //Description: this sets set_stress and
    //             location to zero/(0,0) and sets the name
    cleaner(const string & name);
    
    //Pre: row and column must be less than 25 and greater or equal to zero
    //Post: sets name, row, and column of a cleaner and sets m_stress to zero
    //Description: sets name, row, and column of a cleaner and sets m_stress to 0
    cleaner(const string &name, const int &row, const int &col);
    
    //Pre:
    //Post: this returns the value of m_name
    //Description: this returns the value of m_name
    string get_name();

    //Pre:
    //Post: this returns the value of m_row
    //Description: this returns the value of m_row
    int get_row();

    //Pre:
    //Post: this returns the value of m_col
    //Description: this returns the value of m_col
    int get_col();
    
    //Pre: 
    //Post: sets m_stress to a calculated value
    //Description:calculates value of m_stress based on house and family member
    void calc_stress(house &h, family_member & f);
    
    //Pre: row and col must be less than 25
    //Post: this returns the value of m_row
    //Description: this returns the value of m_row
    void set_loc(const unsigned int &row, const unsigned int &col);
    
    //Pre: 
    //Post: this returns the value of m_row
    //Description: this returns the value of m_row
    void set_name(const string &name);
    
    //Pre: stress must be less than 100
    //Post: this returns the value of m_row
    //Description: this returns the value of m_row
    void set_stress(const unsigned int &stress);

    //Pre:
    //Post: this outputs a cleaner in a readable way
    //Description: shows user the cleaner attributes
    friend ostream& operator<<(ostream& out, const cleaner & c);

  private:
    string m_name;
    unsigned short m_stress;
    coordinate m_location;

    //Pre:
    //Post: this returns the number of obj found
    //Description: scans every square of house and returns the number of
    //             objs found there
    short scan_house(const char &obj, house &h);
};

#endif
