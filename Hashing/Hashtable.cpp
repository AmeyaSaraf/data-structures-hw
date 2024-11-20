#include "HashTable.h"
#include <iostream>

HashTable::HashTable(int size) : size(size), table(size) {}

HashTable::~HashTable() {}

int HashTable::hash_function(int x) {
    return x % size;
}

void HashTable::reposition(int removed_index) {
    int index = (removed_index + 1) % size;
    while (table[index].has_value()) {
        int original_index = hash_function(table[index].value());
        if ((original_index <= removed_index && removed_index < index) || 
            (removed_index < index && index < original_index) || 
            (index < original_index && original_index <= removed_index)) {
            table[removed_index] = table[index];
            table[index].reset();
            removed_index = index;
        }
        index = (index + 1) % size;
    }
}

void HashTable::insert(int x) {
    int index = hash_function(x);
    int slots_checked = 0;
    
    while (slots_checked < size) {
        if (!table[index].has_value()) {
            table[index] = x;
            std::cout << "The value " << x << " was inserted." << std::endl;
            return;
        } else {
            index = (index + 1) % size;
            slots_checked++;
        }
    }
    
    std::cout << "The value " << x << " cannot be inserted." << std::endl;
}

void HashTable::search(int x) {
    int index = hash_function(x);
    int slots_checked = 0;

    while (slots_checked < size) {
        if (!table[index].has_value()) {
            std::cout << "The value " << x << " cannot be found." << std::endl;
            return;
        } else if (table[index] == x) {
            std::cout << "The value " << x << " can be found." << std::endl;
            return;
        } else {
            index = (index + 1) % size;
            slots_checked++;
        }
    }

    std::cout << "The value " << x << " cannot be found." << std::endl;
}

void HashTable::remove(int x) {
    int index = hash_function(x);
    int slots_checked = 0;

    while (slots_checked < size) {
        if (!table[index].has_value()) {
            std::cout << "The value " << x << " cannot be removed." << std::endl;
            return;
        } else if (table[index] == x) {
            table[index].reset();
            reposition(index);
            std::cout << "The value " << x << " was removed." << std::endl;
            return;
        } else {
            index = (index + 1) % size;
            slots_checked++;
        }
    }

    std::cout << "The value " << x << " cannot be removed." << std::endl;
}

void HashTable::print_table() {
    for (int i = 0; i < size; ++i) {
        if (table[i].has_value()) {
            std::cout << "Slot " << i << ": " << table[i].value() << std::endl;
        } else {
            std::cout << "Slot " << i << ": empty" << std::endl;
        }
    }
}
