#ifndef NAMESPACE_BOUQUET_H
#define NAMESPACE_BOUQUET_H
#include "Flower.h"
namespace sdds {
	const int MESS_MAX_LEN = 30;
	const int MAX_FLOWERS = 3;
	class Bouquet
	{
	public:
		Bouquet();
		Bouquet(const Flower* fInBouquet, int noFlowersBouquet = MAX_FLOWERS, const char* msgBouquet = "Congratulations");
		const char* message() const;
		double price() const;
		bool isEmpty()const;
		void setEmpty();
		void setMessage(const char* prompt);
		void discardBouquet();
		void arrangeBouquet();
		ostream& display() const;
		void flushKeyboard() const;

		~Bouquet();

	private:
		double b_price;
		char* b_message;
		Flower* b_flowers;
		int b_flowerCount;


	};


}

#endif // !NAMESPACE_BOUQUET_H