#include <iostream>
#include <windows.h>

//Prototypes
void Intro();
int TheFinalCountdown(int countdown);
void Ending();
void PlayAgain();

//Variable for random number generator
int r = rand() % 2;

//Variable for user input
std::string userInput;

int main()
{
    //Call Intro function
    Intro();

    return 0;
}

//Intro Function
void Intro()
{
    //Scenario explanation
    std::cout << "\n\nYou're currently on a spaceship that is about to explode!\n";
    std::cout << "Will you be able to escape before the countdown hits zero?\n\n";

    //Pause so the user can read the intro before counting down
    system("pause");

    //Call the countdown to self destruct
    //And pass it a number to start the countdown
    TheFinalCountdown(10);
}

//Create countdown function
//Make a recursive function to count down to space launch
int TheFinalCountdown(int countdown)
{
    //Make a base case
    if (countdown <= 0)
    {
        //Then base case is kicked off
        //Blast off!
        std::cout << "T-" << countdown << std::endl;

        //Pause for better UX
        system("pause");

        Ending();

        //Return from our function to kick it off the stack
        return 0;
    }
    //Make a recursive case
    else
    {
        //The recursive case fires again
        //Keep track of countdown
        std::cout << "T-" << countdown << std::endl;
        Sleep(1000);

        //Return from our function (adds to the stack)
        return TheFinalCountdown(--countdown);
    }
}

//Ending Function
void Ending()
{
    //Ending is chosen randomly
    if (r == 0)
    {
        std::cout << "\n\nYou survived! Congradulations!";
    }
    else if (r == 1)
    {
        std::cout << "\n\nI'm sorry, but you didn't make it out in time.";
    }    

    //Call the Play Again function
    PlayAgain();
}

void PlayAgain()
{
    //Get user input
    std::cout << "\n\nWould you like to try again? Enter 'yes' or 'no' and press enter. ";
    std::cin >> userInput;

    //Determine outcome based on user input
    if (userInput == "yes")
    {
        //Restart
        Intro();
    }
    else if (userInput == "no")
    {
        //End program
        return;
    }
    else
    {
        //Run the function again if the user didn't type 'yes' or 'no'
        std::cout << "\n\nI'm sorry, but I don't recognize that command.";
        PlayAgain();
    }
}