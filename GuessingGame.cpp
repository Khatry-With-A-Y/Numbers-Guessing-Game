#include<iostream>
#include<cstdlib> //contains rand( ) and srand( )
#include<ctime> //contains time( )
#include<conio.h> //contains getch( ) to wait for a key press
using namespace std;

class GuessingGame
{
	private:
		char difficulty; //number range difficulty option chosen by user 
		char mode; //limited or unlimited guess mode chosen by user
		char restart; //variable to store chosen choice about replay
		
		int num; //random number generated
		int range; //generate a number from 0 to range
		
		int user_Guess; //number guessed by user
		int current_Attempt; //number of times the user attempted to guess the number
		
		int max_Attempts_Allowed; //number of pre-defined available attempts to guess the number
		int max_Attempts_Diff1=4; //gives 4 attempts for easy difficulty in limited mode
		int max_Attempts_Diff2=8; //gives 8 attempts for normal difficulty 
		int max_Attempts_Diff3=12; //gives 12 attempts for hard difficulty 
		
		int *history; // declaring array history as pointer to store previous guesses
	
	public:
		void startGame()
		{
            difficultyMenu(); //takes input for char difficulty
			modeMenu(); //takes input for char mode
			
			if(mode=='1')
				{
				system("cls");
				switch(difficulty)
					{
					case '1':
						cout<<"You have to guess it correctly in 4 attempts."<<endl;
						cout<<"The number is between 0 - 50."<<endl;
						
						max_Attempts_Allowed = max_Attempts_Diff1; //gives 4 attempts
						range = 50;
						break;
							
					case '2':
						cout<<"You have to guess it correctly in 8 attempts."<<endl;
						cout<<"The number is between 0 - 100."<<endl;
						
						max_Attempts_Allowed = max_Attempts_Diff2; //gives 8 attempts
						range = 100;
						break;
							
					case '3':
						cout<<"You have to guess it correctly in 12 attempts."<<endl;
						cout<<"The number is between 0 - 150."<<endl;
						
						max_Attempts_Allowed = max_Attempts_Diff3; //gives 12 attempts
						range = 150;
						break;
					}	
				}
				
			else
				{
				system("cls");
				max_Attempts_Allowed=1; // value of this variable does not matter for unlimited mode
				cout<<"You have unlimited tries. Try guessing any number from ";
				switch(difficulty)
					{
					case '1':
						cout<<"0 - 50."<<endl;
						range = 50;
						break;
							
					case '2':
						cout<<"0 - 100."<<endl;
						range = 100;
						break;
							
					case '3':
						cout<<"0 - 150."<<endl;
						range = 150;
						break;
					}	
				}
								
				switch(difficulty)
				{
				case '1':                    //range = 50
					Generate0toRange(range);
					checkGuess(range);
					break;
				
				case '2':                    //range = 100
					Generate0toRange(range);
					checkGuess(range);
					break;
				
				case '3':                    //range = 150
					Generate0toRange(range);
					checkGuess(range);
					break;
				}
		}
		
		void difficultyMenu()
		{
			retry:
			cout<<"Welcome to the Number Guessing Game!\n\n";
			cout<<"Select your difficulty level (Number range?)-\n";
			cout<<"1. Easy (Between 0 to 50)\n";
			cout<<"2. Medium (Between 0 to 100)\n";
			cout<<"3. Hard (Between 0 to 150)\n";
			cout<<"4. Exit the game\n";
			cout<<"\nYour choice? ";
			cin>>difficulty;
		
			switch(difficulty)
				{
				case '1':
					break;
					
				case '2':
					break;
					
				case '3':
					break;
					
				case '4':
					cout<<"\nGame exited."<<endl;
					exit(0);
					break;
    			
				default: //if input is invalid
        			system("cls");
        			cout<<"Invalid Input. Please enter '1', '2', '3', or '4' only.\n" << endl;
        			goto retry;
				}
		}


		void modeMenu()
		{
			retry:
				cout<<"\nHow many guesses do you want?\n";
				cout<<"1. Limited Guesses (Normal Mode)\n";
				cout<<"2. Unlimited Guesses (Easy Mode)\n";
				cout<<"Your choice? ";
				cin>>mode; 
	
				if(mode!='1' && mode!='2')
					{
						system("cls");
						cout<<"Invalid choice. Re-enter either '1' or '2' only."<<endl;
						goto retry;
					}	
		}
		
		
		int Generate0toRange(int range)
		{
			srand(time(0));   //time(0) retrieves current system time from epoch i.e 1970,Jan1,00:00
			num=rand();       //srand(); seeds rand with time(0) to generate a random num
			while(num>range)
				{
				num=rand();
				}
			return num;
		}	
	
	
		void checkGuess(int range)
		{	
			current_Attempt=0;
			history=new int [max_Attempts_Allowed];	

			while(user_Guess!=num && max_Attempts_Allowed>0) 
			{ 
				cout<<"\nWhat do you think is the number?"<<"Num =" <<num<<"\n>>";	
				cin>>user_Guess;
				system("cls");
				
				if(user_Guess<0 || user_Guess>range)
				{
					cout<<user_Guess<<" is out of range. Try again."<<endl;
				}
				else if(user_Guess<num)
				{
					cout<<"The number is larger than "<<user_Guess<<". Try again."<<endl;
				}
				else if(user_Guess>num)
				{
					cout<<"The number is smaller than "<<user_Guess<<". Try again."<<endl;
				}
				
				provideHints();
				current_Attempt++;
			}	
		
		
			if(user_Guess==num)
			{
				cout<<"WOW! Congratulations! You guessed correct!\n\nThe number was "<<num<<". You guessed it in "<<current_Attempt<<" attempts."<<endl;	
			}                                                                                                               
			else if(max_Attempts_Allowed==0 && mode=='1') 
			{              
				system("cls");
				cout<<"OH NO! You ran out of attempts. The number was "<<num<<"."<<endl;
				cout<<"\nBetter luck next time!"<<endl;
			}
			
			delete [ ] history;
			
			startNewGameOrExit();
		}
		
		
		void startNewGameOrExit()
		{	
			cout<<"\nWould you like to play again (y/n)?\n";
			restart = getch(); // getch() waits for any key to be pressed. If pressed, it does not display the pressed key but takes input key. 
			system("cls");
			
			if(restart=='y' || restart=='Y')
			{
				startGame();
			}
			else
			{
				system("cls");
				cout<<"Are you sure you want to exit (y/n)?\n";
				restart = getch();
				
				if(restart=='y' || restart=='Y')
				{
					cout<<"Game Exited.";
					exit(0); //instead of exiting, program flow has to return to original 4 games main menu.
				}
				else
				{
					system("cls");
					startGame();
				}
			}
		}
		
		
		void provideHints()
		{	
			if(mode=='1' && user_Guess!=num) //if user has limited tries and has not guessed correct yet
				{          
				max_Attempts_Allowed--;
				                    
				if(max_Attempts_Allowed==1)
				{
					cout<<"\nOne last try remaining."<<endl;
				}	
				
				history[current_Attempt]=user_Guess; 
		 
			    for(int i=0;i<=current_Attempt-1;i++) //for n elements, sorting must be performed (n-1) times
			    {
			        for(int j=0;j<=current_Attempt-1;j++)
			         {
			            if(history[j] > history[j+1])
			            {
			            int temp=history[j]; 
			            history[j]=history[j+1];
			            history[j+1]=temp;
			            }  
			        }
			    }
	
    			cout<<"\nThe number is ";
			    for(int i=0;i<=current_Attempt;i++)
			    {
			            if(history[i]>num)
			           	{
			            cout<<"< "<<history[i];
						}
			            else
			            {
			            cout<<"> "<<history[i];
			       		}
			       		
			            if(i!=current_Attempt)
							cout<<" , ";	
				} 
			    cout<<".\n";
				}
		}
	
};

int main()
{
	GuessingGame game1;
	game1.startGame();
	return 0;
}
