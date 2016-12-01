//Programmers: Jason Beard, Dalton Lobosky, Carl Garrett Herrmann
//Date: 05/07/2013
//File:  vacuum.cpp                 
//Class: CS 53
//Purpose: class definition for vacuum object.


#include "vacuum.h"
#include <cstdlib>
#include <ctime>

vacuum::vacuum()
{
  tinbag = 0;
  exploded = false;
  shorted = false;
}

void vacuum::vac(trash t1)
{
  //static int vac_num = 0;
  
  bag[tinbag] = t1;
  
  tinbag++;
  
  //vac_num++;
  
  if(tinbag > bag_size)
  {
    exploded = true;
    
    cout<<"THE VACUUM HAS EXPLODED!" <<endl;
  }
  
  if(t1.getpotential() > rand() % 101)
  {
    shorted = true;
    
    cout<<"THE VACUUM HAS SHORTED!" <<endl;
  }
 
  return;
}

void vacuum::empty()
{

  cout<< "The trash items: ";
  
  for(int i = 0; i < (tinbag-1); i++)
  {
    cout<< bag[i].getname() << ", ";
  }
  
  cout<< " were placed into the trashcan." <<endl;
  
  //This also "resets" the bag array...... kinda.
  tinbag = 0;
  
  return;
}

bool vacuum::isExploded()
{
  return exploded;
}

bool vacuum::isSparky()
{
  return shorted;
}

  
