// RobotSquad.h
// Robot.h
#ifndef NMAESPACE_ROBOT_SQUAD_H
#define NMAESPACE_ROBOT_SQUAD_H
#include"Robot.h"
#include <ostream>

namespace sdds
{
	const int SQUAD_NAME_MAX_LEN = 10;
	class RobotSquad {
		private:
			char* name;
			Robot* robots;
			int count;
		public:
			RobotSquad();
			RobotSquad(const char* name);
			Robot* getRoster();
			void operator--();
			void operator+=(Robot&);
			std::ostream& display() const;
	};

}
#endif