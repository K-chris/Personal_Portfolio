# Personal Portfolio
This is a ongoing Portfolio of programming projects I have worked ongoing

## Digital Clock
Digital Clock Is a C++ program that is an command line clock that updates every second and you can change the time with the menu. 
This will display a clock in both a 12 hr and 24 hr format to the user. The default time is the localtime on the computer. 
- What works well.
	- the functions that update the time and the functions to convert and display 12hr clock as the backend the code is stored as 24hr format.
	- The clock uses threads to update the time every "second" using wait so not 100% accurate but for the scope of the project works well enough. 
- what could use improvement.
	- The user input could be reworked as right now with the way the screen is updated every second when you enter in a value it gets cleared from the screen. 
	- These will make the code more user friendly as the user will still see their value while before it would not be visible but was still present. 
- what was the most challenging part?
	- The most challenging part to write was figuring out how to implement threads and allow them to operate while still allowing the user to input the time they want.
	- To overcome this, I researched examples of using threads in a simple way to better understand how they work.
- What skills from this program will be useful to other projects?
	- The threads in this project will definitely be used in future projects to either multithread calculations or sort algorithms for speed, or to update the program automatically
- How is this program maintainable, readable and adaptable?
	- my main program mainly calls the Clock class I wrote so I could use the clock class in another project if I needed to convert time on the fly.
	- to keep it readable, I have used naming conventions that make sense and have included inline comments to what each part of the code does. 
	- with separate files for the class and the main, I can update functions in the Clock class without always needing to update the main code, for maintainability
