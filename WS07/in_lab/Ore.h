// Ore.h
#ifndef NAMESPACE_ORE_H
#define NAMESPACE_ORE_H
using namespace std;
namespace sdds
{
	const double DEFAULT_WEIGHT = 300.50;
	const int DEFAULT_PURITY = 20;
	const int CLASS_LEN = 30;
	class Ore
	{

	public:
		Ore();
		Ore(double w, int p, const char* c = "Unknown");
		//~Ore();
		bool refine();
		ostream& display(ostream& os) const;
		istream& input(istream& is);

	private:
		double weight;
		int purity;
		char classification[CLASS_LEN + 1];

	};
	ostream& operator <<(ostream& os, const Ore& ore);
	istream& operator >>(istream& os, Ore& ore);

}
#endif // !NAMESPACE_ORE_H