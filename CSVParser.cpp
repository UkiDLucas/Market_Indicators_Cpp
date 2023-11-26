/**
 * This file contains the implementation of the CSVParser class.
 * @file CSVParser.cpp
 * @author Uki D. Lucas
 * @date 2023-11-25
*/

#include <iostream>
#include <string>
#include <vector>

// for reading CSV data
#include <fstream>
#include <sstream>
#include <cmath>
#include <cmath> // for isnan()
//#include <iomanip>
//#include "tokenizer.cpp"
#include "CSVParser.h" // CSVParser class
#include "Tokenizer.h" // Tokenizer class
#include <vector>


// to cut down on typying "std::" and make code more clear
using namespace std;







void readFilePopulateVector(string relativeFilePath, vector<char> delimiters, vector<MarketIndicator>& marketIndicatiors)
{
    cout << "readFilePopulateVector( " << relativeFilePath  << " )" << endl;
    //     // https://www.coursera.org/learn/cplusplus-crypto-iii/lecture/vqRew/open-a-file
    //     // Create an ifstream object and open the CSV file.
    ifstream file(relativeFilePath); // TODO: hardcoded file name, pass as kwarg

    // check if opening the file was successful
    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return; // Some error -1, not 0
    }

    string line; // a single line of CSV file
    
    // reuse this vector for each line of CSV file
    std::vector<std::string> tokens;
    unsigned int lineCounter = 0;

    // Read each line of the file and split it into individual columns.
    while (getline(file, line)) 
    { 
        lineCounter++;
        // getline returns an istream with eofbit status set if no characters were extracted
        // cout << "CSV file line: " << line << endl;

        Tokenizer tokenizer = Tokenizer( line, delimiters );
        //tokenizer.printTokens();
        tokens = tokenizer.getTokens();

        if(tokens.size() != 7)
        {
            cout << "ERROR in file line " << lineCounter << " : the line has " << tokens.size() << " tokens, expected 7." << endl;
            continue; // skip this line, go to the next one in while loop
        }

//         try{
//             temp_fullName        = tokens[0];    
//             temp_symbol          = tokens[1];
//             temp_originalFileName= tokens[2];
//             temp_dateFormat      = tokens[3] == "YYYY-MM-DD" ? DateFormat::YYYY_MM_DD : DateFormat::MM_DD_YYYY;
//             temp_columnOfInterest= std::stoi(tokens[4]);
//             temp_oldestDate      = tokens[5];
//             temp_csvPathURL      = tokens[6];
//         }catch(const std::exception& e){ // const - cannot change exception, & reference, not copy
//             cout << "ERROR: CSV file line has invalid values, skipping it." << endl;
//             continue; // skip this line, go to the next one in while loop
//         }

//         // add the data from CSV to marketIndicatiors using marketIndicatiors.push_back(marketIndicatiors);
//         marketIndicatiors.push
// {
//     // https://www.coursera.org/learn/cplusplus-crypto-iii/lecture/vqRew/open-a-file
//     // Create an ifstream object and open the CSV file.
//     ifstream file("20200317.csv"); // TODO: hardcoded file name, pass as kwarg

//     // check if opening the file was successful
//     if (!file.is_open()) {
//         cout << "Error: Could not open file." << endl;
//         return -1; // Some error -1, not 0
//     }

//     // Creating variables outside of the while loop to reuse them.
 

//     // Read each line of the file and split it into individual columns.
//     string line;

//     /** Within a line of CSV file, tokens are text separated by comma. */
//     std::vector<std::string> tokens;

//     // https://www.coursera.org/learn/cplusplus-crypto-iii/lecture/vtUz2/read-a-file-using-getline
//     while (getline(file, line)) { // getline returns an istream with eofbit status set if no characters were extracted
//         //cout << "CSV file line: " << line << endl;
//         tokens = tokennize(line, ','); // Tokenize by comma.

//         if(tokens.size() != 5)
//         {
//             cout << "ERROR: CSV file line has " << tokens.size() << " tokens, expected 5." << endl;
//             continue; // skip this line, go to the next one in while loop
//         }

//         try{
//             temp_timestamp = tokens[0];    
//             temp_product   = tokens[1];
//             temp_orderType = tokens[2] == "bid" ? OrderType::bid : OrderType::ask;
//             temp_amount    = tokens[3] != "" ? std::stod(tokens[3]) : 0.0;
//             temp_price     = tokens[4] != "" ? std::stod(tokens[4]) : 0.0;

//             if (temp_amount == 0.0 || temp_price == 0.0)
//             {
//                 cout << "ERROR: CSV file line has missing amount or price." << endl;
//                 continue; // skip this line, go to the next one in while loop
//             }
//         }catch(const std::exception& e){ // const - cannot change exception, & reference, not copy
//             cout << "ERROR: CSV file line has invalid values, skipping it." << endl;
//             continue; // skip this line, go to the next one in while loop
//         }

//         // add the data from CSV to orders using orders.push_back(order);
//         orders.push_back(
//             OrderBookEntry{ 
//                 // constructor order: _price, _amount, _timestamp, _orderBookType, _product
//                 temp_price, 
//                 temp_amount, 
//                 temp_timestamp, 
//                 temp_orderType, 
//                 temp_product
//             }
//         );
    }

    // Close the CSV file.
    file.close();
     return;
}



/** This is the constructor for the class. 
 */
CSVParser::CSVParser(string relativeFilePath, vector<char> delimiters)
{
    cout << "CSVParser constructor called with " << relativeFilePath  << endl;

    string text = "token1, token2, token3 , ";
    Tokenizer tokenizer = Tokenizer( text, delimiters );
    tokenizer.printTokens();

    vector<MarketIndicator> marketIndicatiors;
    readFilePopulateVector(relativeFilePath, delimiters, marketIndicatiors);  
}

