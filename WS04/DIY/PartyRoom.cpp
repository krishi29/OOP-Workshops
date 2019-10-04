#include <iostream>
#include "PartyRoom.h"
using namespace std;
namespace sdds {
   PartyRoom::PartyRoom(int roomNumber, int maxNoOfGuestsInRoom) {
      m_guests = new Guest[maxNoOfGuestsInRoom];
      m_noOfGuests = 0;
      m_roomNumber = roomNumber;
      m_maxNoOfGuests = maxNoOfGuestsInRoom;
   }
   bool PartyRoom::add(const char* guestName) {
      bool success = false;
      if (m_noOfGuests < m_maxNoOfGuests) {
         m_guests[m_noOfGuests++].set(guestName);
         success = true;
      }
      return success;
   }
   ostream& PartyRoom::display()const {
      cout << "Party Room Number: " << m_roomNumber << endl;
      cout << "Capacity: " << m_maxNoOfGuests << " guests" << endl;
      cout << "Number of empty seats: " << m_maxNoOfGuests - m_noOfGuests << endl;
      cout << "Guest list: " << endl;
      for (int i = 0; i < m_noOfGuests; i++) {
         cout << (i + 1) << ": ";
         m_guests[i].display() << endl;
      }
      return cout;
   }
   PartyRoom::~PartyRoom() {
      delete[] m_guests;
   }
}

/*
Party Room 244
(A)dd Guest
(G)uest List
e(X)it
> a
Guest name: John Doe
(A)dd Guest
(G)uest List
e(X)it
> a
Guest name: Jane Dee
(A)dd Guest
(G)uest List
e(X)it
> g
Party Room Number: 244
Capacity: 5 guests
Number of empty seats: 3
Guest list:
1: John Doe
2: Jane Dee
(A)dd Guest
(G)uest List
e(X)it
*/