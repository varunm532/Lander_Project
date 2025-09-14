#include <iostream>
#include <vector>
#include "Lander.h"
#include <iostream>
#include <fstream>

/**
 * Initilized instance varibale and sets gravity constant depending on user input
 * @param int representing option chosed by user
 */

using string = std::string;
Lander::Lander(int option)
{
    // gravitational constants
    const double MERCURY = -3.7;
    const double VENUS = -8.87;
    const double EARTH = -9.81;
    const double MARS = -3.73;

    // sets gravitational constant for game 
    switch(option)
    {
        case 0:
            gravity = MERCURY;
            break;
        case 1:
            gravity = VENUS;
            break;
        case 2:
            gravity = EARTH;
            break;
        case 3:
            gravity = MARS;
            break;
    }

    // sets instance variables
    altitude = 1000;
    fuel = 500;
    time = 0;
    velocity = 0;

    // creates initial logs
    timeLog.push_back(time);
    altitudeLog.push_back(altitude);
    fuelLog.push_back(fuel);
    velocityLog.push_back(velocity);
}


/**
 * updates current altitude
 * @param double representing velocity
 * private method
 */
void Lander::updateAltitude(const double velocity)
{
    altitude += velocity;
}

/** 
 * Applies thrust to the rocket
 * updates current fuel and velocity
 * @param int amount of thrust applied
 */

void Lander::applyThrust(int amount)
{
    // updates fuel
    // sets thrust value
    if(fuel == 0) // case if there is no fuel
    {
        velocity += gravity;
        
    }
    else if(fuel <amount) // case if fuel exists, but thrust value exeeds remaining fuel
    {
        int thrust = fuel;
        fuel = 0;
        velocity = velocity + gravity + thrust;
    }
    else // default 
    {
        int thrust = amount;
        fuel -= thrust;
        velocity = velocity + gravity + thrust; // updates current velocity
    }
    time ++;
    updateAltitude(velocity);
    updateLog();
    
}

/**
 * determins if lander lands or crashes
 * @return true if velocity is too high-- rocked crashes
 * @return false if velocity is acceptable
 */
bool Lander::hasCrashed()
{

    if (velocity < -5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * checks if the game is continued or not by check if the lander landed (altitude of 0)
 * @return true if altitude is greater than 0; false if not
 */
bool Lander::continueGame()
{
    
    bool isSafe = (altitude >=0)? true:false;
    return isSafe;
}

/**
 * Updates all the vectors regarding time, altitude,fuel, and velocity
 */
void Lander::updateLog()
{
    timeLog.push_back(time);
    altitudeLog.push_back(altitude);
    fuelLog.push_back(fuel);
    velocityLog.push_back(velocity);
}

/**
 * displays status
 */
void Lander::displayStatus()
{
    std::cout<<"------------------------------------"<<'\n';
    std::cout<< "Altitude: "<< altitude<<"m"<<'\n';
    std::cout<<"Velocity: "<< velocity<<"m/s"<<'\n';
    std::cout<<"Fuel: "<< fuel<<" units"<<'\n';
    std::cout<<"Enter thrust (0-9): "<<'\n';
    std::cout<<"------------------------------------"<<'\n';

}

/**
 * Creates a file containg all the data collected from each thrust input
 */
void Lander::createDataLog()
{
    // creates a file called "mission_log"
    std::ofstream dataFile("mission_log");

    //creates output string
    string output = "Time(s)    | Altitude (m)  | Velocity (m/s)    | Fuel (units) \n";

    // goes through vectos used to log data and formats into string
    for(int i= 0 ; i < timeLog.size(); i++)
    {
        output += std::to_string(timeLog[i]) + "           |" + std::to_string(altitudeLog[i]) + "           |" + std::to_string(velocityLog[i]) + "           |" + std::to_string(fuelLog[i]) + '\n';
        
    }

    // writes string to file and closes it
    dataFile << output;
    dataFile.close();
}


