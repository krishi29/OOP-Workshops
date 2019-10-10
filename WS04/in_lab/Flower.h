
#ifndef NAMESPACE_FLOWER_H
#define NAMESPACE_FLOWER_H
#include<iostream>
using namespace std;
namespace sdds
{
	const int NAME_MAX_LEN = 25;
	const int COL_MAX_LEN = 15;

	class Flower {

		char* f_name;
		char* f_colour;
		double f_price;

	public:
		Flower();
		Flower(const char* fName, const char* fColour, double fPrice);
		~Flower();
		const char* name() const;
		const char* colour() const;
		double price() const;
		bool isEmpty()const;
		void setEmpty();
		void setName(const char* prompt);
		void setColour(const char* prompt);
		void setPrice(const char* prompt);
		void setFlower();
		ostream& display() const;

	};

}
#endif // !NAMESPACE_FLOWER_H