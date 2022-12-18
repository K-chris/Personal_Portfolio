// project1 cs210.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Christopher Kooyman
//CS 210
//11/10/2022

#include "Clock.h"     //Include the Clock class object 
#include <ctime>       //Ctime to Ini the clock to local time
#include <thread>      // thread for multiple processes 
#include <atomic>      // atomic for thread termination 
using namespace std;   //using namespace std::


/**
*Updates the Clock object every 1000ms (1s)
* adds one second to the clock
* @param isRunning, boolean atomic var True/False
* @param myClock, Clock class object
*/
void clockThread(atomic<bool>& isRunning, Clock& myClock) {
    while (isRunning) {
        this_thread::sleep_for(1000ms);
        myClock.addOneSecond();
        myClock.clear();
        myClock.displayClocks();
        myClock.printMenu();
    }
}

void main(){   //main starts here
    Clock myClock;   //make a new empty clock
    atomic<bool> isRunning{ true };   //flag for the thread loop in clockThread function
    struct tm currentTime;  //ini new structure to import local time
    time_t now = time(0);   
    localtime_s(&currentTime, &now);   //gets the time and stores ut in currenttime 
    myClock.setHour(currentTime.tm_hour);   //set hour from currentTime 
    myClock.setMinute(currentTime.tm_min);  //sets minute from currentTime
    myClock.setSecond(currentTime.tm_sec);  //sets Seconds from currentTime
    unsigned int userChoice=0;   //ini var for user input
    thread cloThread(clockThread, ref(isRunning),ref(myClock));  //executes new thread in the clcokThread function to update clock
    do {  //do while user does not want to exit
        myClock.clear();   //clears out the terminal
        myClock.displayClocks();   //prints out the clocks to the screen
        myClock.printMenu();   //prints out the choice menu to user
        userChoice = myClock.getMenuChoice(4);   //prompts user for input

        switch(userChoice){
        case 1:
            myClock.addOneHour();  //incriments the hour by 1
            break;
        case 2:
            myClock.addOneMinute();   //incriments the minutes by 1
            break;
        case 3:
            myClock.addOneSecond();  //incriments the seconds by 1
            break;
        default:   //default case for all other choices 
            break;
        }

        //loop while user doesn't choose to exit
    }while (userChoice!=4);
    isRunning = false;  //sets running to false 
    cloThread.join();   //joins the thread 
}

