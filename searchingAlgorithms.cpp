#include <iostream>
using namespace std;


void showArray(int* array, int arraySize){
  cout << "[";
  
  for (int i = 0; i < arraySize; i++){
    cout << array[i] << ",";
  }
  
  cout << "]" << endl;
}


int linearSearch(int* array, int targetItem, int arraySize){
  for (int i = 0; i < arraySize; i++){
    if (array[i] == targetItem){
      return i;
    }
  }
  
  return -1;
}


int binarySearch(int* array, int targetItem, int arraySize){
  int lowerIndex = 0;
  int upperIndex = arraySize -1;
  
  while (lowerIndex <= upperIndex){
    int midpoint = (lowerIndex + upperIndex) / 2;
    
    if (array[midpoint] > targetItem){
      upperIndex = midpoint - 1;
    }else if (array[midpoint] < targetItem){
      lowerIndex = midpoint + 1;
    }else{
      return midpoint;
    }
  }
  
  return -1;
}



int main() 
{
  int LENGTH = 5;
  int* ptr = (int*)malloc(LENGTH * sizeof(int));
  ptr[0] = 1;
  ptr[1] = 3;
  ptr[2] = 20;
  ptr[3] = 40;
  ptr[4] = 70;
  
  cout << binarySearch(ptr, 1, LENGTH) << endl;
  
}
