//Programmers: Jason Beard, Dalton Lobosky, Carl Garrett Herrmann
//Date: 05/07/2013
//File:  family_member.cpp                 
//Class: CS 53
//Purpose: class definition for family_member object.

#include "family_member.h"
#include "house.h"
#include "cleaner.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

family_member::family_member()
{
  location.x = 0;
  location.y = 0;
  alive= true;
                
  //int rand_person = rand() % 4;
              
  ifstream in;
                  
  in.open("family_member.txt");
                    
  for(int i = 0; i <= next_fm; i++)
  { 
    in>> name;
    // cout<<"Next family member number is " << next_fm <<endl;        
    in>> sloppiness_factor;
  }
  
  next_fm++;
                   
  in.close();
}
                                    
ostream& operator<<(ostream& os, const family_member fm[])
{
  for(int i = 0; i < 4; i++)
  {
    os<< fm[i].name.c_str() << " is at (" << fm[i].location.x << ","
      << fm[i].location.y << "), and has a sloppiness factor of "
      << fm[i].sloppiness_factor << "." <<endl;
  }       
  return os;
}
                                          
string family_member::getName()
{
  return name;
}
                                            
void family_member::setLocation(const int x, const int y)
{
  location.x = x;
  location.y = y;
  
  return;
}

void family_member::step(house & h1)
{
  int way;
  bool can = false, trash=false, trashRep=false;
  char item;
  
  trash= drop_trash(h1);
  
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
        can = false;
        break;
    
      case 't':
        trashRep=true;
        can = true;
		
        break;
      
      case 'b':
        can = false;
        break;
      
      case 'W':
        can = true;
        alive = false;
        cout<<name <<"FELL OUT WINDOW!!!!!!!!!!!" <<endl;
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
		
      case 'M':
        can = false;
        break; 
        
      case '\0':
        can = true;
        break;         
    }
	
	
  }while(can == false);
  
 
  if(can == true && trash==false)
  {
    switch (way)
    {
      case 0:
        h1.setFloorSpace(location.x, location.y, '\0');
        if (trashRep==true)
        {
          h1.setFloorSpace(location.x, location.y, 't');
        }
		
        location.y --;
        h1.setFloorSpace(location.x, location.y, name[0]);
        break;
        
      case 1:
        h1.setFloorSpace(location.x, location.y, '\0');
	if (trashRep==true)
	{
	  h1.setFloorSpace(location.x, location.y, 't');
	}
		
        location.y ++;
        h1.setFloorSpace(location.x, location.y, name[0]);
        break;
        
      case 2:
        h1.setFloorSpace(location.x, location.y, '\0');
	if (trashRep==true)
	{
	  h1.setFloorSpace(location.x, location.y, 't');
	}
		
        location.x --;
        h1.setFloorSpace(location.x, location.y, name[0]);
        break;
        
      case 3:
        h1.setFloorSpace(location.x, location.y, '\0');
	if (trashRep==true)
	{
	  h1.setFloorSpace(location.x, location.y, 't');
	}
		
        location.x ++;
        h1.setFloorSpace(location.x, location.y, name[0]);
        break;
    }
  }
  if (trash && can)
  {
    switch (way)
	{
	  case 0:
	    h1.setFloorSpace(location.x, location.y, 't');
            location.y --;
            h1.setFloorSpace(location.x, location.y, name[0]);
	    if (trashRep==true && trash==true)
	    {
	      h1.trash_dec();
	    }
		
	    break;
	  case 1:
	    h1.setFloorSpace(location.x, location.y, 't');
            location.y ++;
            h1.setFloorSpace(location.x, location.y, name[0]);
	    if (trashRep==true && trash==true)
	    {
	      h1.trash_dec();
	    }
		
	    break;
	  case 2:
	    h1.setFloorSpace(location.x, location.y, 't');
            location.x --;
            h1.setFloorSpace(location.x, location.y, name[0]);
	    if (trashRep==true && trash==true)
	    {
	      h1.trash_dec();
	    }
		
	    break;
	  case 3:
	    h1.setFloorSpace(location.x, location.y, 't');
            location.x ++;
            h1.setFloorSpace(location.x, location.y, name[0]);	  
	    if (trashRep==true && trash==true)
	    {
	      h1.trash_dec();
	    }
		
	    break;
	}
  } 
   
  


  return;
}

bool family_member::drop_trash(house & h1)
{
  bool drops= false;
  int chance= rand() % 101;
  
  if (sloppiness_factor>=chance)
  {
    drops=true;
    h1.trash_add();
  } 
  
  return drops;
}

bool family_member::getAlive()
{
  return alive;
}
