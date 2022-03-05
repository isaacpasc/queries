//
// Created by cse310 on 3/2/22.
//

#ifndef PROJECT_2_DEFNS_H
#define PROJECT_2_DEFNS_H
// File defns.h for Project #2, Spring 2022

#define	OCC_LEN	125
#define	CODE_LEN 75
#define	NUM_OCC 505

// Structure to hold values from the Earnings-Dist-All-YYY.csv file.  See section 1.1 of the
// project description on Data Format.
//
// A max-heap is defined as an array of struct SOC of size large enough to hold the occupations
// for the given YYYY of data.
//
// Used to answer "find max" queries.

struct SOC{
    char occupation[ OCC_LEN ]; // occupation using SOC
    char SOC_code[ CODE_LEN ]; // SOC code(s) associated with the occupation
    int total; // Number of workers in the occupation that are year-round full-time (YRFT) // id =1
    int female; // Number of YRFT that are female // id = 2
    int male; // Number of YRFT that are male // id = 3
};

// Structure to hold values from the Earnings-1960-1999.csv file.  See section 1.1 of the project
// description on Data Format.

struct earnings{
    int year; // The year for which data is provided
    int male_total; // Number of male workers (thousands)
    int male_with_earnings; // Number of male workers (thousands) with earnings
    int male_earnings; // Male median earnings (dollars) estimate
    int male_earnings_moe; // Male margin of error in earnings
    int female_total; // Number of female workers (thousands)
    int female_with_earnings; // Number of female workers (thousands) with earnings
    int female_earnings; // Female median earnings (dollars) estimate
    int female_earnings_moe; // Female margin of error in earnings
};

// A hash table is an array of pointers to hash_table_entry, i.e., separate chaining is used
// for collision resolution.  Each entry contains a SOC code, and a pointer to the entry in
// the BST with the corresponding SOC code.

struct hash_table_entry{
    char SOC_code[ CODE_LEN ]; // Key fed to hash function
    struct bst *node; // Node in BST with data associated with this SOC code
    struct hash_table_entry *next; // Pointer to next entry in case of collisions
};

// A binary search tree ordered on the occupation field of the SOC structure

struct bst{
    struct SOC soc; // A SOC structure
    struct bst *left; // A pointer to the left child
    struct bst *right; // A pointer to the right child
};
#endif //PROJECT_2_DEFNS_H
