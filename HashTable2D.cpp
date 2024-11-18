#include <iostream>

class HashTable2D {
private:
	int table[100][5];
	int counts[100]; // track how many items

public:
	HashTable2D() { // constructor

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 5; j++) {
				table[i][j] = -1; // Set each slot to -1 means empty
			}
			counts[i] = 0;
		}
	}
	// destructor
	~HashTable2D() {
		std::cout << "HashTable2D object destroyed." << std::endl;
	}

	// insert function
	int insert(int value) {
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

	// search function
	int search(int value){
		int index = value % 100; 
		int slotsChecked = 0;

		// Loop through the row to search for the value
		for (int j = 0; j < counts[index]; j++) { // Only check the occupied slots
			slotsChecked++;      // Increment the number of slots checked
			if (table[index][j] == value) { // If the value is found
				std::cout << "The value " << value << " can be found." << std::endl;
				return slotsChecked; // Return the number of slots checked
			}
		}

		std::cout << "The value " << value << " cannot be found." << std::endl;
		return slotsChecked; 
	}

	// remove function
	int remove (int value){
		int index = value % 100;
		int slotsChecked = 0;

		for (int j=0; j<counts[index]; j++) { // Only check the occupied slots
			slotsChecked++;

			if (table[index][j] == value) { // If the value is found
				// Shift remaining elements to the left
				for (int k = j; k < counts[index] - 1; k++) {
					table[index][k] = table[index][k + 1]; // Shift left
				}
				table[index][counts[index] - 1] = -1;
				counts[index]--; // Decrease the count of items in this row
				std::cout << "The value " << value << " was removed." << std::endl;
				return slotsChecked;
			}
		}

		std::cout << "The value " << value << " cannot be removed." << std::endl;
		return slotsChecked;
	}
	// Print function
	void print() {

		// Loop through each row of the table
		for (int i = 0; i < 100; i++) {
			std::cout << "Row " << i << ": "; // Print the row number
			// Loop through each column in the current row
			for (int j = 0; j < 5; j++) {
				if (table[i][j] == -1) { // If the slot is empty
					std::cout << "[ ] "; // Print an empty slot
				}
				else {
					std::cout << "[" << table[i][j] << "] "; // Print the value in the slot
				}
			}
			std::cout << std::endl; // Move to the next line
		}
	}
};
