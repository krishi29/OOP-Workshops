// Robot.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Robot.h"
#include"Parts.h"
using namespace std;
namespace sdds
{
	Robot::Robot() {
		nickname[0] = '\0';
		durability = 0;
		arms = Arms();
	}
	Robot::Robot(const char* nk_name, int a_force, int r_durability) {
		int length = strlen(nk_name);
		if (nk_name == nullptr || nk_name[0] == '\0') {
			Robot();
		}
		else {
			if (r_durability < 1)
				r_durability = 100;
			durability = r_durability;
			arms = Arms(a_force);
			if (length > NICK_MAX_LEN)
				length = NICK_MAX_LEN;

			strcpy(nickname, nk_name);
			nickname[NICK_MAX_LEN] = '\0';

		}


	}
	ostream& Robot::display() const {
		if (nickname[0] != '\0' && durability != 0) {
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;
		}
		else
			cout << "This Robot isn't operational" << endl;

		return cout;

	}
	Robot::operator bool() const {
		bool valid = false;
		if (nickname == nullptr || durability == 0)
			valid = true;

		return valid;

	}
}