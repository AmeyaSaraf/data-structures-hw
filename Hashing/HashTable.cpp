#include "pch.h"
#include "HashTable.h"
#include <iostream>

HashTable::HashTable(int size) : size(size), table(size, nullptr) {}

HashTable::~HashTable() {
    for (auto& ptr : table) {
        delete ptr;
    }
}

int HashTable::hash_function(int x) {
    return x % size;
}

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

int HashTable::insert(int x) {
    int index = hash_function(x);
    int slots_checked = 0;

    while (slots_checked < size) {
        if (table[index] == nullptr) {
            table[index] = new int(x);
            return slots_checked + 1;
        }
        index = (index + 1) % size;
        slots_checked++;
    }
    return slots_checked;
}

int HashTable::search(int x) {
    int index = hash_function(x);
    int slots_checked = 0;

    while (slots_checked < size) {
        if (table[index] == nullptr) {
            return slots_checked;
        }
        else if (*table[index] == x) {
            return slots_checked + 1;
        }
        index = (index + 1) % size;
        slots_checked++;
    }
    return slots_checked;
}

int HashTable::remove(int x) {
    int index = hash_function(x);
    int slots_checked = 0;

    while (slots_checked < size) {
        if (table[index] == nullptr) {
            return slots_checked;
        }
        else if (*table[index] == x) {
            delete table[index];
            table[index] = nullptr;
            reposition(index);
            return slots_checked + 1;
        }
        index = (index + 1) % size;
        slots_checked++;
    }
    return slots_checked;
}

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
