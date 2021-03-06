// Pencil.h
#ifndef NAMESPACE_PENCIL_H
#define NAMESPACE_PENCIL_H
#include <iostream>
#include "WriteInstrument.h"
using namespace std;
namespace sdds {

	const int HB_MAX = 2;
	const int GRAPHITE_MAX = 100;
	class Pencil : public WriteInstrument {

		char HB_scale[HB_MAX + 1];
		int graphite;

	public:
		Pencil();
		Pencil(const char*, int);
		virtual void write(const char*);
		virtual void refill(int);
		virtual bool filled() const;
		virtual ostream& display(ostream& os) const;
	};
}
#endif // !NAMESPACE_PENCIL_H