//
// Created by cse310 on 3/3/22.
//

#ifndef PROJECT_2_BINARYSEARCHTREE_H
#define PROJECT_2_BINARYSEARCHTREE_H
#include "defns.h"
#include "string"
bst* BUILD_BST(std::string);
bst* bstInsert(SOC, bst*);
void inorderSearch(bst*, std::string, std::string, bool*);
#endif //PROJECT_2_BINARYSEARCHTREE_H
