/***********************************************************************
// OOP244 Workshop 4: read functions for foolproof integer and C string
//                    data entry, copy function for DMA of C strings
// File	utils.h
// Version 1.1
// Date	2019/09/26
// Author	Fardad Soleimanloo, Hong Zhan (Michael) Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Guest            Date            Reason
// Fardad
// Michael         Sept 26 2019    Added a copystr function for Cstring DMA
//                                 Updated cstring read to account for empty strings
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {

   void flushKeyboard();
	// reads an integer from console the integer referenced by "val"
	// argument.
	// if the user enters an invalid integer or values outside of the 
	// boundries set by "min" or "max" , this function flushes the 
	//keyboard, prints the "errorMessage and reads again
	// untill user enters an acceptable integer

	void read(int& val, int min, int max, const char* errorMessage = "");

	// reads a C style string from console up to "len" characters into the
	// the string pointed by the "str" pointer
	// if the user enters more than "len" characters, this function
	// flushes the keyboard, prints the "errorMessage and reads again
	// untill user enters an acceptable string

	void read(char* str, int len, const char* errorMessage = "");
}

#endif