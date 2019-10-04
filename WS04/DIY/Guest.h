#ifndef SDDS_Guest_H__
#define SDDS_Guest_H__
#include <iostream>
namespace sdds {
   class Guest {
      char* m_name;
   public:
      Guest();
      void set(const char* guestName);
      std::ostream& display() const;
      ~Guest();
   };
}
#endif