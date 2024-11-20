#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <optional>

// HashTable class definition
class HashTable {
private:
    std::vector<std::optional<int>> table;  // Vector to store hash table elements
    int size;  // Size of the hash table

    // Hash function to compute index based on value
    int hash_function(int x);

    // Repositions elements after removal to maintain correct order
    void reposition(int removed_index);

public:
    // Constructor to initialize hash table with given size
    HashTable(int size = 500);

    // Destructor to clean up resources
    ~HashTable();

    // Inserts a value into the hash table
    void insert(int x);

    // Searches for a value in the hash table
    void search(int x);

    // Removes a value from the hash table
    void remove(int x);

    // Prints the contents of the hash table
    void print_table();
};

#endif // HASHTABLE_H
