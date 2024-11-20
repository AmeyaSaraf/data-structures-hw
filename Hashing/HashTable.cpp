#include "HashTable.h"
#include <iostream>

// Constructor to initialize hash table with given size
HashTable::HashTable(int size) : size(size), table(size, nullptr) {}

// Destructor to clean up resources
HashTable::~HashTable() {
    for (auto& ptr : table) {
        delete ptr;
    }
}

// Hash function to compute index based on value
int HashTable::hash_function(int x) {
    return x % size;
}

// Repositions elements after removal to maintain correct order
void HashTable::reposition(int removed_index) {
    int index = (removed_index + 1) % size;
    while (table[index] != nullptr) {
        int original_index = hash_function(*table[index]);
        if ((original_index <= removed_index && removed_index < index) ||
            (removed_index < index && index < original_index) ||
            (index < original_index && original_index <= removed_index)) {
            table[removed_index] = table[index];
            table[index] = nullptr;
            removed_index = index;
        }
        index = (index + 1) % size;
    }
}

// Inserts a value into the hash table
void HashTable::insert(int x) {
    int index = hash_function(x);
    int slots_checked = 0;

    while (slots_checked < size) {
        if (table[index] == nullptr) {
            table[index] = new int(x);
            std::cout << "The value " << x << " was inserted." << std::endl;
            return;
        }
        else {
            index = (index + 1) % size;
            slots_checked++;
        }
    }

    std::cout << "The value " << x << " cannot be inserted." << std::endl;
}

// Searches for a value in the hash table
void HashTable::search(int x) {
    int index = hash_function(x);
    int slots_checked = 0;

    while (slots_checked < size) {
        if (table[index] == nullptr) {
            std::cout << "The value " << x << " cannot be found." << std::endl;
            return;
        }
        else if (*table[index] == x) {
            std::cout << "The value " << x << " can be found." << std::endl;
            return;
        }
        else {
            index = (index + 1) % size;
            slots_checked++;
        }
    }

    std::cout << "The value " << x << " cannot be found." << std::endl;
}

// Removes a value from the hash table
void HashTable::remove(int x) {
    int index = hash_function(x);
    int slots_checked = 0;

    while (slots_checked < size) {
        if (table[index] == nullptr) {
            std::cout << "The value " << x << " cannot be removed." << std::endl;
            return;
        }
        else if (*table[index] == x) {
            delete table[index];
            table[index] = nullptr;
            reposition(index);
            std::cout << "The value " << x << " was removed." << std::endl;
            return;
        }
        else {
            index = (index + 1) % size;
            slots_checked++;
        }
    }

    std::cout << "The value " << x << " cannot be removed." << std::endl;
}

// Prints the contents of the hash table
void HashTable::print_table() {
    for (int i = 0; i < size; ++i) {
        if (table[i] != nullptr) {
            std::cout << "Slot " << i << ": " << *table[i] << std::endl;
        }
        else {
            std::cout << "Slot " << i << ": empty" << std::endl;
        }
    }
}

