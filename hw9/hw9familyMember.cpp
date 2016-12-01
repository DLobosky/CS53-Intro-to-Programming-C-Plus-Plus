// Programmer: Dalton Lobosky                   Date: 04/19/2013
// File: hw9familyMember.cpp                    Section: C
// Purpose: Function definitions for the house class
//*****************************************************************************


#include "hw9familyMember.h"
#include <fstream>
#include <string>

using namespace std;

family_member::family_member()
{
  ifstream fin;
  fin.open("family.dat");
  if(fin.is_open())
  { 
    for(int i = 0; i <= rand()%4; ++i)
      fin >> m_name >> m_slop;
  }
  else if(m_slop > 100)
    exit(4);
  else
    cout << "That file can't be opened" << endl;
  cout << m_name << m_slop;
  set_row(0);
  set_col(0);
}

string family_member::get_name()
{
  return m_name;
}

unsigned short family_member::get_row()
{
  return m_row;
}

unsigned short family_member::get_col()
{ cout << m_col;
  return m_col;
}

void family_member::set_row(const int row)
{
  m_row = row;
  return;
}

void family_member::set_col(const int col)
{
  m_col = col;
  return;
}

ostream &operator<<(ostream& out, const family_member &fm)
{
  out << fm.m_name << " is at (" << fm.m_row << ", " 
      << fm.m_col << ") and has a slopiness level of: " << fm.m_slop << endl;
  return out;
}
