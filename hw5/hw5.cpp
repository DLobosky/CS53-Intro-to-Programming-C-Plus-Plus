// Programmer: Dalton Lobosky                   Date: 02/27/2013
// Class: CS53                                  Section: C
// Purpose: To use functions to calculate how much time marge spends on her 
//   chores. 

#include <iostream>
using namespace std;

// Pre: None
// Post: Returns the greeting
// Description: Greets the user
void greetings();

// Pre: None
// Post: Changes value of state
// Description: Coolects Marge's state of mind
short get_state_of_mind();

// Pre: State must be greater than 0
// Post: Displays a message for Lisa
// Description: Instructs Lisa to do one of two things
short serv_Lisa(const short &state);

// Pre: None
// Post: Returns time spent feeding Maggie
// Description: Collects how much baby food Maggie was fed
short serv_Maggie(const short &state);

// Pre: None
// Post: Returns time spent helping Homer
// Description: Collects Homer's hunger value
short serv_Homer(const short &state);

// Pre: None
// Post: Returns time spent helping Bart
// Description: Calculates time spent helping bart
short serv_Bart(const short &state, const short &total_time);

// Pre: None
// Post: Returns time Marge has left for chores
// Description: Calculates time remaining for Marge to finish chores
short Marge_time(const short &total_time);

// Pre: None
// Post: Prints out how much time Marge has remaining 
// Description: Outputs the findings 
void present_Results(const short &time_Marge);

// Pre: None
// Post: Reutrns value used to calculate time spent helping Homer
// Description: Caluculates value used to calculate time spent helping Homer
short doh(const short &hunger);

// Pre: None
// Post: Outputs goodbye message 
// Description: Lets user know that program is over
void signoff();

const int MIN_PER_DAY = 600;

int main()
{
  short state, total_time = 0, time_Marge = 0;
 
  greetings();
  state = get_state_of_mind();
  total_time += serv_Lisa(state);
  total_time += serv_Maggie(state);
  total_time += serv_Homer(state);
  total_time += serv_Bart(state, total_time);
  time_Marge += Marge_time(total_time);
  present_Results(time_Marge);
  signoff();
   
}


void greetings()
{
  cout << endl << endl << "Good morning, Marge.\a" << endl;
  return;
}

short get_state_of_mind()
{
  short scale;

  do
  {
    cout << endl << endl << "On a scale of 1 - 100, what is your state of "
         << "mind?\n1 - being zombie-like \n100 - being like taking Valium.\a" 
         << endl;
    cin >> scale;
  } while(scale < 0 || scale > 100);
  
  return scale;   
}

short serv_Lisa(const short &state)
{ 
  if (state % 2 == 0)
  {
    cout << "Have a wonderful day." << endl;
  }
  
  else 
  {
    cout << endl << endl << "Try not to kill your brother." << endl;
  }

  return 1;
}

short serv_Maggie(const short &state)
{
  const short DIAPER_CHANGE_TIME = 5;
  short food, time;
  
  do
  {
    cout << endl << endl << "On a scale from 0 - 10, how much food did you"
         << " give Maggie?" << endl; 
    cin >> food;
  } while (food < 0 || food > 10);
  
  if (food < state)
  {
    time = (food * DIAPER_CHANGE_TIME);
  }
  
  else
  {
    time = (DIAPER_CHANGE_TIME * state);
  } 

  return time;
} 

short serv_Homer(const short &state)
{
  const short BASE_TIME = 50;
  short hunger, num, hunger2, hunger5;
  
  do
  {
    cout << endl << endl << "What is Homer's hunger value?\n1: Hungry\n2: "
        << "Very hungry\n3: Homerian hungry" << endl;
    cin >> hunger;
  } while(hunger < 1 || hunger > 3);
  
  switch (hunger)
  {
    case 1:
    {
      num = BASE_TIME + doh(hunger); 
    }
    break;
    
    case 2:
    {
      hunger2 = hunger * 2;
      num = BASE_TIME + doh(hunger2) + state; 
    }
    break;
    
    case 3:
    {
      hunger5 = 5 * hunger;
      num = BASE_TIME + doh(hunger5);
    }
    break;
  }
  
  return num;
}

short serv_Bart(const short &state, const short &total_time)
{
  const short BASE_TIME = 25;
  short num;
  
  num = BASE_TIME + ((total_time * total_time) / state);
  
  return num;
}

short Marge_time(const short &total_time)
{
  const short BASE_TIME = 30;
  
  return MIN_PER_DAY - total_time - BASE_TIME;
}

void present_Results(const short &time_Marge)
{
  short time = time_Marge;

  cout << endl << endl << "You have " << time << " minutes left to"
       << " do your chores." << endl; 

  return;
}

short doh(const short &hunger)
{
  return (hunger * hunger) - 1;
}

void signoff()
{
  cout << endl << endl << "Enjoy your day, Marge!" << endl << endl << endl;
}
