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
        /**
        * Constructor.
        ** @input: text to be splitted into tokens,
        ** @input: a vector of delimiters   
        */
        Tokenizer();

        // public methods

        /** prints tokens to console */
        void printTokens(std::vector<std::string> tokens);
    
        /** 
         ** @input: text to be slipped into tokens,
        ** @input: a single  delimiter, the delimiters could be multi-character text,
        ** @output: vector of string tokens
        **/
        vector<string> extractTokens( string text, char delimiter );

    private:
        // member variables
        /** class holder of the tokens */
        //std::vector<std::string> tokens;

        // private methods



};