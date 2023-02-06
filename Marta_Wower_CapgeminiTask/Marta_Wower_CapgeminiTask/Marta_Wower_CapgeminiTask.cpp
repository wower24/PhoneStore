// Marta_Wower_CapgeminiTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "phone.h"

int main()
{
    int number = 0;
    while (number != 4)
    {
        std::cout << "Hello, please choose what do you want to do:" << std::endl
             << "1 - add phone\n2 - show a report\n3 - delete phone\n4 - quit\n";
        std::cin >> number;

        switch (number) {
        case 1: {
            addPhone();
            break;
        }
        case 2: {
            int reportNumber = 0;

            std::cout << "What kind of report do you want to see?" << std::endl
                << "1 - Show all phones by the same brand" << std::endl
                << "2 - Show all phones of a given form factor and screen size" << std::endl
                << "3 - Show the name of the brand with the maximum quantity of the phones" << std::endl
                << "4 - Show TOP-3 screen sizes" << std::endl
                <<"Any other number - Show all phones" << std::endl;

            std::cin >> reportNumber;

            switch (reportNumber) {
            case 1: {
                std::string brandName = "";
                std::cout << "Type in brand name: ";
                getline(std::cin >> std::ws, brandName);
                std::cout << std::endl;

                report(brandName);

                break;
            }
            case 2: {
                std::string formFactor = "";
                int screenSize = 0;
                
                std::cout << "Type in form factor: ";
                getline(std::cin >> std::ws, formFactor);
                std::cout << std::endl;
                std::cout << "Type in screen size: ";
                std::cin >> screenSize;

                report(formFactor, screenSize);
                break;
            }
            case 3: {
                //first create a vector with only brand names in it
                std::vector<std::string> brandNames;
                for (Phone phone : phones)
                    brandNames.push_back(phone.getBrandName());

                report(brandNames);
                break;
            }
            case 4: {
                //first create a vector with only screen sizes in it
                std::vector<int> screenSizes;
                for (Phone phone : phones)
                    screenSizes.push_back(phone.getScreenSize());

                report(screenSizes);
                break;
            }
            default: {
                report();
            }
            }

            break;
        }
        case 3: {
            int deleteID = 0;
            std::cout << "Please provide an ID of the phone that should be deleted: ";
            std::cin >> deleteID;
            deletePhone(deleteID);
            std::cout << std::endl;
            break;
        }
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
