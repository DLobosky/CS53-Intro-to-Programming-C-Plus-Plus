//Programmers: Jason Beard, Dalton Lobosky, Carl Garrett Herrmann
//Date: 05/07/2013
//File:  hw9.cpp                 
//Class: CS 53
//Purpose: file used to demonstrate the use and functionality of the cleaner, 
//         family_member, and house classes.

#include "hw9.h"
#include "family_member.h"
#include "cleaner.h"
#include "house.h"
#include <cstdlib>
#include <ctime>

int family_member::next_fm = 0;

int main()
{
  srand(time(NULL));
  bool alive[4];
  
  
  
  
  family_member fm[4];
  
  
  

  
  cleaner Marge("Marge", 2,4);
  house my_house(10, 5, Marge, fm, 4);
  alive[0]=fm[0].getAlive();
  alive[1]=fm[1].getAlive();
  alive[2]=fm[2].getAlive();
  alive[3]=fm[3].getAlive();
  
  cout<<my_house <<endl <<endl;
  Marge.calc_stress(my_house, alive);
  cout<< Marge;
  
 
  do
  {
	   
    Marge.step(my_house);
    if (alive[0])
    {
      fm[0].step(my_house);
    }
    if (alive[1])
    {
      fm[1].step(my_house);
    }
    if (alive[2])
    {
      fm[2].step(my_house);
    }
    if (alive[3])
    {
      fm[3].step(my_house);
    }
	
    
    cout<<my_house <<endl <<endl;
	
    alive[0]=fm[0].getAlive();
    alive[1]=fm[1].getAlive();
    alive[2]=fm[2].getAlive();
    alive[3]=fm[3].getAlive();
    
    cout<< fm;
    Marge.calc_stress(my_house, alive);
    cout<< Marge;
          
   
  }while(Marge.getAlive() == true && my_house.getTrash() > 0);
  
  if (Marge.getAlive() != true)
  {
    cout << "\nMarge Died!!!!" << endl;
  }
  
  cout << "Trash Left: ";
  cout<< my_house.getTrash() <<endl;
                             
  return 0;
}
