// Pen.h
#ifndef NAMESPACE_PEN_H
#define NAMESPACE_PEN_H
#include <iostream>
using namespace std;
#include "WriteInstrument.h"
namespace sdds {

	const int INK_MAX = 50;
	class Pen :public WriteInstrument {
		char* style;
		int ink;
	public:
		Pen();
		Pen(const char*, int);
		~Pen();
		virtual void write(const char*);
		virtual void refill(int);
		virtual bool filled() const;
		virtual ostream& display(ostream& os) const;

	};
}
#endif // !NAMESPACE_PEN_H