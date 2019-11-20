// Figurine.cpp

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
#include<cstring>
#include"Figurine.h"
using namespace std;
namespace sdds {
	void Figurine::setEmpty()
	{
		name[0] = '\0';
		pose = nullptr;
		price = 0.0;
	}
	Figurine::Figurine() {
		copy = false;
		setEmpty();

	}
	bool Figurine::isEmpty() const
	{
		return ((name == nullptr || name[0] == '\0') && pose == nullptr && price == 0.0);
	}
	Figurine::Figurine(const char* f_name, const char* f_pose, double f_price) {
		copy = false;
		/*if (f_name[0] == '\0' ||f_name == nullptr || f_pose[0] == '\0' || f_pose == nullptr)*/
		if (f_name == nullptr || f_pose == nullptr)
			setEmpty();

		else {
			setName(f_name);
			setPose(f_pose);
			setPrice(f_price);
		}


	}
	Figurine::~Figurine()
	{
		setEmpty();
		delete[] pose;
	}
	Figurine::Figurine(const Figurine& fig) {
		this->price = fig.price;

		strcpy(this->name, fig.name);
		if (fig.pose == nullptr)
		{
			this->pose = nullptr;

		}
		else
		{
			setPose(fig.pose);
		}
		copy = true;

	}
	void Figurine::setName(const char* f_name) {
		strncpy(name, f_name, strlen(f_name));
		name[strlen(f_name)] = '\0';
	}

	void Figurine::setPose(const char* f_pose) {
		this->pose = new char[strlen(f_pose) + 1];
		strcpy(this->pose, f_pose);
		this->pose[strlen(f_pose)] = '\0';
	}

	void Figurine::setPrice(double f_price) {
		if (f_price < 1)
			f_price = DEFAULT_PRICE;

		this->price = f_price;

	}

	ostream& Figurine::display() const {
		if (isEmpty()) {
			cout << "This Figurine has not yet been sculpted" << endl;
			if (isCopy()) {

				cout << "This is a replica of emptiness" << endl;
			}
		}
		else {
			cout << "Figurine Details" << endl;
			cout << "Name: " << name << endl;
			cout << "Pose: " << pose << endl;
			cout << "Price: " << fixed << setprecision(2) << price << endl;
			if (isCopy()) {

				cout << "This is a replica" << endl;
			}
		}

		return cout;

	}
	Figurine::operator bool() const {
		return(name == nullptr || name[0] == '\0');

	}
	Figurine& Figurine::operator=(const Figurine& fig)
	{
		if (this == &fig) {
			return *this;
		}
		delete[] pose;
		setEmpty();
		this->price = fig.price;

		strcpy(this->name, fig.name);
		if (fig.pose == nullptr)
		{
			this->pose = nullptr;

		}
		else
		{
			setPose(fig.pose);
		}
		copy = true;
		return *this;

	}
	bool Figurine::isCopy() const
	{
		return copy;
	}
	bool Figurine::operator==(const Figurine& fig)
	{
		if (strcmp(name, fig.name)==0 && fig.price == price && strcmp(pose, fig.pose)==0) {
			if (!fig.isCopy() && !this->isCopy()) {
				return true;
			}
		}
		return false;
	}
	
}
