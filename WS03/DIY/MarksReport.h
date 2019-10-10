#ifndef SDDS_MARKSREPORT_H
#define SDDS_MARKSREPORT_H

#include "Mark.h"
namespace sdds
{

	class MarksReport
	{

	private:
		Mark* m_mark;
		char m_title[70];
		int noOfmarks;

	public:
		void initialize();
		void getMarks();
		void print();
		void terminate();
	};
}
#endif