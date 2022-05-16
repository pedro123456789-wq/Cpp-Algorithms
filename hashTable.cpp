#include <iostream>
using namespace std;



class HashTable{
private:
  int* valuesArray;
  char** keysArray;
  int tableSize;
  
public:
  hashTable(int size){
    tableSize = size;
    valuesArray = (int*)malloc(size * sizeof(int));
    keysArray = (char**)malloc(size * sizeof((char*)malloc(size * sizeof(char))));
  }
  
  // algorithm to convert string into index
  int hashFunction(char* str){
    long hash = 123;
    int index = 0;
    char currentChar = str[index];
    
    while (currentChar) {
        hash = ((hash << 5) + hash) + (currentChar);
        currentChar = str[index ++];
    } 
    
    // make hash positive and within the bounds of the array 
    return abs(hash) % tableSize;
  }
  
  // add new element to correct index in array
  void put(char* key, int value){
    int index = hashFunction(key);
    
    if (keysArray[index] == 0){
      valuesArray[index] = value;
      keysArray[index] = key;
    }else{
      if (keysArray[index] == key){
        cout << "Key already in use" << endl;
      }else{
        cout << "Collision" << endl;
        // TODO: Add collision handling
      }
    }
  }
  
  // get element from hash table 
  int get(char* key){
    int index = hashFunction(key);
    
    if (keysArray[index] != 0){
      return valuesArray[index];
    }else{
      cout << "Invalid Key" << endl;
      return -1;
    }
  }
};



int main() 
{
  hashTable table = hashTable(60);
  table.put("t1", 2);
  table.put("t4", 5);
  table.put("t4", 7);
  
  cout << table.get("t1") << endl;
  cout << table.get("t4") << endl;
}
