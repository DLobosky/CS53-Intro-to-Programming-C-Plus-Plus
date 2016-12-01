//Programmers: Jason Beard, Dalton Lobosky, Carl Garrett Herrmann
//Date: 05/07/2013
//File:  trash.cpp                 
//Class: CS 53
//Purpose: class definition for trash object.

#include "trash.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

trash::trash()
{
  ifstream in;
  in.open("trash.txt");
  
  int val = rand() % 30;
  
  for(int i = 0; i <= val; i++)
  {
    in >> potential;
    
    // read past spaces!!!!!!!!!!!!!!!       
    getline(in,name);
  }
  
  in.close();
}
string  trash::getname() const
{
  return name;
}

int trash::getpotential() const
{
  return potential;
}

void trash::setLocation(const int x, const int y)
{
  location.x = x;
  location.y = y;
  
  return;
}
