/**
 * This is a header file, or the specification, 
 * represent functions used in parsing CSV files with market indicators.
 * @authors Uki D. Lucas
 * @date 2023-11-25
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

/** This interface is intended for any implementation of CSV parser */
class CSVParser
{
    public:

        // constructor declaration
        CSVParser( 
            string          _relativeFilePath
        );

        // public methods
        string          run();

    private:
        // member variables
            string          _relativeFilePath;
};