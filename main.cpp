#include "defns.h"
#include "Utility.h"
#include "MaxHeap.h"
#include "BinarySearchTree.h"
#include "HashTable.h"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc == 2) {

        bool isFirstQuery = true;
        bool isLastQuery = false;

        // read from stdin
        int k = 0; // number of query

        // create earnings array
        struct earnings earningsArr[60];
        BUILD_EARNINGS_ARR(earningsArr);

        // create hashmap and bst
        int m = getHashMapArrLength(argv[1]);
        hash_table_entry* hashTable[m];
        for (int i = 0; i < m; i++) {
            hashTable[i] = nullptr;
        }
        bst* bstRoot = BUILD_BST(argv[1]);
        inorderBuildHashTable(bstRoot, hashTable, m);



        for (std::string line; std::getline(std::cin, line);) {
            if (line.substr(0,4) == "find") {
                if (line.substr(5,3) == "max") {
                    int id = 1;
                    int count = 0;
                    if (line.substr(9,4) == "male") { // find max men query
                        id = 3;
                        count = getIntFromString(line.substr(14, line.length() - 14));

                        // echo query
                        std::cout << "Query: find max male " << count << "\n" << std::endl;
                        std::cout << "Top " << count << " occupations in " << argv[1] << " for male workers:" << std::endl;
                    } else if (line.substr(9,6) == "female") { // find max women query
                        id = 2;
                        count = getIntFromString(line.substr(16, line.length() - 16));

                        // echo query
                        std::cout << "Query: find max female " << count << "\n" << std::endl;
                        std::cout << "Top " << count << " occupations in " << argv[1] << " for female workers:" << std::endl;
                    } else if (line.substr(9,5) == "total") { // find max total query
                        id = 1;
                        count = getIntFromString(line.substr(15, line.length() - 15));

                        // echo query
                        std::cout << "Query: find max total " << count << "\n" << std::endl;
                        std::cout << "Top " << count << " occupations in " << argv[1] << " for total workers:" << std::endl;
                    }

                    // begin max query
                    int n = findLengthOfHeapArr(argv[1]);
                    SOC array[n]; //create in for loop, deletes each iteration
                    SOC* heapArr = array;
                    BUILD_MAX_ARR(argv[1], heapArr);
                    BUILD_MAX_HEAP(heapArr, n, id);

                    for (int i = 0; i < count; i++) {
                        std::cout << "\t";
                        SOC tmp = DELETE_MAX(heapArr, n, id);
                        std::cout << tmp.occupation;
                        std::cout << ": ";

                        if (id == 1) { // total
                            std::cout << formatWithCommas(tmp.total) << std::endl;
                        }
                        if (id == 2) { // female
                            std::cout << formatWithCommas(tmp.female) << std::endl;
                        }
                        if (id == 3) { // male
                            std::cout << formatWithCommas(tmp.male) << std::endl;
                        }
                    }

                } else if (line.substr(5,5) == "ratio") { // find ratio query

                    int startYear = getIntFromString(line.substr(11, 4));
                    int endYear = getIntFromString(line.substr(16, 4));
                    int queryCount = endYear - startYear + 1;

                    std::cout << "Query: find ratio " << startYear << " " << endYear << "\n" << std::endl;
                    std::cout << "The female-to-male earnings ratio for " << startYear << "-" << endYear << ":" << std::endl;


                    int year = startYear;
                    for (int i = 0; i < queryCount; i++) {
                        std::string femaleOverMale = findRatio(earningsArr, year);
                        std::cout << "\t" << year << ": " <<
                        femaleOverMale.substr(2, 2) << "." <<  femaleOverMale.substr(4, 1)
                        << "%" << std::endl;

                        year++;
                    }

                } else if (line.substr(5,10) == "occupation") { // find occupation query
                    std::string codeToFind = line.substr(16, 7);
                    std::cout << "Query: find occupation " << codeToFind << '\n' << std::endl;
                    std::cout << "The occupation with SOC code " << codeToFind << ":" << std::endl;
                    hash_table_entry* occupation = findSOC(hashTable, codeToFind, m);
                    if (occupation) {
                        std::cout << "\t" << occupation->node->soc.occupation << ": YRFT: " << formatWithCommas(occupation->node->soc.total) <<
                        ", Female: " << formatWithCommas(occupation->node->soc.female) << ", Male: " << formatWithCommas(occupation->node->soc.male) << std::endl;
                    } else {
                        // no matching soc code found
                        std::cout << "Occupation with SOC code " << codeToFind << " not found" << std::endl;
                    }
                }
            } else if (line.substr(0, 5) == "range") { // range query
                std::string words = line.substr(17, line.length() - 17);
                std::string low = getQuotedRange(words, true);
                std::string high = getQuotedRange(words, false);
                std::cout << "Query: range occupation " << words << '\n' << std::endl;
                std::cout << "The occupations in the range \"" << low << "\" to \"" << high << "\":" << std::endl;
                bool foundVal = false;
                bool* foundValPtr = &foundVal;
                inorderSearch(bstRoot, low, high, foundValPtr);
                if (!*foundValPtr) {
                    std::cout << '\t' << "No occupations found in the given range" << std::endl;
                }
            } else { // first line, number of query
                k = getIntFromString(line);
            }

            // decrease number of query
            if (k == 0) {
                isLastQuery = true;
            }
            k--;
            if (!isFirstQuery && !isLastQuery) {
                std::cout << "\n";
            }
            isFirstQuery = false;
        }
    } else {
        std::cout << "Invalid Use" << std::endl;
    }
    return 0;
}
