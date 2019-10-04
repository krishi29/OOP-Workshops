#include <iostream>
#include "PartyRoom.h"
#include "Guest.h"
#include "utils.h"
using namespace std;
using namespace sdds;
char menu() {
   char ch;
   do {
      cout << "(A)dd Guest" << endl;
      cout << "(G)uest List" << endl;
      cout << "e(X)it" << endl << "> ";
      ch = cin.get();
      flushKeyboard();
   } while (ch != 'A' && ch != 'a' && ch != 'G' && ch != 'g' && ch != 'X' && ch != 'x' &&
      cout << "Invalid input!" << endl);
   return ch;
}
int main() {
   char name[71];
   char ch;
   PartyRoom pr(244, 5);
   cout << "Party Room 244" << endl;
   do {
      switch (ch = menu()){
      case 'A':
      case 'a':
         cout << "Guest name: ";
         read(name, 70, "Guest name is too long, retry: ");
         if (!pr.add(name)) {
            cout << "Sorry " << name << " party room 244 is full!" << endl;
         }
         break;
      case 'G':
      case 'g':
         pr.display();
         break;
      }
   }while(ch != 'x' && ch != 'X');
   cout << "Goodbye! " << endl;
   cout << "Before leaving, lets test an empty name: ";
   Guest G;
   G.display() << endl;
   cout << "Done!" << endl;
   return 0;
}