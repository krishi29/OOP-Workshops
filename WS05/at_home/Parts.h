// Parts.h
#ifndef NAMESPACE_PARTS_H
#define NAMESPACE_PARTS_H
namespace sdds
{

	const int MIN_FORCE = 50;
	const int MIN_SPEED = 25;
	
	class Arms
	{
		private:
			int force;

		public:
			Arms();
			Arms(int);
			int getForce() const;
			Arms& operator++();
			Arms operator++(int);
			Arms& operator+=(int);
	};

	class Legs
	{
		private:
			int speed;

		public:
			Legs();
			Legs(int);
			int getSpeed() const;
			Legs& operator-=(int);
	};

	bool operator>(const Legs&, const Legs&);
	bool operator<(const Legs&, const Legs&);
	bool operator>(const Arms&, const Arms&);
	bool operator<(const Arms&, const Arms&);

}

#endif // !NAMESPACE_PARTS_H
