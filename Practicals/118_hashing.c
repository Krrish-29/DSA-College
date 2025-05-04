#include<stdio.h>
#define tableSize 7
int hashTable[tableSize] = {0}; 
int hash1(int key) {return key % tableSize;}
int hash2(int key) {return 1+ key%5;}
void insertKey(int key) {
    int index = hash1(key);
    int step = hash2(key);//Double hashing 
    // int i=1 ; Quadratic probing
    while (hashTable[index] != 0) { 
        index =(index+step) % tableSize;//Double hashing
        // index = (index + 1) % TABLE_SIZE; // Linear probing 
        // index = (hash1(key) + i * i) % TABLE_SIZE; i++; // Quadratic probing
    }hashTable[index] = key;}
int searchKey(int key) {
    int index = hash1(key);
    int step = hash2(key);//Double hashing 
    // int i=1 ; Quadratic probing
    while (hashTable[index] != 0) {
        if (hashTable[index] == key)return index;
        index =(index+step) % tableSize;//Double hashing 
        // index = (index + 1) % tableSize; // Linear probing 
        // index = (hash1(key) + i*i) % tableSize; i++; // Quadratic probing
    }return -1; }
void printTable() {
    printf("Index   Data\n");
    for (int i = 0; i < tableSize; i++) {
        printf("%d   ->   %d\n", i, hashTable[i]);}}
int main() {
    insertKey(1);
    insertKey(7);
    insertKey(3);
    insertKey(14);
    insertKey(19);
    insertKey(9); 
    printTable();
    printf("Is key %d in the hash table? : %s",19 ,searchKey(19) == -1?"No":"Yes");
}