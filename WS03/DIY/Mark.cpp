#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Mark.h"
using namespace std;

namespace sdds {
	void Mark::flushKeyboard()const {
		char ch;
		do {
			ch = cin.get();
		} while (ch != '\n');
	}

	void Mark::set(int diaplayMode) {
		m_displayMode = diaplayMode;
	}

	void Mark::set(double mark, int outOf) {
		m_mark = mark;
		m_outOf = outOf;
	}

	void Mark::setEmpty() {
		m_displayMode = DSP_UNDEFINED;
		m_mark = -1;
		m_outOf = 100;
		strcpy(m_name, "");

	}

	bool Mark::isEmpty()const {
		return (m_mark == -1);
	}

	int Mark::percent()const
	{
		return(m_mark / (double)m_outOf * 100 + 0.5);
	}

	double Mark::rawValue()const {
		return(m_mark / m_outOf);

	}
	bool Mark::read(const char* prompt) {
		bool flag = true;
		cout << prompt;
		cin >> m_mark;
		cin.ignore();
		cin >> m_outOf;
		if (cin.fail()) {
			cin.clear();
			setEmpty();
			flag = false;
		}
		flushKeyboard();
		return flag;
	}
	ostream& Mark::display(int width) const {
		if (isEmpty()) {
			cout << "Empty Mark object!";
		}
		else {
			if (m_name[0] != '\0') {
				cout.fill('.');
				cout.width(width);
				cout.setf(ios::left);
				cout << m_name;
			}
			if (m_displayMode == DSP_RAW) {
				cout.precision(2);
				cout << rawValue();
			}
			else if (m_displayMode == DSP_PERCENT) {
				cout << "%" << percent();
			}
			else if (m_displayMode == DSP_ASIS) {
				cout.precision(1);
				cout.setf(ios::fixed);
				cout << m_mark << "/" << m_outOf;
			}
			else if (m_displayMode == DSP_LETTER) {
				prnLetter();
			}
			else if (m_displayMode == DSP_GPA) {
				cout.precision(1);
				cout.setf(ios::fixed);
				cout << GPA();
			}
			else if (m_displayMode == DSP_UNDEFINED) {
				cout << "Display mode not set!";
			}
			else
				cout << "Invalid Mark Display setting!";
		}
		return cout;
	}
	void Mark::prnLetter()const {
		if (!isEmpty()) {

			int percentage = percent();
			if (percentage >= 90 && percentage <= 100)
				cout << "A+";
			else if (percentage >= 80 && percentage <= 89)
				cout << "A";
			else if (percentage >= 75 && percentage <= 79)
				cout << "B+";
			else if (percentage >= 70 && percentage <= 74)
				cout << "B";
			else if (percentage >= 65 && percentage <= 69)
				cout << "C+";
			else if (percentage >= 60 && percentage <= 64)
				cout << "C";
			else if (percentage >= 55 && percentage <= 59)
				cout << "D+";
			else if (percentage >= 50 && percentage <= 54)
				cout << "D";
			else if (percentage <= 49 && percentage >= 0)
				cout << "F";
			else if (percentage > 100)
				cout << "?";
		}

	}
	void Mark::set(const char* name) {
		strcpy(m_name, name);
	}
	void Mark::set(const char* name, double rawMark, int outof) {
		set(name);
		set(rawMark, outof);
	}
	bool Mark::readName(const char* prompt, int maxLen) {
		cout << prompt;
		if (maxLen > 50)
			maxLen = 50;
		//cin >> m_name[51];
		cin.getline(m_name, maxLen + 1);
		if (cin.fail()) {
			cin.clear();
			flushKeyboard();
			setEmpty();
			return false;
		}
		return true;
	}
	void Mark::changeOutOf(int value) {
		m_mark = m_mark * (double)value / m_outOf;
		if (m_mark < 1)
			m_mark = -1;
		m_outOf = value;
	}
	double Mark::GPA()const {
		return (rawValue() * 4);
	}
	double Mark::letterBasedGPA()const {
		int percentage = percent();
		if (percentage >= 90 && percentage <= 100)
			return 4.0;
		else if (percentage >= 80 && percentage <= 89)
			return 4.0;
		else if (percentage >= 75 && percentage <= 79)
			return 3.5;
		else if (percentage >= 74 && percentage <= 70)
			return 3.0;
		else if (percentage >= 69 && percentage <= 65)
			return 2.5;
		else if (percentage >= 64 && percentage <= 60)
			return 2.0;
		else if (percentage >= 59 && percentage <= 55)
			return 1.5;
		else if (percentage >= 54 && percentage <= 50)
			return 1.0;
		else
			return 0.0;
	}

}