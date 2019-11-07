#define _CRT_SECURE_NO_WARNINGS

#include "RobotSquad.h"
#include "Robot.h"
#include<iostream>
#include<string.h>

using namespace sdds;
using namespace std;
// RobotSquad.cpp
sdds::RobotSquad::RobotSquad()
{this->count = 0;
	this->robots = nullptr;
	this->name = new char[8];
	strcpy(this->name, "No Name");}
sdds::RobotSquad::RobotSquad(const char* squadName)
{if (squadName == nullptr || squadName[0] == '\0') {
		RobotSquad();}
else {int nameLength = strlen(squadName);
	this->name = new char[nameLength + 1];
strncpy(this->name, squadName, nameLength + 1);
this->count = 0;
		this->robots = nullptr;}}
Robot* sdds::RobotSquad::getRoster()
{return this->robots;}
void sdds::RobotSquad::operator--()
{if (count == 0) {
cout << "This squad **" << name << "** has no members or is uninitialized. Can't do --." << endl;
		return;}
	if(count - 1 == 0){
		delete[] robots;
		count-=1;
		robots = nullptr;
		return;}
	else {int i = 0;
Robot* newRoster = new Robot[count - 1];
for (i = 0; i < count - 1; i++) {
newRoster[i] = robots[i];}
		delete[] robots;
		robots = new Robot[count - 1];
		for (i = 0; i < count - 1; i++) {
			robots[i] = newRoster[i];}
		count-=1;
		delete[] newRoster;}}
void sdds::RobotSquad::operator+=(Robot& robot)
{Robot *newRoster = new Robot[count + 1];
	int i;
	if (count != 0) {
		for (i = 0; i < count ; i++) {
newRoster[i] = robots[i];}}
	newRoster[count] = robot;
	delete[] robots;
	robots = new Robot[count + 1];
	for (i = 0; i < count + 1; i++) {
		robots[i] = newRoster[i]}
	delete[] newRoster;
	count+=1;}
std::ostream& sdds::RobotSquad::display()const
{if (count == 0) {
cout << "Squad **" << name << "** has no members" << endl;
return cout;}
cout << "***Squad Summary***" << endl;
cout << "Name: " << name << endl;
cout << "Roster Count: " << count << endl;
	cout << "Roster:" << endl;
int i;
for (i = 0; i < count; i++) {
robots[i].display();}
	return cout;
}
