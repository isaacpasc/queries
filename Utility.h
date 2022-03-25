//
// Created by cse310 on 3/3/22.
//

#ifndef PROJECT_2_UTILITY_H
#define PROJECT_2_UTILITY_H
#include <string>
#include "defns.h"
void BUILD_MAX_ARR(std::string, SOC*);
int getIntFromString(std::string);
int findLengthOfHeapArr(std::string);
std::string formatWithCommas(int);
std::string findRatio(earnings*, int);
void BUILD_EARNINGS_ARR(earnings*);
bool testForPrime(int);
int getHashMapArrLength(std::string);
void inorderBuildHashTable(bst*, hash_table_entry**, int);
int socCodeToInt(std::string);
std::string intToSOCCode(int);
std::string getQuotedRange(std::string, bool);
#endif //PROJECT_2_UTILITY_H
