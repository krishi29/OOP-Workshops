// Pencil.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Pencil.h"
using namespace std;
namespace sdds {

	Pencil::Pencil()
	{
		HB_scale[0] = '\0';
		graphite = 0;
	}
	Pencil::Pencil(const char* scale, int grpht)
	{
		if (scale == nullptr || scale[0] == '\0')
		{
			HB_scale[0] = '\0';
			graphite = 0;
		}
		else
		{
			strcpy(HB_scale, scale);
			HB_scale[strlen(scale)] = '\0';
			if (grpht < 1 || grpht >100)
			{
				grpht = GRAPHITE_MAX;
			}
			graphite = grpht;


		}
	}
	void Pencil::write(const char* text) {
		if (graphite > 0)
		{
			int noOfSpaces = 0;
			cout << "Writing out the following: " << text << " with a Pencil!" << endl;
			int temp = strlen(text);

			for (int i = 0; i < temp; i++)
			{
				if (text[i] == char(32))// char(32) is ASCII value of space;
					noOfSpaces++;
			}
			graphite -= 5 * noOfSpaces;

			if (graphite < 0)
				graphite = 0;

		}
		else
			cout << "We can't write without graphite!" << endl;

	}
	void Pencil::refill(int amount) {
		graphite += amount;
		if (graphite > GRAPHITE_MAX)
			graphite = GRAPHITE_MAX;
		cout << "Refilling the pencil with graphite" << endl;
	}
	bool Pencil::filled() const {
		bool flag = true;
		if (graphite <= 0)
			flag = false;
		return flag;

	}
	ostream& Pencil::display(ostream& os) const {
		if (HB_scale[0] == '\0' && graphite == 0)
		{
			os << "This is an empty Pencil" << endl;
		}
		else
		{
			os << "Pencil Details" << endl;
			os << "HB Value: " << HB_scale << endl;
			os << "Graphite Remaining: " << graphite << endl;

		}
		return os;

	}

}