// Robot.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Robot.h"
#include"Parts.h"
using namespace std;
namespace sdds
{
	Robot::Robot() {
		nickname[0] = '\0';
		durability = 0;
		arms = Arms();
		legs = Legs();}
Robot::Robot(const char* nk_name, int a_force, 
	int speed, int r_durability)
	{int length = strlen(nk_name);
if (nk_name == nullptr || nk_name[0] == '\0') {
			Robot();}
else {
if (r_durability < 1)
 r_durability = 100;
 durability = r_durability;
 arms = Arms(a_force);
 legs = Legs(speed);
 if (length > NICK_MAX_LEN)
 length = NICK_MAX_LEN;
 strcpy(nickname, nk_name);
 nickname[NICK_MAX_LEN] = '\0';}}
	ostream& Robot::display() const {
if (nickname[0] != '\0' && durability != 0) {
cout << "***Robot Summary***" << endl;
cout << "Nickname: " << nickname << endl;
cout << "Arm Power: " << arms.getForce() << endl;
cout << "Durability: " << durability << endl;
cout << "Legs: " << legs.getSpeed() << endl;}
		else
cout << "This Robot isn't operational" << endl;
return cout;}
	Robot::operator bool() const {
bool valid = false;
if (nickname == nullptr || durability == 0)
valid = true;
return valid;}
Arms Robot::getArms() const
	{
		return arms;
	}
Legs Robot::getLegs() const
	{
		return legs;
	}
	
Robot& Robot::operator-=(int diff)
	{
		durability -= diff;
		if (durability < 1) {
			durability = 0;}
		return *this}
void box(Robot& robot1, Robot& robot2)
	{
cout << "Attempting to begin a Robot boxing match" << endl;
if (robot1 || robot2) {
cout << "At least one of the Robots isn't " << endl;
			return;		}
cout << "Both participants are operational.." << endl;
while (!robot1 && !robot2) {
if (robot1.getLegs() > robot2.getLegs()) {
	robot2 -= robot1.getArms().getForce();
		if (!robot2) {
robot1 -= robot2.getArms().getForce();}}
			else {
robot1 -= robot2.getArms().getForce();		
				if (!robot1) {
					robot2 -= robot1.getArms().getForce();}}
cout << "The bout has concluded... the winner is: " << endl;
if (robot1) {
	robot2.display();
		}
		else {
			robot1.display();
		}
	}
}