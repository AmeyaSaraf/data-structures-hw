#pragma once
#ifndef HASHTABLE2D_H
#define HASHTABLE2D_H

#include <iostream>

class HashTable2D {
private:
    int table[100][5];
    int counts[100]; // Track how many items are in each row

public:
    HashTable2D(); // Constructor
    ~HashTable2D(); // Destructor

    int insert(int value); // Insert function
    int search(int value); // Search function
    int remove(int value); // Remove function
    void print(); // Print function
};

#endif
