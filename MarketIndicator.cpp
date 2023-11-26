/**
 * This is a header file, or the specification, 
 * represents a single row of data.
 * @authors Uki D. Lucas
*/
//#pragma once 

// Enable C++11 standard
#define _GLIBCXX_USE_CXX11_ABI 1
// make sure that the compiler supports C++11 standard
#if __cplusplus < 201103L
    #error This code requires at least C++11 standard
#endif

#include <string>
#include "DateFormat.h" // DateFormat enum class
#include "MarketIndicator.h"

using namespace std;

// constructor declaration
MarketIndicator::MarketIndicator( 
    string          fullName,
    string          symbol,
    string          originalFileName,
    DateFormat      dateFormat,
    unsigned int    columnOfInterest,
    string          oldestDate, // might convert to object if needed
    string          csvPathURL 
)
{
    _fullName           = fullName;
    _symbol             = symbol;
    _originalFileName   = originalFileName;
    _dateFormat         = dateFormat;
    _columnOfInterest   = columnOfInterest;
    _oldestDate         = oldestDate;
    _csvPathURL         = csvPathURL;       

};

// accessor methods
string          MarketIndicator::getFullName(){             return _fullName; };
string          MarketIndicator::getSymbol(){               return _symbol; };  
string          MarketIndicator::getOriginalFileName(){     return _originalFileName; };
DateFormat      MarketIndicator::getDateFormat(){           return _dateFormat; };
unsigned int    MarketIndicator::getColumnOfInterest() {    return _columnOfInterest; };
string          MarketIndicator::getOldestDate(){           return _oldestDate; };
string          MarketIndicator::getCsvPathURL(){           return _csvPathURL; };

// member variables
// string          _fullName;
// string          _symbol;
// string          _originalFileName;
// DateFormat      _dateFormat;
// unsigned int    _columnOfInterest;
// string          _oldestDate; // might convert to object if needed
// string          _csvPathURL;

