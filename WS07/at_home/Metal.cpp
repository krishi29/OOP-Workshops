// Metal.cpp

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<iomanip>
#include "Metal.h"
using namespace std;
namespace sdds {

	Metal::Metal() {
		name = nullptr;
		moh_Metal = 2.5;
	}
	Metal::Metal(double w_metal, int p_Metal, const char* c_Metal, const char* n_Metal, double m_Metal) :Ore(w_metal, p_Metal, c_Metal) {
		if (n_Metal == nullptr || n_Metal[0] == '\0')
		{
			*this = Metal();
		}
		else {
			int length = strlen(n_Metal);
			length = length > NAME_LEN ? NAME_LEN : length;
			name = new char[length + 1];
			strncpy(name, n_Metal, length + 1);
			moh_Metal = m_Metal > 0 ? m_Metal : DEFAULT_MOHS;
		}
	}
	Metal::~Metal() {
		delete[] name;
	}
	void Metal::refine() {
		if (Ore::refine())
			moh_Metal += 1;

	}
	ostream& Metal::display(ostream& os) const {
		if (name != nullptr && name[0] != '\0' && moh_Metal > 0)
		{
			os << "Name: " << name << endl;
			Ore::display(os);
			os << "Mohs: " << moh_Metal << endl;
		}
		else
			os << "This metal is imaginary" << endl;
		return os;

	}
	istream& Metal::input(istream& is) {
		char temparr[NAME_LEN + 1];
		double tempMohs = 0.0;
		cout << "Enter a value for this metal's name: ";
		is.getline(temparr, NAME_LEN + 1, '\n');
		if (name != nullptr) {
			delete[] name;
		}
		name = new char[NAME_LEN + 1];
		strcpy(name, temparr);
		name[NAME_LEN] = '\0';

		cout << "Enter a value for this metal's mohs: ";
		is.clear();
		is >> tempMohs;
		if (tempMohs <= 0)
			tempMohs = DEFAULT_MOHS;
		moh_Metal = tempMohs;
		Ore::input(is);
		return is;
	}
	ostream& operator<<(ostream& os, const Metal& met) {
		os << "Metal" << endl;
		met.display(os);
		return os;

	}
	istream& operator>>(istream& is, Metal& met) {
		met.input(is);
		return is;

	}
}