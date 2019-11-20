// Ore.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
#include<cstring>
#include"Ore.h"
using namespace std;
namespace sdds {

	Ore::Ore() {
		weight = 0;
		purity = 0;
		classification[0] = '\0';
	}
	Ore::Ore(double w, int p, const char* c) {
		if (w < 1)
			w = DEFAULT_WEIGHT;
		weight = w < 1 ? DEFAULT_WEIGHT : w;
		purity = (p < 1 || p>100) ? DEFAULT_PURITY : p;
		strncpy(classification, c, CLASS_LEN);

	}
	bool Ore::refine() {

		bool check = true;
		if (purity < 100)
		{
			weight -= 20;
			purity += 10;
			check = true;
		}
		else
		{
			purity = 100;
		}
		if (purity == 100)
		{
			cout << "Can no longer be refined" << endl;
			check = false;
		}
		return check;


	}

	ostream& Ore::display(ostream& os) const {
		if (classification[0] == '\0' && weight == 0 && purity == 0) {
			os << "This ore is imaginary" << endl;
		}
		else {
			os << "Weight: " << fixed << setprecision(2) << weight << endl;
			os << "Purity: " << purity << endl;
			os << "Classification: " << classification << endl;
		}

		return os;
	}
	istream& Ore::input(istream& is) {
		double tempWeight = 0.0;
		int tempPurity = 0;
		char tempClassification[CLASS_LEN + 1];
		cout << "Enter a value for this ore's weight: ";
		is >> tempWeight;
		cout << "Enter a value for this ore's purity: ";
		is >> tempPurity;
		is.ignore();
		cout << "Enter a classification for the ore (MAX 30 chars): ";

		//getline(tempClassification,30);
		is.getline(tempClassification, CLASS_LEN + 1, '\n');
		Ore tmp(tempWeight, tempPurity, tempClassification);
		*this = tmp;
		return is;

	}
	ostream& operator<<(ostream& os, const Ore& ore) {
		os << "Ore" << endl;
		ore.display(os);
		return os;
	}
	istream& operator>>(istream& is, Ore& ore) {
		ore.input(is);
		return is;

	}
};