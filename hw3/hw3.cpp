// Programmer: Dalton Lobosky        Date: 02/11/2013
// Class: CS53       Section: C
// Purpose: To create a program that will tell Marge Simpson what kind of 
//  doughnut to make for Homer Simpson, based on how bad his morning is going.

#include <iostream>
using namespace std;

int main()
{
  // Variable Declarations
  const int MIN_THUMPS = 0, MIN_DOHS = 1, MAX_STEPS = 10, CLOTHES_DIV = 3;
  const int CLOTHES_KRUSTY = 2, CLOTHES_WIGGUM = 0, MAX_COUNT = 3;
  const int BACON_POINT = 5, BUTTER_POINT = 3, VELV_POINT = 6, CHX_POINT = 50;
  const int GREASE_POINT = 13, DOUGHNUT_BASE = 10, BEER_POINT = 4;
  int thumps, dohs, steps, clothes, bacon, butter, velveeta;
  int chx_skn = 0, count = 0, point = 0;
  bool krusty = 0, wiggum = 0, bacon_bool = 0, velveeta_bool = 0, butter_bool;
  bool chx_skn_bool = 0, grease_bool = 0;

  
  // Greeting
  cout << endl << endl << endl << "Welcome, Marge, to your Doughnut Making "
  << "Wizard!" << endl << endl << endl;
  
  // Thumps Prompt
  cout << "How many times has Homer hit his head on the floor this morning?" 
  << endl;
  cin >> thumps;
  
  // DOH Prompt
  cout << endl << endl << "How many times did he yell DOH while shaving?"
  << endl;
  cin >> dohs;
  
  // Steps Prompt
  cout << endl << endl << "How many successful steps did homer take before"
  << " falling the rest?" << endl;
  cin >> steps;
  
  // Clothing Prompt
  cout << endl << endl <<"How many articles of clothing is Homer missing this"
  << " morning?" << endl;
  cin >> clothes;

  // Data Cleansing
  if (thumps >= MIN_THUMPS && dohs >= MIN_DOHS && steps <= MAX_STEPS)
  {
    // Logic  
    if (thumps % 2 == MIN_THUMPS)
    {
      krusty = 1;
      wiggum = 0;
      point += DOUGHNUT_BASE;
    }
    else
    {
      wiggum = 1;
      krusty = 0;
      point += DOUGHNUT_BASE;
    }
    
    if (krusty == 1 && wiggum == 0 && count < MAX_COUNT)
    {
      bacon = dohs;
      bacon_bool = 1;
      count++;
      point += BACON_POINT * bacon;
    }
    
    if (wiggum == 1 && krusty == 0 && count < MAX_COUNT)
    {
      butter = dohs;
      butter_bool = 1;
      count++;
      point += BUTTER_POINT * butter;
    }
    
    if (count < MAX_COUNT)
    {
      velveeta = (MAX_STEPS - steps) + dohs;
      velveeta_bool = 1;
      count++;
      point += VELV_POINT * velveeta;
    }
    
    if (clothes % CLOTHES_DIV == 0 && count < MAX_COUNT)
    {
      chx_skn++;
      chx_skn_bool = 1;
      count++;
      point += CHX_POINT * chx_skn;
    }
    
    if (krusty == 1 && clothes > CLOTHES_KRUSTY && count < MAX_COUNT && 
    wiggum == 0)
    {
      grease_bool = 1;
      count++;
      point += GREASE_POINT;
    }
    
    if (wiggum == 1 && clothes == CLOTHES_WIGGUM && krusty == 0 && 
    chx_skn_bool == 1)
    {
      chx_skn += 2;
      point += CHX_POINT * 2;
    }
      
    if (wiggum == 1 && clothes == CLOTHES_WIGGUM && krusty == 0 &&
    chx_skn_bool == 0)
    {
      chx_skn += 2;
      chx_skn_bool = 1;
      count++;
      point += CHX_POINT * 2;
    }
    
    if (krusty == 1 && wiggum == 0)
    {
      cout << endl << endl << endl << "Go to Krustybase Doughnuts and get a "
      << "doughnut with: " << endl << endl; 
    
      if (bacon_bool == 1)
      {
        cout << bacon << " strips of bacon" << endl;
      }
    
      if (velveeta_bool == 1)
      {
        cout << velveeta << " ounces of Velveeta" << endl;
      }
    
      if (chx_skn_bool == 1)
      {
        cout << chx_skn << " chicken skin(s)" << endl;
      }
      
      if (grease_bool == 1)
      { 
        cout << "A dollop of grease cream" << endl;
      }
    }
     
    if (wiggum == 1 && krusty == 0)
    {
      cout << endl << endl << endl << "Go to Wiggumbase Doughnuts and get a "
      << "doughnut with: " << endl << endl;
    
      if (butter_bool == 1)
      {
        cout << butter << " pats of butter" << endl;
      }
      
      if (velveeta_bool == 1)
      {
        cout << velveeta << " ounces of velveeta" << endl;
      }
      
      if (chx_skn_bool == 1)
      {
        cout << chx_skn << " chicken skin(s)" << endl;
      }
    }
  }
  
  else
  {
    cout << endl << endl << endl << endl << endl <<"Screw it, just give him a" 
    << " beer......" << endl << endl;
    point += BEER_POINT;
  }

  cout << endl << endl << endl << "Your point total for Homer's \"breakfast\""
  << " is: " << point << endl;
  
  cout << endl << endl << "Have a good day! :)" << endl << endl 
  << endl;
  
  return 0;
}
  
