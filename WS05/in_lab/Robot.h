// Robot.h
#ifndef NMAESPACE_ROBOT_H
#define NMAESPACE_ROBOT_H
#include"Parts.h"
namespace sdds
{
	const int NICK_MAX_LEN = 10;
	class Robot
	{
	private:
		char nickname[NICK_MAX_LEN + 1];
		int durability;
		Arms arms;
	public:
		Robot();
		Robot(const char* nickname, int a_force, int r_durability);
		std::ostream& display() const;
		operator bool() const;

	};
}

#endif // !NMAESPACE_ROBOT_H
