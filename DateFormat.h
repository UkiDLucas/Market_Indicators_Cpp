/**
 * This is a header file, or the specification, 
 * represents different date formats that can be encountered in CSV files.
 * @authors Uki D. Lucas
*/
#pragma once 

// Enable C++11 standard
#define _GLIBCXX_USE_CXX11_ABI 1
// make sure that the compiler supports C++11 standard
#if __cplusplus < 201103L
    #error This code requires at least C++11 standard
#endif



/**
 ** This enumerator gives you commonly used date formats.
 ** "yyyy-mm-dd" example 1927-12-30 computer friendly 
 ** "mm/dd/yyyy" example 12/30/1927 USA style 
 ** "dd.mm.yyyy" example 30.12.1927 European style
 **/
enum class DateFormat {
    // This enumerator is a C++11 feature.

    /** "yyyy-mm-dd" example 1927-12-30 computer friendly */
    YYYY_MM_DD_dashes,  // 

    /** "dd/mm/yyyy" example 30/12/1927 USA style */
    MM_DD_YYYY_slashes, // 

    /** "dd.mm.yyyy" example 30.12.1927 European style */
    DD_MM_YYYY_dots,    // 
};