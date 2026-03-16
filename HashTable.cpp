#include "HashTable.hpp"

template <typename T>
void MiniVector<T>::push_back(T val) {
    if (currentSize == capacity) {
        capacity *= 2;
        T* temp = new T[capacity];
        for (int i = 0; i < currentSize; i++) temp[i] = data[i];
        delete[] data;
        data = temp;
    }
    data[currentSize++] = val;
}

int HashTable::midSquareHash(int key) {
    long long squared = (long long)key * key;
    std::string s = std::to_string(squared);
    if (s.length() > 2) {
        int mid = s.length() / 2;
        s = s.substr(mid - 1, 2);
    }
    return std::stoi(s) % TABLE_SIZE;
}

int HashTable::adler32Hash(std::string key) {
    unsigned long a = 1, b = 0;
    for (char c : key) {
        a = (a + c) % 65521;
        b = (b + a) % 65521;
    }
    return ((b << 16) | a) % TABLE_SIZE;
}

void HashTable::insert(int key, int value) {
    table[midSquareHash(key)].push_back(Node(key, value));
}

void HashTable::insert(std::string key, int value) {
    table[adler32Hash(key)].push_back(Node(key, value));
}

void HashTable::display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].size() > 0) {
            std::cout << "Bucket [" << i << "]: ";
            for (int j = 0; j < table[i].size(); j++) {
                if (table[i][j].isStringKey)
                    std::cout << "(" << table[i][j].strKey << ", " << table[i][j].value << ") ";
                else
                    std::cout << "(" << table[i][j].intKey << ", " << table[i][j].value << ") ";
            }
            std::cout << std::endl;
        }
    }
}