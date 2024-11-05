
#include <cassert>
#include <iostream>
#include <string>

const std::string months[12] =
	{"Janurary",
	"Feburary",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"};

const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isValidMonth(int month) {
	return month > 0 && month <= 12;
}

/// @return The name of the month given as a number NOTE: Returns an empty string if the month is invalid
std::string convertMonthNumberToName(int month) {
	if (!isValidMonth(month))
		return "";

	return months[month - 1];
}


/// @return The number of days in a month. NOTE: Returns -1 if the month is in valid
int getNumberOfDaysInMoth(int month) {
	if (!isValidMonth(month))
		return -1; // Month is invalid

	return daysInMonth[month - 1];
}

/// @brief Stores a date with the month day and year.
struct Date { // A struct was chosen because all members are public and this is meant as a way to store data and not a method for performing some action.
	unsigned int month;
	unsigned int day;
	unsigned int year;

	void init() {
		month = 1;
		day = 1;
		year = 2001;
	}

	/// @breif Creates a date with this given date: 1/1/2001
	Date() { init(); }
	/// NOTE: If the given date is in valid it will be set to the default date.
	Date(unsigned int m, unsigned int d, unsigned int y) : month(m), day(d), year(y) {
		if (!isValid())
			init(); // Invalid date set to default arguments
	}

	/// @return Returns wether the current date is valid
	bool isValid() {
		return isValidMonth(month) && day <= getNumberOfDaysInMoth(month) && day > 0;
	}

	/// @breif Prints the date in the format of MM/DD/YYYY NOTE: The output is not 0 padded.
	void printMini() {
		std::cout << month << "/" << day << "/" << year << std::endl;
	}

	/// @breif Prints the othput in the format "(Month Name) DD, YYYY NOTE: The output is not 0 padded
	void printNormal() {
		std::cout << convertMonthNumberToName(month) << " " <<  day << ", " << year;
	}

	/// @breif Prints the othput in the format "DD (Month Name) YYYY NOTE: The output is not 0 padded
	void printNormalFlipped() {
		std::cout << day << " " <<  convertMonthNumberToName(month) << " " << year;
	}

};


int main () {

	// Tests
	std::cout << "Performing tests... NOTE: If any test fails, it is using an assert statment meaning the program will fail to run if the test doesn't pass." << std::endl;
	std::cout << "As such the fact that the program is running means that all tests have passed." << std::endl;
	{
		// Test isValidMonth
		assert(isValidMonth(5));
		assert(!isValidMonth(13));

	}
	{
		// Test convertNumberToMonthName
		assert(convertMonthNumberToName(12) == "December");
		assert(convertMonthNumberToName(5) == "May");
		assert(convertMonthNumberToName(13) == "");
	
		// NOTE: Good practice here would be to test literally every month name, but I do not feel like writing all of that :(
	}
	{
		// Test getNumberOfDaysInMonth
		assert(getNumberOfDaysInMoth(1) == 31);
		assert(getNumberOfDaysInMoth(13) == -1);
	}
	{
		// Test default constructor
		Date date;

		assert(date.month == 1);
		assert(date.day == 1);
		assert(date.year == 2001);
	}
	{
		// Test normal constructor
		Date date(5, 13, 2005);
		
		assert(date.month == 5);
		assert(date.day == 13);
		assert(date.year == 2005);
	}
	{

		// Test invalidDate
		Date date(13, 43, 0);

		assert(date.month == 1);
		assert(date.day	== 1);
		assert(date.year == 2001);
	}
	std::cout << "Tests complete and passed!" << std::endl;

	// I would test the remaining functions, but that requires me to intercept the std::cout, which we could do, but for brevity I am not going to do that.
	
	// Basic program functionality
	unsigned int month = 0;
	int day = -1;
	int year = -1;

	while (!isValidMonth(month) ) {
		std::cout << "Please enter a month:" << std::endl;
		std::cin >> month;
	}
	while (day < 0 || day > getNumberOfDaysInMoth(month)){
		std::cout << "Please enter a day:" << std::endl;
		std::cin >> day;
	}

	while (year < 0) {
		std::cout << "Please enter a year:" << std::endl;
		std::cin >> year;
	}

	Date date(month, day, year);

	date.printMini();
	date.printNormal();
	date.printNormalFlipped();

}
