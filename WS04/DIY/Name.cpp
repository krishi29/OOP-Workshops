#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Guest.h"
#include "utils.h"
using namespace std;
namespace sdds {
   Name::Name() {
      m_data = nullptr;
   }
   void Name::set(const char* value) {
      delete[] m_data;
      m_data = new char[strlen(value) + 1];
      strcpy(m_data, value);
      return *this;
   }
   Name::~Name() {
      delete[] m_data;
   }
   ostream& Name::display() const{
      return cout << (m_data ? m_data : "No Name");
   }
}
