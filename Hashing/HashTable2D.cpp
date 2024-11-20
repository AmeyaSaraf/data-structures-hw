#include "HashTable2D.h"

// Constructor
HashTable2D::HashTable2D() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 5; j++) {
            table[i][j] = -1; // Set each slot to -1 means empty
        }
        counts[i] = 0;
    }
}

// Destructor
HashTable2D::~HashTable2D() {
    std::cout << "HashTable2D object destroyed." << std::endl;
}

// Insert function
int HashTable2D::insert(int value) {
    int index = value % 100; // calculate hash index
    int slotsChecked = 0;

    if (counts[index] < 5) {
        table[index][counts[index]] = value; // insert value
        counts[index]++;
        slotsChecked++;
        return slotsChecked;
    }

    // if row is full
    std::cout << "The value " << value << " Cannot be inserted. Row is full." << std::endl;
    return slotsChecked;
}

// Search function
int HashTable2D::search(int value) {
    int index = value % 100; 
    int slotsChecked = 0;

    // Loop through the row to search for the value
    for (int j = 0; j < counts[index]; j++) { // Only check the occupied slots
        slotsChecked++;
        if (table[index][j] == value) {
            std::cout << "The value " << value << " can be found." << std::endl;
            return slotsChecked; // Return the number of slots checked
        }
    }

    std::cout << "The value " << value << " cannot be found." << std::endl;
    return slotsChecked; 
}

// Remove function
int HashTable2D::remove(int value) {
    int index = value % 100;
    int slotsChecked = 0;

    for (int j = 0; j < counts[index]; j++) { // Only check the occupied slots
        slotsChecked++;

        if (table[index][j] == value) { // If the value is found
            // Shift remaining elements to the left
            for (int k = j; k < counts[index] - 1; k++) {
                table[index][k] = table[index][k + 1]; // Shift left
            }
            table[index][counts[index] - 1] = -1;
            counts[index]--;
            std::cout << "The value " << value << " was removed." << std::endl;
            return slotsChecked;
        }
    }

    std::cout << "The value " << value << " cannot be removed." << std::endl;
    return slotsChecked;
}

// Print function
void HashTable2D::print() {
    for (int i = 0; i < 100; i++) {
        std::cout << "Row " << i << ": ";
        for (int j = 0; j < 5; j++) {
            if (table[i][j] == -1) {
                std::cout << "[ ] ";
            } else {
                std::cout << "[" << table[i][j] << "] ";
            }
        }
        std::cout << std::endl;
    }
}
