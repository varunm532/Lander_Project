#include <iostream>
#include "Lander.h"

int main()
{
    // introduction + level/option selection
    int option;
    std::cout<< "Welcome to Moonlander!"<<'\n'<< "You start at 1000 meters with 500 units of fuel.";
    do{
        std::cout<< "Choose the planet you want to land at:"<<'\n'<< "0:Mecury"<<'\n'<<"1:Venus"<<'\n'<<"2:Earth"<<'\n'<<"3:Mars"<<'\n';
        std::cin>>option;
        if (option>3)
        {
            std::cout<<"Please choose a valid option"<<'\n';
        }
    }while (option>3 );
    

    bool exit = true;
    std::cout<<"To exit at anytime, enter 'E'"<<'\n';
    // creats game object
    Lander game(option);
    char input;
    while(game.continueGame() == true || exit == false)
    {
        // display status and promps user
        game.displayStatus();
        std::cin>> input;

        // checks for exit command and thrust value
        if (input == 'E' || input == 'e' )
        {
            exit = false;
            break;
        }
        else if ( input >= '0' && input <= '9')
        {
            int thrust = input - '0';
            game.applyThrust(thrust); // applies thrust
        }
        else
        {
            std::cout<< "Please enter a number between 0-9 or 'E' to exit the program"<<'\n';
        }
    }

    //checks if lander was successful
    if( game.hasCrashed() == true)
    {
        std::cout<< "Your velocity was too high, you crashed"<< '\n';
    }
    else
    {
        std::cout<< "Your lander landed safely"<< '\n';
    }
    game.createDataLog();
    return 0;
}