#include<iostream>
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

	}
	bool Mark::isEmpty()const {
		return(m_displayMode == DSP_UNDEFINED && m_mark == -1 && m_outOf == 100);

	}
	int Mark::percent()const {
		return(m_mark / m_outOf * 100 + 0.5);

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

	ostream& Mark::display() const {
		if (isEmpty()) {
			cout << "Empty Mark object!";
			return cout;
		}
		else {
			if (m_displayMode == DSP_RAW) {
				cout << rawValue();
			}
			else if (m_displayMode == DSP_PERCENT) {
				cout << "%" << percent();
			}
			else if (m_displayMode == DSP_ASIS) {
				cout << m_mark << "/" << m_outOf;
			}
			else if (m_displayMode == DSP_UNDEFINED) {
				cout << "Display mode not set!";
			}
			else
			{
				cout << "Invalid Mark Display setting!";
			}
			return cout;
		}
	}

}