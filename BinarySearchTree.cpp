//
// Created by cse310 on 3/3/22.
//

#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include "BinarySearchTree.h"
#include "Utility.h"
#include "defns.h"



bst* BUILD_BST(std::string year) {
    std::ifstream inFile;
    std::string fileName = "Occupation-Dist-All-" + year + ".csv";
    inFile.open(fileName);
    std::string line;

    // skip 5 lines
    for (int i = 0; i < 5; i++) {
        std::getline(inFile, line);
    }

    int subIndex = 0;
    int index = 0;

    bst* ROOT = NULL;
    bool firstNode = true;

    // parse csv, line by line
    while(inFile.good()) {
        std::getline(inFile, line);

        // parse csv, character by character
        bool insideQuote = false;
        std::string finalCell;
        SOC* nodePtr = (struct SOC*) malloc(sizeof(struct SOC));
        for(int i = 0; i < line.length(); i++) {

            // check if end of line
            if (i == line.length() - 1) {
                if (subIndex == 0) {
                    for (int j = 0; j < OCC_LEN; j++) {
                        nodePtr->occupation[j] = '\0';
                    }
                    for (int j = 0; j < finalCell.length(); j++) {
                        nodePtr->occupation[j] = finalCell[j];
                    }
                }
                if (subIndex == 1) {
                    for (int j = 0; j < CODE_LEN; j++) {
                        nodePtr->SOC_code[j] = '\0';
                    }
                    for (int j = 0; j < finalCell.length(); j++) {
                        nodePtr->SOC_code[j] = finalCell[j];
                    }
                }
                if (subIndex == 2) {
                    nodePtr->total = getIntFromString(finalCell);
                }
                if (subIndex == 3) {
                    nodePtr->female = getIntFromString(finalCell);
                }
                if (subIndex == 4) {
                    nodePtr->male = getIntFromString(finalCell);
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
                        for (int j = 0; j < OCC_LEN; j++) {
                            nodePtr->occupation[j] = '\0';
                        }
                        for (int j = 0; j < finalCell.length(); j++) {
                            nodePtr->occupation[j] = finalCell[j];
                        }
                    }
                    if (subIndex == 1) {
                        for (int j = 0; j < CODE_LEN; j++) {
                            nodePtr->SOC_code[j] = '\0';
                        }
                        for (int j = 0; j < finalCell.length(); j++) {
                            nodePtr->SOC_code[j] = finalCell[j];
                        }
                    }
                    if (subIndex == 2) {
                        nodePtr->total = getIntFromString(finalCell);
                    }
                    if (subIndex == 3) {
                        nodePtr->female = getIntFromString(finalCell);
                    }
                    if (subIndex == 4) {
                        nodePtr->male = getIntFromString(finalCell);
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

        if (firstNode) {
            ROOT = bstInsert(*nodePtr, ROOT);
            firstNode = false;
        } else {
            bstInsert(*nodePtr, ROOT);
        }
        index++;
    }
    inFile.close();
    return ROOT;
}

bst* bstInsert(SOC node, bst* root) {
    if (!root) {
        bst *newRoot = (struct bst*) malloc(sizeof(struct bst));
        newRoot->soc = node;
        newRoot->left = nullptr;
        newRoot->right = nullptr;
        return newRoot;
    }

    if (std::strcmp(node.occupation, root->soc.occupation) <= 0) { // smaller, go to left
        root->left = bstInsert(node, root->left);
    } else { // larger, go to right
        root->right = bstInsert(node, root->right);
    }
    return root;
}

void inorderSearch(bst* root, std::string low, std::string high, bool* foundVal) {
    if (!root) {
        return;
    }
    inorderSearch(root->left, low, high, foundVal);
    if (std::strcmp(root->soc.occupation, high.c_str()) <= 0 &&  std::strcmp(root->soc.occupation, low.c_str()) >= 0) {
        std::cout << "\t" << root->soc.occupation << ": YRFT: " << formatWithCommas(root->soc.total) << ", Female: " <<
        formatWithCommas(root->soc.female) << ", Male: " << formatWithCommas(root->soc.male) << std::endl;
        *foundVal = true;
    }
    inorderSearch(root->right, low, high, foundVal);
}