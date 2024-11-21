#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

class HashTable {
private:
    std::vector<int*> table; // Vector of pointers to store hash table elements
    int size; // Size of the hash table

    int hash_function(int x); // Hash function to compute index
    void reposition(int removed_index); // Repositions elements after removal

public:
    HashTable(int size = 500); // Constructor
    ~HashTable(); // Destructor

    int insert(int x); // Inserts a value into the hash table
    int search(int x); // Searches for a value
    int remove(int x); // Removes a value
    void print_table(); // Prints the contents of the hash table
};

#endif
