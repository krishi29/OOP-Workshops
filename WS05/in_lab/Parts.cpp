// Parts.cpp
#include<iostream>
#include"Parts.h"
using namespace std;
namespace sdds
{

	Arms::Arms()
	{
		force = 0;
	}
	Arms::Arms(int a_forse)
	{
		if (a_forse < 1)
			a_forse = MIN_FORCE;

		force = a_forse;

	}

	int Arms::getForce() const {
		return force;

	}
	Arms& Arms::operator++() {
		force += 10;
		return *this;

	}
	Arms Arms::operator++(int a_force) {
		Arms temp = *this;
		force += 10;
		return temp;

	}
	Arms& Arms::operator+=(int increment) {
		force += increment;
		if (force < 1)
			force = 0;
		return *this;
	}
}
