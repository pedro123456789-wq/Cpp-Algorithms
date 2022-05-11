#include <iostream>
using namespace std;

int* bubbleSort(int* array, int arraySize){
  bool sorted = false;
  int iterations = 0;
  
  while (!sorted && iterations < arraySize){
    sorted = true;
    
    for (int i = 0; i < arraySize - iterations; i++){
      if (array[i + 1] < array[i]){
        int temp = array[i + 1];
        array[i + 1] = array[i];
        array[i] = temp;
        sorted = false;
      }
    }
    
    iterations ++; 
  }
  
  return array;
}

int main() 
{
  int LENGTH = 5;
  int* ptr = (int*)malloc(LENGTH * sizeof(int));
  ptr[0] = 3;
  ptr[1] = 7;
  ptr[2] = 2;
  ptr[3] = -1;
  ptr[4] = 20;
  
  int* sorted = bubbleSort(ptr, LENGTH);
  for (int i = 0; i < LENGTH; i ++){
    cout << sorted[i] << endl;
  }
}
