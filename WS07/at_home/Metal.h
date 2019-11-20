// Metal.h

#ifndef NAMESPACE_METAL_H
#define NAMESPACE_METAL_H
#include "Ore.h"
namespace sdds {

	const double DEFAULT_MOHS = 2.5;
	const int NAME_LEN = 10;
	class Metal : public Ore {
	char* name;
	double moh_Metal;

	public:
		Metal();
		Metal(double w_metal, int p_Metal, const char* c_Metal, const char* n_Metal, double m_Metal);
		~Metal();
		void refine();
		ostream& display(ostream& os) const;
		istream& input(istream& is);
	};
	ostream& operator<<(ostream& os, const Metal& met);
	istream& operator>>(istream& is, Metal& met);

}
#endif // !NAMESPACE_METAL_H