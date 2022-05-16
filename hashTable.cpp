#include <iostream>
using namespace std;


struct hashTableItem{
  char* key;
  int value;
};


class hashTable{
  private:
  
  int hashFunction(char* str){
    unsigned long hash = 5381;
    unsigned int size = str.length();
    unsigned int i = 0;
    
    for (i = 0; i < size; i++) {
        hash = ((hash << 5) + hash) + (str[i]); /* hash * 33 + c */
    }

    return hash;
  }
};



int main() 
{
    cout << "Hello, World!";
    return 0;
}
