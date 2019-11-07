// Robot.h
#ifndef NMAESPACE_ROBOT_H
#define NMAESPACE_ROBOT_H
#include"Parts.h"
#include<iostream>

namespace sdds
{
	const int NICK_MAX_LEN = 10;
	class Robot
	{
		private:
			char nickname[NICK_MAX_LEN + 1];
			int durability;
			Arms arms;
			Legs legs;
		public:
			Robot();
			Robot(const char* nickname, int a_force, int speed, int r_durability);
			std::ostream& display() const;
			operator bool() const;
			Arms getArms() const;
			Legs getLegs() const;
			Robot& createCopy();
			Robot& operator-=(int);
	};

	void box(Robot&, Robot&);
}

#endif // !NMAESPACE_ROBOT_H
