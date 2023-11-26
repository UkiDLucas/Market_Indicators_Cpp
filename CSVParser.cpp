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
#include "MarketIndicator.cpp" 

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

    Tokenizer tokenizer = Tokenizer();

    // Read each line of the file and split it into individual columns.
    while (getline(file, line)) 
    { 
        lineCounter++;
        // getline returns an istream with eofbit status set if no characters were extracted
        // cout << "CSV file line: " << line << endl;

        //tokenizer.printTokens();
        tokens = tokenizer.extractTokens(line, delimiters[0]); 

        if(tokens.size() != 7)
        {
            cout << "ERROR in file line " << lineCounter << " : the line has " << tokens.size() << " tokens, expected 7." << endl;
            continue; // skip this line, go to the next one in while loop
        }

        string          temp_fullName;
        string          temp_symbol;
        string          temp_originalFileName;
        DateFormat      temp_dateFormat;
        unsigned int    temp_columnOfInterest;
        string          temp_oldestDate;
        string          temp_csvPathURL;

        try
        {
            temp_fullName           = tokens[0];    
            temp_symbol             = tokens[1];
            temp_originalFileName   = tokens[2];
            temp_dateFormat         = DateFormat::YYYY_MM_DD_dashes;
            temp_columnOfInterest   = std::stoi(tokens[4]); // stoi() converts string to int
            temp_oldestDate         = tokens[5];    
            temp_csvPathURL         = tokens[6];
        }catch(const std::exception& e){ // const - cannot change exception, & reference, not copy
            cout << "ERROR in CSV line " << lineCounter << " the line has invalid values, skipping it." << endl;
            continue; // skip this line, go to the next one in while loop
        }

//         // add the data from CSV to orders using orders.push_back(order);
        marketIndicatiors.push_back(
            MarketIndicator{
                // constructor order: _price, _amount, _timestamp, _orderBookType, _product
                temp_fullName,
                temp_symbol,
                temp_originalFileName,
                temp_dateFormat,
                temp_columnOfInterest,
                temp_oldestDate,
                temp_csvPathURL
            } // end of MarketIndicator constructor
        );
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


    vector<MarketIndicator> marketIndicatiors;
    readFilePopulateVector(relativeFilePath, delimiters, marketIndicatiors); 
    
    cout << " =============== " << endl;
    cout << "Populated " << marketIndicatiors.size() << " MarketIndicators!" << endl;

    cout << " =============== " << endl;
    cout << "Printing ID: 3: " << endl;
    cout << "temp_fullName : "          << marketIndicatiors[3].getFullName()           << endl;
    cout << "temp_symbol : "            << marketIndicatiors[3].getSymbol()             << endl;
    cout << "temp_originalFileName : "  << marketIndicatiors[3].getOriginalFileName()   << endl;
    //cout << "temp_dateFormat : "        << marketIndicatiors[3].getDateFormat()         << endl;
    cout << "temp_columnOfInterest : "  << marketIndicatiors[3].getColumnOfInterest()   << endl;
    cout << "temp_oldestDate : "        << marketIndicatiors[3].getOldestDate()         << endl;
    cout << "temp_csvPathURL : "        << marketIndicatiors[3].getCsvPathURL()         << endl;
}


