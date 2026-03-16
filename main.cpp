#include "HashTable.hpp"

int main() {
    HashTable myHT;
    myHT.insert(10, 20);
    myHT.insert("fg", 67);
    myHT.display();
    return 0;
}