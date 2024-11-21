#include "HashTable2D.h"
#include <iostream>

HashTable2D::HashTable2D() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 5; j++) {
            table[i][j] = -1;
        }
        counts[i] = 0;
    }
}

HashTable2D::~HashTable2D() {
    std::cout << "HashTable2D object destroyed." << std::endl;
}

int HashTable2D::insert(int value) {
    int index = value % 100;
    int slotsChecked = 0;

    if (counts[index] < 5) {
        table[index][counts[index]] = value;
        counts[index]++;
        return ++slotsChecked;
    }

    std::cout << "The value " << value << " cannot be inserted. Row is full." << std::endl;
    return slotsChecked;
}

int HashTable2D::search(int value) {
    int index = value % 100;
    int slotsChecked = 0;

    for (int j = 0; j < counts[index]; j++) {
        slotsChecked++;
        if (table[index][j] == value) {
            return slotsChecked;
        }
    }
    return slotsChecked;
}

int HashTable2D::remove(int value) {
    int index = value % 100;
    int slotsChecked = 0;

    for (int j = 0; j < counts[index]; j++) {
        slotsChecked++;
        if (table[index][j] == value) {
            for (int k = j; k < counts[index] - 1; k++) {
                table[index][k] = table[index][k + 1];
            }
            table[index][counts[index] - 1] = -1;
            counts[index]--;
            return slotsChecked;
        }
    }
    return slotsChecked;
}

void HashTable2D::print() {
    for (int i = 0; i < 100; i++) {
        std::cout << "Row " << i << ": ";
        for (int j = 0; j < 5; j++) {
            if (table[i][j] == -1) {
                std::cout << "[ ] ";
            }
            else {
                std::cout << "[" << table[i][j] << "] ";
            }
        }
        std::cout << std::endl;
    }
}
