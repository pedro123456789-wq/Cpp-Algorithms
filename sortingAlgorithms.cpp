#include <iostream>
using namespace std;


void showArray(int* array, int arraySize){
  cout << "[";
  
  for (int i = 0; i < arraySize; i++){
    cout << array[i] << ",";
  }
  
  cout << "]" << endl;
}


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


int* insertionSort(int* array, int arraySize){
  for (int currentIndex = 0; currentIndex < arraySize; currentIndex ++){
    int targetItem = array[currentIndex];
    
    while (currentIndex > 0 && array[currentIndex - 1] > targetItem){
      array[currentIndex] = array[currentIndex - 1];
      currentIndex --;
    }

    array[currentIndex] = targetItem;
  }
  
  return array;
}



int main() 
{
  int LENGTH = 5;
  int* ptr = (int*)malloc(LENGTH * sizeof(int));
  ptr[0] = 3;
  ptr[1] = 2;
  ptr[2] = 1;
  ptr[3] = -1;
  ptr[4] = 20;
  
  showArray(insertionSort(ptr, LENGTH), LENGTH);
}
