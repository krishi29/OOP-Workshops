// Parts.h
#ifndef NAMESPACE_PARTS_H
#define NAMESPACE_PARTS_H
namespace sdds
{

	const int MIN_FORCE = 50;

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


}

#endif // !NAMESPACE_PARTS_H
