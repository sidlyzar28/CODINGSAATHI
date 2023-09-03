
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int
main ()
{
  srand (time (0));
  time_t now = time(0);
  char* date_time = ctime(&now);
  int lowerno = 1;
  int upperno = 100;
  int numbertobeguessed = rand () % (upperno - lowerno + 1) + lowerno;	
  int numberOfAttempts = 0;
  int userGuess;
  int maxAttempts = 10;
  int score = 0;

  cout << "Welcome to ->GUESS THE NUMBER GAME " << endl;
  cout << "----------------------------------  " << endl;
  cout <<"current date and time:"<<date_time << endl;
  cout << "The computer has selected a random number between " << lowerno << " and " <<
    upperno << "-> Try your best to guess it." << endl;

  while (numberOfAttempts < maxAttempts)
    {
      cout << "Enter the number that you guessed: "<<endl;
      cin >> userGuess;
      numberOfAttempts++;

      if (userGuess < lowerno || userGuess > upperno)
	{
	  cout << "Please enter a number between " << lowerno << " and " <<
	    upperno << "." << endl;
	  continue;
	}

      if (userGuess == numbertobeguessed)
	{
	  cout << "Congratulations! You guessed the correct number in " <<
	    numberOfAttempts << " attempts." << endl;
	  score += maxAttempts - numberOfAttempts + 1;
	  cout << "Your score is: " << score << endl;
	  cout << "Do you want to play again?Kindly answer in yes OR no only:- ";
	  string playAgain;
	  cin >> playAgain;

	  if (playAgain == "yes")
	    {
	      numbertobeguessed =
		rand () % (upperno - lowerno + 1) + lowerno;
	      numberOfAttempts = 0;
	      continue;
	    }
	  else
	    {
	      cout << "Thank you from our side for playing. Your final score is: " << score <<
		endl;
	      break;
	    }
	}
      else if (userGuess < numbertobeguessed)
	{
	  cout << "Too low ,increase your guess and Try again." << endl;
	}
      else
	{
	  cout << "Too high,decrease your guess and Try again." << endl;
	}
    }

  if (numberOfAttempts == maxAttempts)
    {
      cout <<
	"You've reached the maximum number of attempts allowed by the game. The correct number was: "
	<< numbertobeguessed << "." << endl;
      cout << "Your final score is: " << score << endl;
    }

  return 0;
}
