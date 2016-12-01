//Programmers: Jason Beard, Dalton Lobosky, Carl Garrett Herrmann
//Date: 05/07/2013
//File:  cleaner.cpp                 
//Class: CS 53
//Purpose: class definition for cleaner object.

#include "cleaner.h"
#include "house.h"
#include <cstdlib>
#include <ctime>

cleaner::cleaner(string obj_name, int x_coor, int y_coor)
{
  name = obj_name;
  location.x = x_coor;
  location.y = y_coor;
  stress = 0;
  alive = true;
  aneurism = false;
}
        
void cleaner::calc_stress(house house1, const bool alive[])
{
  int trash_n = 0;
  int people_n = 0;
  int h_size = 0;
  char floor_space;
                
  h_size = house1.getSize();
                  
  for(int x = 0; x < h_size; x++)
  {
    for(int y = 0; y < h_size; y++)
    {
      floor_space = house1.getFloorSpace(x,y);
                                
      switch (floor_space)
      {
        case 'H':
        case 'B':
        case 'L':
        case 'm':
          people_n++;
          break;
        case 't':
          trash_n++;
          break;
      }
    }
  }
               
  if (alive[0]==false)
  {
    people_n--;
  }	
  if (alive[1]==false)
  {
    people_n--;
  }	
  if (alive[2]==false)
  {
    people_n--;
  }	
  if (alive[3]==false)
  {
    people_n--;
  }	
  
  stress = (int)((trash_n * 100.0)/(h_size * h_size)) + (2 * people_n);
  
  if(stress >= 100)
  {
    aneurism = true;
    stress = 100;
    
    cout<<"STRESS TOO HEIGH!!!!!!!!!!!!!!!!" <<endl;
  }
                                                                                                                                     
  return;
}
                                                                                                                                        
string cleaner::getName()
{
  return name;
}
                                                                                                                                          
void cleaner::setLocation(const int x, const int y)
{
  location.x = x;
  location.y = y;
}
                                                                                                                                              
ostream& operator << (ostream& os, const cleaner cl)
{
  os<< cl.name.c_str() << " is at (" << cl.location.x << "," << cl.location.y
    << "), and has a stress level of " << cl.stress << " out of 100." <<endl;
  
  return os;
}
                                                                                                                                                      
int cleaner::getStress()
{
  return stress;
}

bool cleaner::getAlive()
{
  return alive;
}

void cleaner::step(house & h1)
{
  int way;
  bool can = false;
  char item;
  trash mytrash;
  
  do
  {
    way = rand() % 4;
    
    switch (way)
    {
      case 0:
        item = h1.getFloorSpace(location.x, location.y - 1);
        break;
      
      case 1:
        item = h1.getFloorSpace(location.x, location.y + 1);
        break;
      
      case 2:
        item = h1.getFloorSpace(location.x - 1, location.y);
        break;
        
      case 3:
        item = h1.getFloorSpace(location.x + 1, location.y);
        break;
      default:
        item = '\0';
    }
        
    switch (item)
    {
      case 'C':
        dyson.empty();
        can = false;
        break;
    
      case 't':
        dyson.vac(mytrash);
        h1.trash_dec();
        can = true;
        break;
      
      case 'b':
        can = false;
        break;
      
      case 'W':
        can = true;
        alive = false;
        cout<<"FELL OUT WINDOW!!!!!!!!!!!" <<endl;
        break;
        
      case 'H':
        can = false;
        break;
        
      case 'B':
        can = false;
        break;
          
      case 'L':
        can = false;
        break;
        
      case 'm':
        can = false;
        break;
        
      case '\0':
        can = true;
        break;         
    }
	
	
  }while(can == false);
  
 
	
	
  if(can == true)
  {
    switch (way)
    {
      case 0:
        h1.setFloorSpace(location.x, location.y, '\0');
        location.y --;
        h1.setFloorSpace(location.x, location.y, 'M');
        break;
        
      case 1:
        h1.setFloorSpace(location.x, location.y, '\0');
        location.y ++;
        h1.setFloorSpace(location.x, location.y, 'M');
        break;
        
      case 2:
        h1.setFloorSpace(location.x, location.y, '\0');
        location.x --;
        h1.setFloorSpace(location.x, location.y, 'M');
        break;
        
      case 3:
        h1.setFloorSpace(location.x, location.y, '\0');
        location.x ++;
        h1.setFloorSpace(location.x, location.y, 'M');
        break;
    }
  }
  
  
                               
  if(stress >= 100 || dyson.isExploded() || dyson.isSparky())
  {
    alive = false;
  }
  
  
  return;
}


