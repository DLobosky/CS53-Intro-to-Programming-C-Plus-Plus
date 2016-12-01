//Programmers: Jason Beard, Dalton Lobosky, Carl Garrett Herrmann
//Date: 05/07/2013
//File:  house.cpp                 
//Class: CS 53
//Purpose: class definition for the house object.

#include"house.h"
using namespace std;
#include"hw9.h"
#include <cstdlib>
#include <ctime>

house::house(int house_size, short trash_num, cleaner & house_cleaner,
             family_member fam[], int fam_num)
{
  string name;
  int floor_x, floor_y;
  
  if(house_size <= 25 && house_size >= 5)
  {
    size = house_size;
  }
  else
  {
    size = 25;
  }
   
  trash = trash_num;
      
  for(int x = 0; x < floor_size; x++)
  {
    for(int y = 0; y < floor_size; y++)
    {
      floor[x][y] = '\0';
    }
  }
  
  // Setting locations of walls and windows.
  for(int y = 0; y < size; y++)
  {
    if((y != 0) && (y != (size - 1)) && (y % 4 == 0))
    {
      floor[0][y] = 'W';
      floor[size - 1][y] = 'W';
    }
    else
    {
      floor[0][y] = 'b';
      floor[size - 1][y] = 'b';
    }
  }
  
  for(int x = 0; x < size; x++)
  {
    if((x != 0) && (x != (size - 1)) && (x % 4 == 0))
    {
      floor[x][0] = 'W';
      floor[x][size -1] = 'W';
    }
    else
    {
      floor[x][0] = 'b';
      floor[x][size - 1] = 'b';
    }
  }                           
  
  // Setting random location for cleaner.
  do
  {                                                            
    floor_x = rand() % size;
    floor_y = rand() % size;
  }while(floor[floor_x][floor_y] != '\0');
  
  name = house_cleaner.getName();
  floor[floor_x][floor_y] = name[0];
  house_cleaner.setLocation(floor_x, floor_y);
  
  // Setting random locations for each family member.
  for(int i = 0; i < fam_num; i++)
  {                                      
    do
    {
      floor_x = rand() % size;
      floor_y = rand() % size;
    }while(floor[floor_x][floor_y] != '\0');
                                                        
    name = fam[i].getName();
    floor[floor_x][floor_y] = name[0];
    fam[i].setLocation(floor_x, floor_y);
  }
  // Setting random location for trash can.
  do
  {
    floor_x = rand() % size;
    floor_y = rand() % size;
  }while(floor[floor_x][floor_y] != '\0');
  
  floor[floor_x][floor_y] = 'C';
                                                                    
  scatter_trash();  
}
                                                                        
ostream& operator<<(ostream& os, const house& h)
{
  for(int x = 0; x < h.size; x++)
  {
    for(int y = 0; y < h.size; y++)
    {
      if(h.floor[x][y] == '\0')
      {
        os<< ".";
      }
      else
      {
        os<< h.floor[x][y];
      }
    }
    os<< endl;
  }
  return os;
}
                                                                                                                              
void house::scatter_trash()
{
  int floor_x, floor_y;
                                                                                                                                  
  for(int t = 0; t < trash; t++)
  {
    do
    {
      floor_x = rand() % size;
      floor_y = rand() % size;
    }while(floor[floor_x][floor_y] != '\0');
                                                                                                                                                            
    floor[floor_x][floor_y] = 't';
    
  }
                                                                                                                                                                
  return;
}
                                                                                                                                                                  
int house::getSize()
{
  return size;
}
                                                                                                                                                                    
char house::getFloorSpace(const int x, const int y)
{
  return floor[x][y];
}

void house::trash_dec()
{
  trash--;
  
  return;
}

void house::trash_add()
{
  trash++;
  
  return;
}

int house::getTrash()
{
  return trash;
}

void house::setFloorSpace(const int x, const int y, const char n)
{
  
  floor[x][y] = n;
  
  return;
}  
