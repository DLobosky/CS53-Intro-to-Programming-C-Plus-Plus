// Programmer: Dalton Lobosky                   Date: 04/19/2013
// File: hw9familyMember.h                                Section: C
// Purpose: Function definitions for the family_memeber class
//*****************************************************************************


#ifndef hw9familyMember_h
#define hw9familyMember_h
#include <fstream>
#include <string>
#include <iostream>
#include "hw9house.h"
#include "hw9lib.h"
using namespace std;

class family_member
{
  public:
    //Pre: 
    //Post: sets location to 0,0 and name and slop are set from file
    //Description: sets family_member variables when declared
    family_member();

    //Pre: 
    //Post: this returns the value of m_row
    //Description: this returns the value of m_row
    unsigned short get_row();

    //Pre:
    //Post: this returns the value of m_col
    //Description:this returns the value of m_col
    unsigned short get_col();

    //Pre:
    //Post: this returns the value of m_name
    //Description:this returns the value of m_name
    string get_name();

    //Pre: row must be less than 25 and greater than zero
    //Post: sets m_row to row parameter
    //Description:sets m_row to row parameter
    void set_row(const int row);

    //Pre:col must be less than 25 and greater than zero
    //Post:sets m_row to row parameter
    //Description:sets m_row to row parameter
    void set_col(const int col);

    //Pre: 
    //Post: outputs the info from family_member to readable format
    //Description: outputs the info from family_member to readable format
    friend ostream& operator<<(ostream& out, const family_member &fm);
  
  private:
    string m_name;
    unsigned short m_slop;
    unsigned short m_row;
    unsigned short m_col;
};

#endif
