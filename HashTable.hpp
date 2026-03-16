#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>

template <typename T>
class MiniVector {
private:
    T* data;
    int capacity;
    int currentSize;
public:
    MiniVector() : capacity(2), currentSize(0) { data = new T[capacity]; }
    ~MiniVector() { delete[] data; }
    void push_back(T val);
    int size() const { return currentSize; }
    T& operator[](int index) { return data[index]; }
};
struct Node {
    std::string strKey;
    int intKey;
    int value;
    bool isStringKey;
    Node() : strKey(""), intKey(0), value(0), isStringKey(false) {}
    Node(int k, int v) : intKey(k), value(v), isStringKey(false) {}
    Node(std::string k, int v) : strKey(k), value(v), isStringKey(true) {}
};
class HashTable {
private:
    static const int TABLE_SIZE = 100;
    MiniVector<Node> table[TABLE_SIZE];
    int midSquareHash(int key);
    int adler32Hash(std::string key);

public:
    void insert(int key, int value);
    void insert(std::string key, int value);
    void display();
};

#endif