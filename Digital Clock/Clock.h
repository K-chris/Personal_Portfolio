#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>   //include iostream for I/O to and from the user
#include <string>     //include string for data type strings 

using namespace std;  //use the std:: namespace


class Clock { //class Clock object for setting and incrementing the time
public:       //list of public accessable functions by the user

	/**
	*Gets the correct clear call for the current users OS 
	*/
	void clear();

	/**
	 * Prints menu of user selection choices
	 */
	void printMenu();

	/**
	 * Gets menu choice 1 through maxChoice, inclusive
	 *
	 * @param maxChoice, maximum choice index, a number between 2 and 9, inclusive
	 * @return the first legal choice input, could be 1 through maxChoice, inclusive
	 */
	unsigned int getMenuChoice(unsigned int maxChoice);
	/**
	*sets the seconds variable in the Clock class
	* @param s, seconds 0-59 expected 
	*/
	void setSecond(unsigned int s);

	/**
	*sets the minutes variable in the Clock class
	* @param m, minutes 0-59 expected
	*/
	void setMinute(unsigned int m); 

	/**
	*sets the hours variable in the Clock class
	* @param h, hours 0 - 59 expected
	*/
	void setHour(unsigned int h);

	/**
	 * Display the clocks
	 *in 12 hour / 24 hour formats
	 * @param hours, 0 to 23
	 * @param minutes, 0 to 59
	 * @param seconds, 0 to 59
	 */
	void displayClocks();

	/**
	 *Adds 1 second to the clock
	 * @param h, hours 0 to 23
	 * @param m, minutes 0 to 59
	 * @param s, seconds 0 to 59
	 */
	void addOneSecond();

	/**
	 *Adds 1 minute to the clock
	 * @param h, hours 0 to 23
	 * @param m, minutes 0 to 59
	 */
	void addOneMinute();

	/**
	 *Adds 1 hour to the clock
	 * @param h, hours 0 to 23
	 */
	void addOneHour();

private:   //list of private variables and functions, hidden from user

	unsigned int hours;    //var hours, expected range 0-23
	unsigned int minutes;  //var minutes, expected range 0-59
	unsigned int seconds;  //var seconds, expected range 0-59

	/**
	 * Formats the time in military format
	 * 
	 * @param hours, 0 to 23
	 * @param minutes, 0 to 59
	 * @param seconds, 0 to 59
	 * @return hh:mm:ss
	 */
	string formatTime24();

	/**
	 * Formats the time in am/pm format
	 *
	 * @param h, hours 0 to 23
	 * @param m, minutes 0 to 59
	 * @param s, seconds 0 to 59
	 *
	 * @return hh:mm:ss A M or hh:mm:ss P M where hh is between 01 and 12, inclusive
	 */
	string formatTime12();

	/**
	 * Formats a number as 2 digits, with a leading 0 if needed
	 * This method can be useful when converting a time like 9 hours, 12 minutes and 3 seconds to "09:12:03"
	 *
	 * @param n number to format, assumed between 0 and 59, inclusive
	 * @returns two digit string representation of number
	 */
	string twoDigitString(unsigned int);

	/**
	 * Returns a string of length n, of character value of var c.
	 * For example, nCharString(5, '*') should return "*****"
	 *
	 * @param n string length, >=0
	 * @return string of length n c's
	 */
	string nCharString(size_t, char);
};
#endif // !CLOCK_H