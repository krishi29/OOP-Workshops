
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Flower.h"
#include"utils.h"
#include<cstring>
using namespace std;
namespace sdds {
	Flower::Flower() {
		f_name = nullptr;
		f_colour = nullptr;
		f_price = 0;
	}
	Flower::Flower(const char* fName, const char* fColour, double fPrice) {
		if ((fName != nullptr && fName[0] != '\0') && (fColour != nullptr && fColour[0] != '\0') && fPrice > 0) {
			f_name = new char[strlen(fName) + 1];
			strcpy(f_name, fName);
			f_colour = new char[strlen(fColour) + 1];
			strcpy(f_colour, fColour);
			f_price = fPrice;
		}
		else
			setEmpty();
	}


	Flower::~Flower() {
		if (isEmpty())
			cout << "An unknown flower has departed..." << endl;
		else
			cout << colour() << " " << name() << " has departed..." << endl;
		delete[] f_name;
		delete[] f_colour;

	}
	const char* Flower::name() const {
		return f_name;

	}
	const char* Flower::colour() const {
		return f_colour;

	}
	double Flower::price() const {
		return f_price;

	}
	bool Flower::isEmpty()const {
		bool flag = true;
		if ((f_name != nullptr) && (f_colour != nullptr) && f_price > 0)
			flag = false;
		return flag;

	}
	void Flower::setEmpty() {
		f_name = nullptr;
		f_colour = nullptr;
		f_price = 0;

	}
	void Flower::setName(const char* prompt) {
		cout << prompt;
		char nameOfFlower[NAME_MAX_LEN + 1];
		read(nameOfFlower, NAME_MAX_LEN, "A flower's name is limited to 25 characters... Try again: ");
		f_name = new char[strlen(nameOfFlower) + 1];
		strcpy(f_name, nameOfFlower);


	}
	void Flower::setColour(const char* prompt) {

		cout << prompt;
		char colourOfFlower[COL_MAX_LEN + 1];
		read(colourOfFlower, COL_MAX_LEN, "A flower's colour is limited to 15 characters... Try again: ");
		f_colour = new char[strlen(colourOfFlower) + 1];
		strcpy(f_colour, colourOfFlower);


	}
	void Flower::setPrice(const char* prompt) {
		cout << prompt;
		double price;
		do {
			cin >> price;
			if (price <= 0)
				cout << "A flower's price is a non-negative number... Try again: ";
		} while (price <= 0);
		f_price = price;


	}
	void Flower::setFlower() {
		cin.clear();
		cout << "Beginning the birth of a new flower..." << endl;
		setName("Enter the flower's name... : ");
		setColour("Enter the flower's colour... : ");
		setPrice("Enter the flower's price... : ");
		cout << "The flower's current details..." << endl;
		display();

	}
	ostream& Flower::display() const {
		if (isEmpty())
			cout << "This is an empty flower..." << endl;
		else
			cout << "Flower: " << f_colour << " " << f_name << " Price: " << f_price << endl;
		return cout;

	}
	void Flower::setName(const char* name, int len) {

		f_name = new char[len + 1];
		strcpy(f_name, name);
	}
	void Flower::setColour(const char* colour, int len) {
		f_colour = new char[len + 1];
		strcpy(f_colour, colour);

	}
	void Flower::setPrice(double price) {
		if (price <= 0)
			price = 1;
		f_price = price;
	}



}
