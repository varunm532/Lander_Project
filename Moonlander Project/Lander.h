#pragma once
#include <vector>
#include <iostream>
#include <iostream>
#include <fstream>

class Lander
{
    public:
        Lander(int option);
        bool hasCrashed(); //true if landed; false if not
        bool continueGame(); // true game is continued; false if game stops
        void displayStatus(); //shows status
        void applyThrust(int amount); // applies thrust
        void createDataLog(); // returns file containing run data
        

    private:

        // game essential instance varaiables
        double altitude;
        int fuel;
        int time;
        double velocity;
        double gravity;

        // game log arrays
        std::vector<int> timeLog;
        std::vector<double> altitudeLog;
        std::vector<int> fuelLog;
        std::vector<double> velocityLog;

        // private methods
        void updateAltitude(const double velocity);
        void updateLog();
};