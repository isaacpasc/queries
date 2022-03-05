//
// Created by cse310 on 3/3/22.
//

#include "Utility.h"
#include <fstream>
#include <sstream>
#include <iostream>

void BUILD_MAX_ARR(std::string year, SOC* heapArr) {
    std::ifstream inFile;
    std::string fileName = "Occupation-Dist-All-" + year + ".csv";
    inFile.open(fileName);
    std::string line;

    // skip 5 lines
    for (int i = 0; i < 1; i++) {
        std::getline(inFile, line);
    }

    int subIndex = 0;
    int index = 0;

    // parse csv, line by line
    while(inFile.good()) {
        std::getline(inFile, line);

        // parse csv, character by character
        bool insideQuote = false;
        std::string finalCell;
        for(int i = 0; i < line.length(); i++) {

            // check if end of line
            if (i == line.length() - 1) {
                if (subIndex == 0) {
                    for (int j = 0; j < finalCell.length(); j++) {
                        heapArr[index].occupation[j] = finalCell[j];
                    }
                }
                if (subIndex == 1) {
                    for (int j = 0; j < finalCell.length(); j++) {
                        heapArr[index].SOC_code[j] = finalCell[j];
                    }
                }
                if (subIndex == 2) {
                    heapArr[index].total = getIntFromString(finalCell);
                }
                if (subIndex == 3) {
                    heapArr[index].female = getIntFromString(finalCell);
                }
                if (subIndex == 4) {
                    heapArr[index].male = getIntFromString(finalCell);
                    subIndex = -1;
                }
                subIndex++;
                finalCell = "";
                continue;
            }

            // if hit a quote, toggle insideQuote
            if(line[i] == '"') {
                if (insideQuote) {
                    insideQuote = false;
                } else {
                    insideQuote = true;
                }
                continue;
            }

            if (!insideQuote) {
                if (line[i] == ',') {
                    if (subIndex == 0) {
                        for (int j = 0; j < finalCell.length(); j++) {
                            heapArr[index].occupation[j] = finalCell[j];
                        }
                    }
                    if (subIndex == 1) {
                        for (int j = 0; j < finalCell.length(); j++) {
                            heapArr[index].SOC_code[j] = finalCell[j];
                        }
                    }
                    if (subIndex == 2) {
                        heapArr[index].total = getIntFromString(finalCell);
                    }
                    if (subIndex == 3) {
                        heapArr[index].female = getIntFromString(finalCell);
                    }
                    if (subIndex == 4) {
                        heapArr[index].male = getIntFromString(finalCell);
                        subIndex = -1;
                    }
                    subIndex++;
                    finalCell = "";
                    continue;
                } else {
                    finalCell += line[i];
                }
            } else {
                finalCell += line[i];
            }
        }
        index++;
    }
    inFile.close();
}

int getIntFromString(std::string str) {
    std::stringstream ss(str);
    std::string tmp;
    while (ss.good()) {
        std::string substr;
        getline(ss, substr, ',');
        tmp += substr;
    }
    int num;
    std::stringstream n;
    n << tmp;
    n >> num;
    return num;
}

int findLengthOfHeapArr(std::string year) {
    std::ifstream inFile;
    std::string fileName = "Occupation-Dist-All-" + year + ".csv";
    int rowCount = 0;
    inFile.open(fileName);

    while(!inFile.eof()) {
        std::string line;
        getline(inFile, line);
        rowCount ++;
    }

    inFile.close();
    return rowCount - 1;
}

std::string formatWithCommas(int num) {
    std::string s = std::to_string(num);
    for( int i = s.size() - 3; i > 0; i -= 3 )
    {
        s.insert(  s.begin() + i, ',' );
    }
    return s;
}

void BUILD_EARNINGS_ARR(earnings* earningsArr) {
    std::ifstream inFile;
    std::string fileName = "Earnings-1960-2019.csv";
    inFile.open(fileName);
    std::string line;

    // skip 8 lines
    for (int i = 0; i < 1; i++) {
        std::getline(inFile, line);
    }

    int subIndex = 0;
    int index = 0;

    // parse csv, line by line
    while(inFile.good()) {
        std::getline(inFile, line);

        // parse csv, character by character
        bool insideQuote = false;
        std::string finalCell;
        for(int i = 0; i < line.length(); i++) {

            // check if end of line
            if (i == line.length() - 1) {
                if (subIndex == 0) {
                    earningsArr[index].year = getIntFromString(finalCell);
                }
                if (subIndex == 1) {
                    earningsArr[index].male_total = getIntFromString(finalCell);
                }
                if (subIndex == 2) {
                    earningsArr[index].male_with_earnings = getIntFromString(finalCell);
                }
                if (subIndex == 3) {
                    earningsArr[index].male_earnings = getIntFromString(finalCell);
                }
                if (subIndex == 4) {
                    earningsArr[index].male_earnings_moe = getIntFromString(finalCell);
                }
                if (subIndex == 5) {
                    earningsArr[index].female_total = getIntFromString(finalCell);
                }
                if (subIndex == 6) {
                    earningsArr[index].female_with_earnings = getIntFromString(finalCell);
                }
                if (subIndex == 7) {
                    earningsArr[index].female_earnings = getIntFromString(finalCell);
                }
                if (subIndex == 8) {
                    earningsArr[index].female_earnings_moe = getIntFromString(finalCell);
                    subIndex = -1;
                }
                subIndex++;
                finalCell = "";
                continue;
            }

            // if hit a quote, toggle insideQuote
            if(line[i] == '"') {
                if (insideQuote) {
                    insideQuote = false;
                } else {
                    insideQuote = true;
                }
                continue;
            }

            if (!insideQuote) {
                if (line[i] == ',') {
                    if (subIndex == 0) {
                        earningsArr[index].year = getIntFromString(finalCell);
                    }
                    if (subIndex == 1) {
                        earningsArr[index].male_total = getIntFromString(finalCell);
                    }
                    if (subIndex == 2) {
                        earningsArr[index].male_with_earnings = getIntFromString(finalCell);
                    }
                    if (subIndex == 3) {
                        earningsArr[index].male_earnings = getIntFromString(finalCell);
                    }
                    if (subIndex == 4) {
                        earningsArr[index].male_earnings_moe = getIntFromString(finalCell);
                    }
                    if (subIndex == 5) {
                        earningsArr[index].female_total = getIntFromString(finalCell);
                    }
                    if (subIndex == 6) {
                        earningsArr[index].female_with_earnings = getIntFromString(finalCell);
                    }
                    if (subIndex == 7) {
                        earningsArr[index].female_earnings = getIntFromString(finalCell);
                    }
                    if (subIndex == 8) {
                        earningsArr[index].female_earnings_moe = getIntFromString(finalCell);
                        subIndex = -1;
                    }
                    subIndex++;
                    finalCell = "";
                    continue;
                } else {
                    finalCell += line[i];
                }
            } else {
                finalCell += line[i];
            }
        }
        index++;
    }
    inFile.close();
}

std::string findRatio(earnings* earningsArr, int year) {
    int i = 2019 - year;
    return std::to_string((float)earningsArr[i].female_earnings/(float)earningsArr[i].male_earnings);
}
