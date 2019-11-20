// Figurine.h
#ifndef NAMESPACE_FIGURINE_H
#define NAMESPACE_FIGURINE_H
using namespace std;
namespace sdds {

	const int MAX_NAME_LEN = 20;
	const double DEFAULT_PRICE = 25.25;

	class Figurine {
		char name[MAX_NAME_LEN + 1];
		char* pose;
		double price;
		bool copy;

	public:
		Figurine();
		Figurine(const char* f_name, const char* f_pose, double f_price = DEFAULT_PRICE);
		~Figurine();
		void setEmpty();
		bool isEmpty() const;
		Figurine(const Figurine&);
		void setName(const char*);
		void setPose(const char*);
		void setPrice(double);
		ostream& display() const;
		operator bool() const;
		Figurine& operator=(const Figurine&);
		bool isCopy() const;
		bool operator ==(const Figurine&);
		
	};
}
#endif // !NAMESPACE_FIGURINE_H