#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <optional>

class HashTable {
private:
    std::vector<std::optional<int>> table;
    int size;

    int hash_function(int x);
    void reposition(int removed_index);

public:
    HashTable(int size = 500);
    ~HashTable();

    void insert(int x);
    void search(int x);
    void remove(int x);
    void print_table();
};

#endif // HASHTABLE_H
