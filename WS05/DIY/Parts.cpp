// Parts.cpp
#include<iostream>
#include"Parts.h"
using namespace std;
namespace sdds
{Arms::Arms()
	{force = 0;}
Arms::Arms(int a_forse)
{if (a_forse < 1)
a_forse = MIN_FORCE;
force = a_forse;}
int Arms::getForce() const {
		return force;}
Arms& Arms::operator++() {
force += 10;return *this;}
Arms Arms::operator++(int a_force) 
{Arms temp = *this;
force += 10;return temp;}
Arms& Arms::operator+=(int increment) {
force += increment;
if (force < 1)
force = 0;return *this;}
Legs::Legs()
	{speed = 0;}
Legs::Legs(int spd)
	{if (spd < 1) {
speed = MIN_SPEED;}
else {speed = spd;}}
int Legs::getSpeed() const
	{return speed;}
Legs& Legs::operator-=(int diff)
{speed -= diff;
if (speed < 1) {
speed = 0;}return *this;}
bool operator>(const Legs& leg1, const Legs& leg2)
{return leg1.getSpeed() > leg2.getSpeed();}
bool operator<(const Legs& leg1, const Legs& leg2)
{return leg1.getSpeed() < leg2.getSpeed();}
bool operator>(const Arms& arm1, const Arms& arm2)
{return arm1.getForce() > arm2.getForce();}
bool operator<(const Arms& arm1, const Arms& arm2)
{return arm1.getForce() < arm2.getForce();
	}
}
