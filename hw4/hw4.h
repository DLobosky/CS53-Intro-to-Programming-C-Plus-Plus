// Programmer: Dalton Lobosky          Date: 02/19/2013
// Class: CS53                         Section: C
// Purpose: 

#include <iostream>
using namespace std;

int main()
{
  // Variable Declarations
  const float BEER = 4.88, SPAM = 1.77, DOHNUTS = 3.29, MUSTARD_PACKETS = 2.50;
  float money, funds, cash = 0.0, leftover = 0;
	int choice, how_many, beer = 0, spam = 0, dohnut = 0, mustard = 0, number = 0;
	bool quit;
	string again;
	
	cout.setf(ios::fixed); 
  cout.setf(ios::showpoint); 
  cout.precision(2);

	// Greeting
	cout << endl << endl << endl << "Welcome, Marge, to your Online Shopping "
       << "Wizard!" << endl << endl << endl;
	
	
	
	// Logic
	do
	{ 
	  beer = 0;
		spam = 0;
		dohnut = 0;
		mustard = 0;
		quit = false;
    again = 'n';
		
	  do
		{ 
		  // Money Prompt
      cout << "How much money can you spend today?" << endl << endl;
	    cin >> funds;
			money = funds;
		} while (money < 0);
			
		do
		{
      do
      {
        cout << endl << "MENU: \n"
             << "1. Beer ($4.88)\n2. Spam ($1.77)\n3. DOHnuts ($3.29)\n"
             << "4. Mustard Packets (100 Count) ($2.50)\n5. Quit" << endl;
				cin >> choice;		 
      }while (choice < 1 || choice > 5);
			
			switch (choice)
			{
			  case 1:
				{
				  cout << endl << endl << "How many beers do you want?\n" << endl;
					cin >> how_many;
					
					if (money >= (how_many * BEER))
					{
					  money -= (how_many * BEER);
						beer += how_many;
					}
					else
					{
					  number = 0;
						
						for (int i = 1; i <= how_many && money >= (i * BEER); i++)
						{
						  number++;
						}
						
						money -= (number * BEER);
						
						
						cout << "With the amount of money that you have, you can only"
						     << " afford " << number << " beer(s)." << endl << endl;
						
            beer += number;

					}
				}
				break;
				
				case 2:
				{
				  cout << endl << endl << "How many cans of Spam do you want?\n"
					     << endl;
					cin >> how_many;
					
					if (money >= (how_many * SPAM))
					{
					  money -= (how_many * SPAM);
						spam += how_many;
					}
					else
					{
					  number = 0;
						
						for (int i = 1; i <= how_many && money >= (i * SPAM); i++)
						{
						  number++;
						}
						
						money -= (number * SPAM);
						
						
						cout << "With the amount of money that you have, you can only"
						     << " afford " << number << " can(s) of Spam." << endl << endl;

            spam += number;

					}
				}
				break;
				
				case 3:
				{
				  cout << endl << endl << "How many DOHnuts do you want?\n" << endl;
					cin >> how_many;
					
					if (money >= (how_many * DOHNUTS))
					{
					  money -= (how_many * DOHNUTS);
						dohnut += how_many;
					}
					else
					{
					  number = 0;
						
						for (int i = 1; i <= how_many && money >= (i * DOHNUTS); i++)
						{
						  number++;
						}
						
						money -= (number * DOHNUTS);
						
						
						cout << "With the amount of money that you have, you can only"
						     << " afford " << number << " boxes of DOHnuts." 
								 << endl << endl;
             
            dohnut += number;

					}
				}
				break;
				
				case 4:
				{
				  cout << endl << endl << "How many packs of mustard do you want?\n"
        		   << endl;
					cin >> how_many;
					
					if (money >= (how_many * MUSTARD_PACKETS))
					{
					  money -= (how_many * MUSTARD_PACKETS);
						mustard += how_many;
					}
					else
					{
					  number = 0;
						
						for (int i = 1; i <= how_many && money >= (i * MUSTARD_PACKETS)
						    ; i++)
						{
						  number++;
						}
						
						money -= (number * MUSTARD_PACKETS);
						
						
						cout << "With the amount of money that you have, you can only"
						     << " afford " << number << " packs of mustard."
								 << endl << endl;

            mustard += number;

					}
				}
				break;
				
				case 5:
				{
				  quit = true;
				}
				break;
			}
    }while (quit == false);
		
    leftover = funds - money;

		cout << "Your Cart: \n" << beer << " case(s) of beer\n" << spam 
		     << " can(s) of Spam\n" << dohnut << " box(es) of DOHnuts\n"
				 << mustard << " case(s) of mustard\n\nYou have spent: $"
				 << money << "\nYou have: $" << leftover << " leftover\n\n" << (flush);
				 			 
		
		
		cout << "Do you want to shop again?\nYes: y\nNo: n" << endl << endl;
		cin >> again;
  }while (again == "y" || again == "Y");
	
	return 0;
}