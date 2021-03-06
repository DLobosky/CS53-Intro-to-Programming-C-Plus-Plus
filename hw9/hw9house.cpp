// Programmer: Dalton Lobosky                   Date: 04/19/2013
// File: hw9house.cpp                           Section: C
// Purpose: Function definitions for the house class
//*****************************************************************************

#include "hw9cleaner.h"
#include "hw9familyMember.h"
#include "hw9house.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

house::house(const unsigned int &size_row, const unsigned int &size_col,
             const unsigned int &trash, cleaner &c, family_member & fm)
{
  set_size_row(size_row);
  set_size_col(size_col);
  set_trash(trash);
  make_house();

  put_obj(c.get_row(), c.get_col(), c.get_name()[0]);
  put_obj(fm.get_row(), fm.get_col(), fm.get_name()[0]);
  scatter_trash();
}

ostream& operator<<(ostream& out, const house & h)
{
  out << "\n\n-";
  for(int i = 0; i < h.m_col; ++i)
    out << "----";
  out << endl;
  for(int i = 0; i < h.m_row; ++i)
  {
    for(int j = 0; j < h.m_col; ++j)
    {
      out << "| " << h.m_floor[i][j] << " ";
    }
    out << "|" << endl;
    for(int i = 0; i < h.m_col; ++i)
      out << "----";
    out << "-" << endl;
  }
  return out;
}

void house::set_size_row(const unsigned int &size)

{
  if(size > FLOOR_MAX)
    exit(1);
  m_row = size;
  return;
}

void house::set_size_col(const unsigned int &size)
{
  if(size > FLOOR_MAX)
    exit(2);
  m_col = size;
  return;
}

void house::set_trash(const int &size)
{
  if(size > m_row*m_col)
    exit(3);
  m_trash = size;
  return;
}

void house::make_house()
{
  for(int i = 0; i < m_row; ++i)
  {
    for(int j = 0; j < m_col; ++j)
    {
      m_floor[i][j] = EMPTY;
    }
  }
}

void house::put_obj(const int row, const int col, const char & name)
{
  m_floor[row-1][col-1] = name;
  return;
}

void house::place_obj_random(const char &obj)
{
  short r,c;
  bool done = false;
  do
  {
    r = rand()%m_row;
    c = rand()%m_col;
    if(m_floor[r][c] == EMPTY)
    {
      m_floor[r][c] = obj;
      done = true;
    }
  }while(!done);
}

void house::scatter_trash()
{
  for(int i = 0; i < m_trash; ++i)
    place_obj_random(TRASH);
  return;
}

char house::get_floor(const int i, const int j)
{
  return m_floor[i][j];
}

unsigned short house::get_row()
{
  return m_row;
}

unsigned short house::get_col()
{
  return m_col;
}

unsigned short house::get_trash()
{
  return m_trash;
}
