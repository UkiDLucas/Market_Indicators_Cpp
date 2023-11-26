/** 
 * This application reads CSV file market_indicators.csv
 * 
*/
#include <iostream> // for cout, endl

// to cut down on typying "std::"
using namespace std;

#include "CSVParser.h" // 

int main()
{  
    // to know executable updated:
    cout << "Application version: ==== 1 ==== "<< endl;

    // https://github.com/UkiDLucas/MarketIndicators.jl/blob/9b2690b300819214dd4b84a0401feeb4ef903797/src/DATA/Indicators.csv
    // vector<char> delimiters = {',', ' '};
    CSVParser parser = CSVParser("Indicators.csv", {','}); // comma delimited file

    // TODO make some GUI

    return 0;
}