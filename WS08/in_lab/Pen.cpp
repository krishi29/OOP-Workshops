// Pen.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Pen.h"
using namespace std;
namespace sdds {
	Pen::Pen() {
		style = nullptr;
		ink = 0;
	}
	Pen::Pen(const char* s, int ink_) {
		if (s == nullptr || s[0] == '\0')
		{
			//Pen();
			style = nullptr;
			ink = 0;
		}
		else {
			style = new char[strlen(s) + 1];
			strcpy(style, s);
			style[strlen(s)] = '\0';
			if (ink_ < 1 || ink_>50) {
				ink = INK_MAX;
			}
			else
				ink = ink_;

		}
	}
	Pen::~Pen() {
		delete[] style;
	}
	void Pen::write(const char* text) {
		int nonSpace = 0;
		if (ink > 0) {
			cout << "Writing out the following: " << text << " with a Pen!" << endl;
			int temp = strlen(text);
			for (int i = 0; i < temp; i++) {
				if (text[i] != char(32))
					nonSpace++;
			}
			ink -= nonSpace * 2;
			if (ink < 0)
				ink = 0;
		}
		else {
			cout << "We can't write without ink!" << endl;
		}
	}
	void Pen::refill(int amount) {
		ink += amount;
		if (ink > INK_MAX)
			ink = INK_MAX;
		cout << "Refilling the pen with ink";
	}
	bool Pen::filled() const {
		return (ink > 0);

	}
	ostream& Pen::display(ostream& os) const
	{
		if (style == nullptr && ink == 0)
		{
			os << "This is an empty Pen" << endl;
		}
		else
		{
			os << "Pen Details" << endl;
			os << "Style: " << style << endl;
			os << "Ink Remaining: " << ink << endl;
		}
		return os;
	}

}
