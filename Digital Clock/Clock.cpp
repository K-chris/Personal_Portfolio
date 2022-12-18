#include "Clock.h"
using namespace std;


void Clock::setSecond(unsigned int s) {   //sets the seconds variable in the Clock class
    seconds = s;
}
void Clock::setMinute(unsigned int m) {  //sets the minutes variable in the Clock class
    minutes = m;
}
void Clock::setHour(unsigned int h) {  //sets the hours variable in the Clock class
    hours = h;
}

string Clock::twoDigitString(unsigned int n) {   //formats the time to two digit strings
    string digit;
    if (n <= 9) {
        digit = "0" + to_string(n);  //combines zero plus the string verson n into digit
    }
    else {
        digit = to_string(n);   //sets digit to the string version of n
    }
    return digit;  //return int string of length 2 
}

string Clock::nCharString(size_t n, char c) {
    string nString;
    for (int i = 0; i < n; ++i) {
        nString += c;
    }
    return nString;
}

string Clock::formatTime24() {
    // return time as hh:mm:ss
    return twoDigitString(hours) + ":" + twoDigitString(minutes) + ":" + twoDigitString(seconds);  
}

string Clock::formatTime12() {
    unsigned int localHours = hours;  //sets localHours to current hours  
    string amOrPm = " A M";   //Ini string of amOrPm to A M 
    if (localHours >= 12) {  //check to see the time is 12:00 to 23:00 militart time
        amOrPm = " P M";    //if so then set the amOrPm flag to P M
        localHours -= 12;    //subtract 12 to localHours to convert to 12hr format
    }
    //checks 1st if localHours is == 0 if it is then set it to 12 else does not alter
    // return as hh:mm:ss A M / P M
    return twoDigitString((localHours == 0) ? 12 : localHours) + ":" + twoDigitString(minutes) + ":" + twoDigitString(seconds) + amOrPm;
}


void Clock::printMenu() {
    int width = 25;       //sets width of menu to 25
    int listLength = 4;   //list entry size is 4
    //list of all the menu options
    const char* menuList[4] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
    
    cout << nCharString(16, ' ') << nCharString(width, '*') << endl;  //outputs * in the top

    //loops to output the entries in menuList
    for (int i = 0; i < listLength; ++i) {
        int spaceLength = width - 7 - strlen(menuList[i]);
        cout << nCharString(16, ' ') << "* " << i + 1 << " - " << menuList[i] << nCharString(spaceLength, ' ') << "*" << endl;
        if (i < listLength - 1) {
            cout << endl;  //if every line except the lastone in the list
        }
    }
    cout << nCharString(16, ' ') << nCharString(width, '*') << endl;   //outputs * at the bottom 
}

unsigned int Clock::getMenuChoice(unsigned int maxChoice) {
    char userChoice;  //ini userChoice var
    do {   //do while userChoice is not a valad option 
        cin >> userChoice;
    } while ((int(userChoice) - 48) < 1 || (int(userChoice) - 48) > maxChoice);
    // return the value
    return int(userChoice) - 48;
}

void Clock::displayClocks() { 
    //outputs the formatting for the clock output

    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;
    cout << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12() << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24() << nCharString(9, ' ') << nCharString(1, '*') << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;

}

void Clock::clear(){
    //checks to see if operating system is window/linux or Unix(apple)
#if defined _WIN32   
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void Clock::addOneSecond() {
    if (seconds == 59) { //checks to see if seconds are 59 and if so sets it back to 0 and calls addOneMinute()
        setSecond(0);
        addOneMinute();
    }
    else {  //else sets seconds+1 
        setSecond(seconds + 1);
    }
}

void Clock::addOneMinute() {
    if (minutes == 59) {//checks to see if minutes are 59 and if so sets it back to 0 and calls addOnehour()
        setMinute(0);
        addOneHour();
  }
    else {  //else sets minutes+1
        setMinute(minutes + 1);
    }
}

void Clock::addOneHour() {
    //sets hours to 0 if hours are currently 23 else hours+1 
    hours = (hours == 23) ? 0 : hours + 1;
}