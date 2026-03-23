#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#define capasity 10000

typedef struct Ht_item Ht_item;

// Define the Hash Table Item 
struct Ht_item {
    char* key;
    char* value;
};

struct HashTable {
    // Contains an array of pointers
    // to items
    Ht_item** items;
    int size; //table size
    int count; //count of elements in table

    void ht_insert(HashTable* table, char* key, char* value);
    unsigned long hash_function(char* str);
    Ht_item* create_item(char* key, char* value);
    HashTable* create_table(int size);
    void free_item(Ht_item* item);
    void free_table(HashTable* table);
    void print_table(HashTable* table);
};



