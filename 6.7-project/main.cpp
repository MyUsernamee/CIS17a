
#include <iostream>

long hms_to_secs(int hours, int minutes, int seconds);

int main()
{

    std::cout << "6.7 Mini programming project exercise" << std::endl;
    std::cout << "This program converts hours, minutes, and seconds to total seconds." << std::endl;
    std::cout << "Enter 0 for all values or CTRL-C to exit." << std::endl;

    while (true)
    {

        std::cout << "Enter hours, minutes, and seconds (Press enter after each): " << std::endl;
        int hours, minutes, seconds;
        std::cout << "Hours: ";
        std::cin >> hours;
        std::cout << "Minutes: ";
        std::cin >> minutes;
        std::cout << "Seconds: ";
        std::cin >> seconds;

        if (hours == 0 && minutes == 0 && seconds == 0)
        {
            break;
        }

        std::cout << "Total seconds: " << hms_to_secs(hours, minutes, seconds) << std::endl;

        std::cout << std::endl;
    }
}

long hms_to_secs(int hours, int minutes, int seconds)
{
    return hours * 3600 + minutes * 60 + seconds;
}