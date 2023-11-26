
#include "Tokenizer.h"
#include <string>
#include <vector>
#include <iostream>



/** Constructor.
 * @input: text to be splitted into tokens,
 * @input: a vector of delimiters
 * This constructor actually does the tokenizing,
 * and populates the tokens vector, a member variable.
*/
Tokenizer::Tokenizer(string text, vector<char> delimiters)
{
    std::cout << "Tokenizer constructor called with: " << std::endl;
    std::cout << "TEXT: " << text << std::endl;


    unsigned int delimiterCounter = 0;
    vector<string> tokens0 = extractTokens( text, delimiters.at(delimiterCounter));
}


void Tokenizer::printTokens()
{
        int counter = 0;
    // pass by reference
    for (std::string& token : tokens)
    {
        counter++;
        std::cout << counter << " token \"" << token << "\" " << std::endl;
    }
}




std::vector<std::string> Tokenizer::getTokens(std::string originalText, vector<char> delimiters)
{   
    std::vector<std::string> tokens;

    /** The index could be negative. */
    signed int start, end;
    /** Temporary token. */
    std::string token;
    /** Begining index of the token. */
    start = originalText.find_first_not_of(delimiter, 0); // start at the first NOT separator
    //std::cout   << "csvLine :" << csvLine << std::endl;

    do{
        end = originalText.find_first_of(delimiter, start + 1);
        //std::cout << "-start "  << start    << std::endl;
        //std::cout << "-end "    << end      << std::endl;

        if (start >= originalText.length() || start == end) 
            break;
        if (end >= 0) // found token
            token = originalText.substr(start, end-start);
        else{
            token = originalText.substr(start, originalText.length() - start);
        }
        // std::cout   << " token \"" << token 
        //     << "\", start " << start 
        //     << ", end "  << end
        //     << std::endl;
            
        if (token.compare(std::string(1, delimiter)) == 0) // ugly C++ coparison
        {
            start = start + 1;
        }
        else
        {
            tokens.push_back(token);
        }
        // Move start to the next position after end.
        start = end + 1;
    // The npos is returned if nothing is found.
    } while (end > 0); // return -1 //end != std::string::npos
    return tokens;
}

// TODO convert to a unit test
// int main()
// {
//     // local version of tokens:
//     std::vector<std::string> tokens;

//     std::string text = "     token_1,,,,, . token_2 , token_3,       ";
//     text = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";
//     //tokens = tokennize(text, ' '); // Tokenize by space.
//     vector<char> delimiters = {',', ' '};
//     tokens = Tokenizer::getTokens(text, delimiters);

//     int counter = 0;
//     // pass by reference
//     for (std::string& token : tokens)
//     {
//         counter++;
//         std::cout << counter << " token \"" << token << "\" " << std::endl;
//     }

//     return 0;
// }

