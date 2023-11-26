/**
 * This is a header class file, or the specification, 
 * represent APi for extracting tokens from the text.
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
#include <vector>

using namespace std;

/** This interface is intended for any implementation of CSV parser */
class Tokenizer
{
    public:
        // constructor declaration
        Tokenizer();

        // public methods
        
        /** 
         * Function that takes parameters:
         * text, 
         * and vector of delimiter, the delimiters could be multi-character text,
         * splits the text into tokens and returns them as a vector.
         **/
        vector<string> getTokens( string text, vector<char> delimiters );

    private:
        // member variables
};