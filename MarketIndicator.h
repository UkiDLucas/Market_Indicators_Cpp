/**
 * This is a header file, or the specification, 
 * represents a single row of data.
 * @authors Uki D. Lucas
*/
#pragma once 

// Enable C++11 standard
#define _GLIBCXX_USE_CXX11_ABI 1
// make sure that the compiler supports C++11 standard
#if __cplusplus < 201103L
    #error This code requires at least C++11 standard
#endif

#include <string>
#include "DateFormat.h" // DateFormat enum class
using namespace std;

class MarketIndicator
{
    public:

        // constructor declaration
        MarketIndicator( 
            string          fullName,
            string          symbol,
            string          originalFileName,
            DateFormat      dateFormat,
            unsigned int    columnOfInterest,
            string          oldestDate, // might convert to object if needed
            string          csvPathURL 
        );

        // accessor methods
        string          getFullName();
        string          getSymbol();
        string          getOriginalFileName();
        DateFormat      getDateFormat();
        unsigned int    getColumnOfInterest();
        string          getOldestDate();
        string          getCsvPathURL();

    private:
        // member variables
        string          _fullName;
        string          _symbol;
        string          _originalFileName;
        DateFormat      _dateFormat;
        unsigned int    _columnOfInterest;
        string          _oldestDate; // might convert to object if needed
        string          _csvPathURL;
};