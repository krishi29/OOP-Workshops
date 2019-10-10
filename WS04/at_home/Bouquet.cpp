#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<iomanip>
#include"Bouquet.h"
#include"utils.h"
using namespace std;
namespace sdds {
	void Bouquet::flushKeyboard() const //to clear the buffer
	{
		char ch;
		do {
			ch = cin.get();
		} while (ch != '\n');

	}
	Bouquet::Bouquet() {// default constructor
		setEmpty();
	}
	Bouquet::Bouquet(const Flower* fInBouquet, int noFlowersBouquet, const char* msgBouquet) {
		double price = 0.0;
		if (fInBouquet == nullptr)
		{
			setEmpty();
		}
		else
		{
			if (noFlowersBouquet <= MAX_FLOWERS)
				b_flowerCount = noFlowersBouquet;
			else
				b_flowerCount = MAX_FLOWERS;

			b_flowers = new Flower[MAX_FLOWERS];

			for (int i = 0; i < b_flowerCount; i++) {
				b_flowers[i].setName(fInBouquet[i].name(), strlen(fInBouquet[i].name()));
				b_flowers[i].setColour(fInBouquet[i].colour(), strlen(fInBouquet[i].colour()));
				b_flowers[i].setPrice(fInBouquet[i].price());
				price += b_flowers[i].price();
			}
			b_price = price;

			b_message = new char[strlen(msgBouquet) + 1];//dynamic memory allocation
			strcpy(b_message, msgBouquet);

		}
	}
	const char* Bouquet::message() const {
		return b_message;
	}
	double Bouquet::price() const {
		return b_price;

	}
	bool Bouquet::isEmpty()const {
		return(b_price == 0.0 && b_message == nullptr && b_flowers == nullptr && b_flowerCount == 0);

	}
	void Bouquet::setEmpty() {// safe state
		b_price = 0.0;
		b_message = nullptr;
		b_flowers = nullptr;
		b_flowerCount = 0;
	}
	void Bouquet::setMessage(const char* prompt) {
		char msg[MESS_MAX_LEN];
		cout << prompt;
		read(msg, MESS_MAX_LEN + 1, "A bouquets's message (non-empty) is limited to 30 characters... Try again: ");
		b_message = new char[strlen(msg) + 1];// dynamic memory allocation
		strcpy(b_message, msg);
	}
	void Bouquet::discardBouquet() {
		cout << "Discarding the current bouquet..." << endl;
		delete[] b_message;// memory deallocation
		delete[]b_flowers;
		setEmpty();
	}
	void Bouquet::arrangeBouquet() {

		char ans = 'Y';
		int noFlowers = 0;
		double price = 0.0;

		cout << "Arranging a new bouquet..." << endl;

		if (!isEmpty()) {
			cout << "This bouquet has an arrangement currently, discard it? (Y/N): ";

			do {
				cin >> ans;
				cin.clear();
				switch (ans) {
				case 'Y':
					discardBouquet();
					break;
				case 'N':
					cout << "No new arrangement performed..." << endl;
					break;
				default:
					cout << "The decision is either Y or N... Try again: ";
				}
			} while (ans != 'Y' && ans != 'N');
		}

		if (isEmpty() || ans == 'Y') {


			cout << "Enter the number of flowers in this bouquet (Valid: 1-3)... : ";
			read(noFlowers, 1, 3, "The valid range is 1-3... Try again: ");
			b_flowerCount = noFlowers;
			b_flowers = new Flower[b_flowerCount];
			for (int i = 0; i < b_flowerCount; i++) {
				//cin.clear();
				b_flowers[i].setFlower();
				price += b_flowers[i].price();
				flushKeyboard();
			}
			b_price = price;
			//flushKeyboard();
			cout << "A bouquet has been arranged..." << endl;
			setMessage("Enter a message to send with the bouquet...: ");

		}
	}
	ostream& Bouquet::display() const {
		if (isEmpty())
			cout << "This is an empty bouquet..." << endl;
		else {
			cout << "This bouquet worth " << fixed << setprecision(2) << b_price << " has the following flowers..." << endl;
			for (int i = 0; i < b_flowerCount; i++) {
				b_flowers[i].display();

			}
			cout << "with a message of: " << b_message << endl;
		}
		return cout;

	}

	Bouquet::~Bouquet() {//destructor
		if (isEmpty())
			cout << "An unknown bouquet has departed..." << endl;
		else
			cout << "A bouquet has departed with the following flowers..." << endl;
		delete[] b_message;
		delete[]b_flowers;

	}

}
