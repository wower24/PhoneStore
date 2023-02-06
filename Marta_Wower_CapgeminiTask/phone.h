#ifndef PHONE_H
#define PHONE_H
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

class Phone {
private:
	std::string brandName{}; //name of brand
	std::string modelName{}; //name of model
	std::string formFactor{}; //bar, brick, slate, phablet, flip, slider, swivel, 
	int yearOfIssue{}; //the year that the phone was made in
	int screenSize{}; //diagonal in inches
	int price{};  //price
	int phoneID{};

public:
	Phone();
	Phone(std::string brandName, std::string modelName, std::string formFactor, int yearOfIssue, int screenSize, int price);

	//getters of fields that will be used outside of the class
	std::string getBrandName();
	std::string getFormFactor();
	int getScreenSize();
	int getPhoneID();

	std::string toString();

	~Phone();
};

extern std::vector<Phone> phones;

void addPhone();
void deletePhone(int phoneID);

//reports
void report(std::string brandName); //show all phones by the same brand
void report(std::string formFactor, int screenSize); //Show all phones of a given form factor and screen size
void report(std::vector<std::string> names); //Show the name of the brand with the maximum quantity of the phones
void report(std::vector<int> screenSizes); //Show TOP-3 screen sizes (popularity is determined by the number of phones with the screen size)
void report(); //show all phones

#endif