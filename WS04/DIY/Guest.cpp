#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Guest.h"
#include "utils.h"
using namespace std;
namespace sdds {
   Guest::Guest() {
      m_name = nullptr;
   }
   void Guest::set(const char* value) {
      delete[] m_name;
      m_name = new char[strlen(value) + 1];
      strcpy(m_name, value);
   }
   Guest::~Guest() {
      delete[] m_name;
   }
   ostream& Guest::display() const{
      return cout << (m_name ? m_name : "No Name");
   }
}
