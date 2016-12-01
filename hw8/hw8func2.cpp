// Programmer: Dalton Lobosky                   Date: 04/10/2013
// File: hw8func.cpp                                  Section: C
// Purpose: The file that contains all the funnction definitions for the
//          hw8header.h file
//
// File: hw8func.cpp
//*****************************************************************************



#include<iostream>
#include<string>
#include<cctype>
#include "hw8header.h"

using namespace std;

void menu()
{
  cout << "\n\nWelcome to L33tinat0r\n" << endl;
  cout << "1. Translate: English to L33t" << endl;
  cout << "2. Translate: L33t to English" << endl;
  cout << "3. Quit" << endl << endl;

  return;
}



void english_l33t()
{
  char english_arr[99]={0};
 // int i = 0;
  
  cout << "Enter the phrase in English" << endl;
  cin.getline(english_arr, 99, '\n');
  
/*  for(int i = 0; english_arr[i] != '\n'; ++i)
  {
    switch(english_arr[i])
    {
      case 'a':
      case 'A':
        cout << "@";
        break;
        
      case 'b':
      case 'B':
        cout << "8";
        break;
        
      case 'c':
      case 'C':
        cout << "(";
        break;
        
      case 'd':
      case 'D':
        cout << "[)";
        break;
        
      case 'e':
      case 'E':
        cout << "3";
        break;
        
      case 'f':
      case 'F':
        cout << "|=";
        break;
        
      case 'g':
      case 'G':
        cout << "9";
        break;
        
      case 'h':
      case 'H':
        cout << "#";
        break;
        
      case 'i':
      case 'I':
        cout << "][";
        break;
        
      case 'j':
      case 'J':
        cout << "]";
        break;
        
      case 'k':
      case 'K':
        cout << "|<";
        break;
        
      case 'l':
      case 'L':
        cout << "1";
        break;
        
      case 'm':
      case 'M':
        cout << "|\\/|";
        break;
        
      case 'n':
      case 'N':
        cout << "|\\|";
        break;
        
      case 'o':
      case 'O':
        cout << "0";
        break;
        
      case 'p':
      case 'P':
        cout << "|?";
        break;
        
      case 'q':
      case 'Q':
        cout << "4";
        break;
      
      case 'r':
      case 'R':
        cout << "|^";
        break;
        
      case 's':
      case 'S':
        cout << "$";
        break;
        
      case 't':
      case 'T':
        cout << "7";
        break;
        
      case 'u':
      case 'U':
        cout << "|_|";
        break;
        
      case 'v':
      case 'V':
        cout << "\\/";
        break;
        
      case 'w':
      case 'W':
        cout << "\\^/";
        break;
        
      case 'x':
      case 'X':
        cout << "><";
        break;
        
      case 'y':
      case 'Y':
        cout << "/";
        break;
        
      case 'z':
      case 'Z':
        cout << "%";
        break;
        
      case ' ':
        cout << " ";
    }
    cin.ignore('\n');*/
    
    cout << english_arr;
    return;
  //}
  
}

void l33t_english()
{
  char l33t_arr[99]={0};
//  int i = 0;
  cout << "Enter the phrase in L33t" << endl;
  cin.getline(l33t_arr, 99, '\n');
  
  for(int i = 0; l33t_arr[i] != '\n'; ++i)
  {
    if(l33t_arr[i] == '@')
      cout << 'a';
      
    else if(l33t_arr[i] == '8')
      cout << 'b';
    
    else if(l33t_arr[i] == '(')
      cout << 'c';
      
    else if(l33t_arr[i] == '[')
    {
      if(l33t_arr[i++] == ')')
        cout << 'd';
    }
    
    else if(l33t_arr[i] == '3')
      cout << 'e';
      
    else if(l33t_arr[i] == '|')
    {
      if(l33t_arr[i++] == '=')
        cout << 'f';
    }
    
    else if(l33t_arr[i] == '9')
      cout << 'g';
      
    else if(l33t_arr[i] == '#')
      cout << 'h';
      
    else if(l33t_arr[i] == ']')
    {
      if(l33t_arr[i++] == '[')
        cout << 'i';
    }
      
    else if(l33t_arr[i] == ']')
      cout << 'j';
      
    else if(l33t_arr[i] == '|')
    { 
      if(l33t_arr[i++] == '<')
        cout << 'k';
    }
      
    else if(l33t_arr[i] == '1')
      cout << 'l';
      
    else if(l33t_arr[i] == '|')
    {
      if(l33t_arr[i++] == '\\')
        if(l33t_arr[i++] == '/')
          if(l33t_arr[i++] == '|')
            cout << 'm';
    }
      
    else if(l33t_arr[i] == '|')
    {
      if(l33t_arr[i++] == '\\')
        if(l33t_arr[i++] == '|')
          cout << 'n';
    }
    
    else if(l33t_arr[i] == '0')
      cout << 'o';
      
    else if(l33t_arr[i] == '|')
    {
      if(l33t_arr[i++] == '?')
        cout << 'p';
    }
    
    else if(l33t_arr[i] == '4')
      cout << 'q';
      
    else if(l33t_arr[i] == '|')
    {
      if(l33t_arr[i++] == '^')
        cout << 'r';
    }
    
    else if(l33t_arr[i] == '$')
      cout << 's';
      
    else if(l33t_arr[i] == '7')
      cout << 't';
      
    else if(l33t_arr[i] == '|')
    {
      if(l33t_arr[i++] == '_')
        if(l33t_arr[i++] == '|')
          cout << 'u';
    }
    
    else if(l33t_arr[i] == '\\')
    {
      if(l33t_arr[i++] == '/')
        cout << 'v';
    }
    
    else if(l33t_arr[i] == '\\')
    {
      if(l33t_arr[i++] == '^')
        if(l33t_arr[i++] == '/')
          cout << 'w';
    }
    
    else if(l33t_arr[i] == '>')
    {
      if(l33t_arr[i++] == '<')
        cout << 'x';
    }
    
    else if(l33t_arr[i] == '`')
    {
      if(l33t_arr[i++] == '/')
        cout << 'y';
    }
    
    else if(l33t_arr[i] == '%')
      cout << 'z';
  
    else
      cout << l33t_arr[i];
  }
    cin.ignore('\n');
  return;
}

