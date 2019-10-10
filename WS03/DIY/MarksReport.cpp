#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "MarksReport.h"
#include "ReportUtils.h"
#include "Mark.h"
using namespace std;

namespace sdds
{
	void MarksReport::initialize()
	{
		strncpy(m_title, "", 70);
	}

	void MarksReport::getMarks()
	{

		char title[70];
		cout << "Enter the report Name: ";
		cin.getline(title, 70); // 1 for null byte


		if (cin.fail())
		{
			cin.clear();
		}

		else {

			strncpy(m_title, title, 70);

		}

		cout << "Enter the number of marks: ";
		cin >> noOfmarks;
		cin.ignore();
		m_mark = new Mark[noOfmarks]; // memory allocation

		cout << "Please enter 3 marks:" << endl;

		for (int i = 0; i < noOfmarks; ++i)
		{

			cout << i + 1 << ": ";
			m_mark[i].readName("Subject Name: ", 6);
			m_mark[i].read("Mark (mark/outof): ");


		}

	}

	void MarksReport::print()
	{
		double result_gpa = 0;
		int lowest = 100;
		int highest = -1;

		cout << "Entry Completed!" << endl;

		cout << endl;

		line(70, '-') << endl;
		cout << m_title << endl;
		line(70, '-') << endl;

		cout << "Marks entered:" << endl;

		for (int i = 0; i < noOfmarks; ++i)
		{
			m_mark[i].set(DSP_LETTER); // Make sure that it will print out the letter 
			m_mark[i].display(66) << endl;
			highest > m_mark[i].percent() ? highest : highest = m_mark[i].percent();
			lowest < m_mark[i].percent() ? lowest : lowest = m_mark[i].percent();
		}

		line(70, '-') << endl;

		line(30, ' ');
		cout << "Lowest Mark";
		line(25, '.');
		cout << "%" << lowest << endl;

		line(30, ' ');
		cout << "Highest mark";
		line(24, '.');
		cout << "%" << highest << endl;

		line(30, ' ');
		cout << "GPA";
		line(33, '.');


		// Add all GPA and divided by the number of marks
		for (int i = 0; i < noOfmarks; ++i)
		{
			result_gpa += m_mark[i].letterBasedGPA();
		}

		result_gpa = result_gpa / noOfmarks;

		cout << setprecision(2) << result_gpa << endl;

	}

	void MarksReport::terminate()
	{
		delete[] m_mark;
	}

}