#include<iostream>
#include<cstdlib> //contains rand( ) and srand( )
#include<ctime> //contains time( )
#include<conio.h> //contains getch( ) to wait for a key press
using namespace std;

class Betting
{
	private:
		char difficulty; //number range difficulty option chosen by user 
		char mode; //limited or unlimited guess mode chosen by user
		char restart; //variable to store chosen choice about replay
		
		int num; //random number generated
		int userguess; //number guessed by user
		int guessCount; //number of pre-defined available attempts to guess the number
		int attempt; //number of times the user attempted to guess the number

	public:
		void menu()
		{
			option:
			cout<<"Select your difficulty level (Number range?)-\n";
			cout<<"1. Easy (Between 0 to 50)\n";
			cout<<"2. Medium (Between 0 to 100)\n";
			cout<<"3. Hard (Between 0 to 150)\n";
			cout<<"4. Exit the game\n";
			cout<<"\nYour choice? ";
			cin>>difficulty;
			
			switch (difficulty) 
				{
   			 	case '1': // do nothing if 1,2,3,4 is selected
    		 	case '2':
    			case '3':
    			case '4':
    			break;
    			
				default: //if input is invalid
        		system("cls");
        		cout << "Invalid Input. Please enter '1', '2', '3', or '4' only." << endl;
        		goto option;
				}
			
			
			while(difficulty!='4')
			{
				retry:
				cout<<"\nHow many guesses do you want?\n";
				cout<<"1. Limited Guesses (Normal Mode)\n";
				cout<<"2. Unlimited Guesses (Easy Mode)\n";
				cout<<"Your choice? ";
				cin>>mode; //used later in checkinput( );
				if(mode!='1' && mode!='2')
					{
						system("cls");
						cout<<"Invalid choice. Re-enter either '1' or '2' only."<<endl;
						goto retry;
					}
				
				if(difficulty=='1')
					{
						guessCount=4; //gives 4 attempts
					}
				else if(difficulty=='2')
					{
						guessCount=8; //gives 8 attempts
					}
				else if(difficulty=='3')
					{
						guessCount=12; //gives 12 attempts
					}
				
				switch(difficulty)
				{
				case '1':
				generate0toN(50);
				checkinput(50);
				break;
				
				case '2':
				generate0toN(100);
				checkinput(100);
				break;
				
				case '3':
				generate0toN(150);
				checkinput(150);
				break;
				
				case '4':
				cout<<"Game exited."<<endl;
				break;
				
				}
			}
		}
		
		int generate0toN(int n)
		{
			//	int t=time(0); //time(0) retrieves current system time from epoch(1970,Jan1,00:00)
			srand(time(0)); 
			num=rand();
			int i=1;
			while(num>n)
				{
				i++;
				num=rand();
				}
			return num;
		}	
	
		void checkinput(int range)
		{	
			attempt=0;
			IncorrectGuess:
			if(mode=='1') //mode=='1' is limited guesses mode
					{
						if(guessCount==1)
							{
							cout<<"\nLast attempt."<<endl;
							}
												//cout<<"guessCount "<<guessCount<<endl;
						guessCount--;
				
						if(attempt==0)// if mode is limited guess mode and is the first attempt
							{
							system("cls");
							switch(difficulty)
								{
							case '1':
							cout<<"You have to guess it correctly in 4 attempts."<<endl;
							cout<<"The number is between 0 - 50."<<endl;
							break;
							
							case '2':
							cout<<"You have to guess it correctly in 8 attempts."<<endl;
							cout<<"The number is between 0 - 100."<<endl;
							break;
							
							case '3':
							cout<<"You have to guess it correctly in 12 attempts."<<endl;
							cout<<"The number is between 0 - 150."<<endl;
							break;
								}
							}
					}	
			
			//		
		//	int history;	
		//	switch (guessCount) 
				{
   			 //	case 3: // do nothing if it is the first attempt
    		 //	case 7:
    		//	case 11:
    		//	break;
    			
				//default: 
        	//	cout<<"You have tried the numbers: "<<history<<" , "<<endl;
				}
				//	
							
			cout<<"\nWhat do you think is the number?\n>>";
										//	cout<<num<<endl;
			cin>>userguess;
			//history=userguess;
			attempt++;
						
										//	cout<<"Attempt "<<attempt<<endl;
										//	cout<<"guessCount "<<guessCount<<endl;
			if(guessCount>0)
			{
				while(userguess!=num)
				{
					if(userguess<0 || userguess>range)
					{
						cout<<userguess<<" is out of range. Try again."<<endl;
						goto IncorrectGuess;
					}
					else if(userguess>num)
					{
						cout<<"The number is smaller than "<<userguess<<". Try again."<<endl;
						goto IncorrectGuess;
					}
					else if(userguess<num)
					{
						cout<<"The number is larger than "<<userguess<<". Try again."<<endl;
						goto IncorrectGuess;
					}
				}
				CorrectGuess:
				system("cls");
				cout<<"WOW! Congratulations! You guessed correct!\n\nThe number was "<<num<<". You guessed it in "<<attempt<<" attempts."<<endl;
				goto replay;
			}
			else if(mode=='1')
			{
			 	if(userguess!=num) 
				{
			 	system("cls");
				cout<<"OH NO! You ran out of attempts. Better luck next time!"<<endl;
				cout<<"The number was "<<num<<"."<<endl;
				goto replay;
				}
				else
				goto CorrectGuess;
			}
			
			
			replay:		
			cout<<"\nWould you like to play again?\nPress 'y' to play again or press any other key to exit.\n";
			restart = getch(); // getch() waits for any key to be pressed. If pressed, it does not display the pressed key. 
			system("cls");
			if(restart=='y' || restart=='Y')
			{
				menu();
			}
			else
			{
				system("cls");
				cout<<"Are you sure you want to exit? \nPress 'y' to exit or any other key to play again.";
				restart = getch();
				if(restart=='y' || restart=='Y')
				{
					exit(0); //instead of exiting, program flow has to return to original 4 games main menu.
				}
				else
				{
					system("cls");
					menu();
				}
			}
		}
};

int main()
{
	Betting b1;
	b1.menu();
	return 0;
}
