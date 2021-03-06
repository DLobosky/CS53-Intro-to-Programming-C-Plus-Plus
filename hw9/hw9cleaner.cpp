// Programmer: Dalton Lobosky                   Date: 04/19/2013
// File: hw9cleaner                             Section: C
//*****************************************************************************


#include "hw9lib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "hw9cleaner.h"

using namespace std;

cleaner::cleaner(const string & name)
{
  set_stress(0);
  set_name(name);
  set_loc(0,0);
}
cleaner::cleaner(const string &name,const int &row, const int &col)
{
  set_stress(0);
  set_name(name);
  set_loc(row, col);
}

string cleaner::get_name()
{
  return m_name;
}

ostream& operator<<(ostream& out, const cleaner & c)
{
  out << "\n" << c.m_name << " is at (" << c.m_location.m_row << ", "
      << c.m_location.m_col << ") and has a stress level of: " << c.m_stress
      << '.' << endl << endl;
  return out;
}

void cleaner::calc_stress(house &h, family_member & f)
{
  m_stress = ((static_cast<float>(scan_house(TRASH,h))/(h.get_row()*h.get_col()))
              * 100 + 2*(scan_house(f.get_name()[0],h)));
  if(m_stress > 100)
  {
    m_stress -= m_stress;
    cout << "Stress level more than 100!" << endl;
  }
  return;
}

short cleaner::scan_house(const char &obj, house &h)
{
  short total = 0;
  for(int i = 0; i < h.get_row(); ++i)
  {
    for(int j = 0; j < h.get_col(); ++j)
    {
      if(h.get_floor(i,j) == obj)
      {
        ++total;
      }
    }
  }
  return total;
}

int cleaner::get_row()
{
  return m_location.m_row;
}

int cleaner::get_col()
{
  return m_location.m_col;
}

void cleaner::set_loc(const unsigned int &row, const unsigned int &col)
{
  m_location.m_row = row;
  m_location.m_col = col;
  return;
}

void cleaner::set_name(const string &name) 
{
  m_name = name;
  return;
}

void cleaner::set_stress(const unsigned int &stress)
{
  if(stress <= 100)
    m_stress = stress;
  else
    exit(3);
  return;
}
