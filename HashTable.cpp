//
// Created by cse310 on 3/3/22.
//

#include "HashTable.h"
#include "Utility.h"
void insertHash(hash_table_entry** hashTable, std::string code, bst* bstNode, int m, int k) {
    int key = k % m;
    if (!hashTable[key]) {
        hash_table_entry* new_node = (struct hash_table_entry*) malloc(sizeof(struct hash_table_entry));
        new_node->node = bstNode;
        new_node->next = nullptr;
        for (int i = 0; i < CODE_LEN; i++) {
            new_node->SOC_code[i] = '\0';
        }
        for (int i = 0; i < code.length(); i++) {
            new_node->SOC_code[i] = code[i];
        }
        hashTable[key] = new_node;
    } else {
        // insert at head
        hash_table_entry* new_node = (struct hash_table_entry*) malloc(sizeof(struct hash_table_entry));
        new_node->node = bstNode;
        new_node->next = hashTable[key];
        for (int i = 0; i < CODE_LEN; i++) {
            new_node->SOC_code[i] = '\0';
        }
        for (int i = 0; i < code.length(); i++) {
            new_node->SOC_code[i] = code[i];
        }
        hashTable[key] = new_node;
    }
}

hash_table_entry* findSOC(hash_table_entry** hashTable, std::string socString, int m) {
    int k = socCodeToInt(socString);
    int key = k % m;
    if (hashTable[key]) {
        if (hashTable[key]->next) {
            // linked list has more than one node, loop to find soc
            hash_table_entry* last = hashTable[key];
            while (last->next) {
                if (socCodeToInt(last->SOC_code) == k) {
                    return last;
                }
                last = last->next;
            }
        } else if (socCodeToInt(hashTable[key]->SOC_code) == k) {
            // linked list has only one node (head), check if soc match
            return hashTable[key];
        }
    }
    // no linked list at key exists
    return nullptr;
}