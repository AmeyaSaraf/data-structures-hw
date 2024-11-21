#include "HashTable2D.h" 
#include "HashTable.h" 
#include <set>
#include <cstdlib>
#include <ctime>

int main() {
    //Seed rng
    std::srand(std::time(0));

    //Set makes sure all values are unique
    std::set<int> uniqueNumbers;
    while (uniqueNumbers.size() < 100) {
        int randomNumber = std::rand() % 1000 + 1; // Generate random number between 1 and 1000
        uniqueNumbers.insert(randomNumber);
    }

    // Copy unique number set into dataset array
    int dataset[100];
    int index = 0;
    for (int num : uniqueNumbers) {
        dataset[index++] = num;
    }

    HashTable onetable(500);
    HashTable2D twotable;

    int twoTableCheckedSlots = 0;
    int oneTableCheckedSlots = 0;
    
    //First insertion
    for (int i=0; i<50; i++) {
        int checkedSlots = onetable.insert(dataset[i]);
        oneTableCheckedSlots += checkedSlots;
        checkedSlots = twotable.insert(dataset[i]);
        twoTableCheckedSlots += checkedSlots;
    }

    std::cout << "Running total of checked slots for 1D hash table: " << oneTableCheckedSlots << std::endl;
    std::cout << "Running total of checked slots for 2D hash table: " << twoTableCheckedSlots << std::endl;

    //Selective removal
    for (int i=0; i<50; i++) {
        if (dataset[i] % 7 == 0) {
            int checkedSlots = onetable.remove(dataset[i]);
            oneTableCheckedSlots += checkedSlots;
            checkedSlots = twotable.remove(dataset[i]);
            twoTableCheckedSlots += checkedSlots;
        }
    }

    std::cout << "Running total of checked slots for 1D hash table: " << oneTableCheckedSlots << std::endl;
    std::cout << "Running total of checked slots for 2D hash table: " << twoTableCheckedSlots << std::endl;

    //Second insertion
    for (int i=50; i<100; i++) {
        int checkedSlots = onetable.insert(dataset[i]);
        oneTableCheckedSlots += checkedSlots;
        checkedSlots = twotable.insert(dataset[i]);
        twoTableCheckedSlots += checkedSlots;
    }

    std::cout << "Running total of checked slots for 1D hash table: " << oneTableCheckedSlots << std::endl;
    std::cout << "Running total of checked slots for 2D hash table: " << twoTableCheckedSlots << std::endl;

    //Search Operation
    for (int i=0; i<100; i++) {
        if (dataset[i] % 9 == 0) {
            int checkedSlots = onetable.search(dataset[i]);
            oneTableCheckedSlots += checkedSlots;
            checkedSlots = twotable.search(dataset[i]);
            twoTableCheckedSlots += checkedSlots;
        }
    }

    std::cout << "Final total of checked slots for 1D hash table: " << oneTableCheckedSlots << std::endl;
    std::cout << "Final total of checked slots for 2D hash table: " << twoTableCheckedSlots << std::endl;
}