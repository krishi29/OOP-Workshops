
#include "ReportUtils.h"
#include <iostream>

namespace sdds {
	std::ostream& line(int len, char ch)
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << ch;
		}

		return std::cout;
	}
}