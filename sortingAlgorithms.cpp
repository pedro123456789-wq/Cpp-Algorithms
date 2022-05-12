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


int* subSort(int* arr1, int* arr2, int length1, int length2){
    // create new ouptut array
    int* output = (int*)malloc(length1 + length2);
    int arr1Index = 0;
    int arr2Index = 0;
    
    
    // sort two arrays, knowing that each of the sub arrays is sorted
    while (arr1Index < length1 && arr2Index < length2){
      if (arr1[arr1Index] < arr2[arr2Index]){
        output[arr1Index + arr2Index] = arr1[arr1Index];
        arr1Index ++;
      }else{
        output[arr1Index + arr2Index] = arr2[arr2Index];
        arr2Index ++;
      }
    }
    
    while (arr1Index < length1){
      output[arr1Index + arr2Index] = arr1[arr1Index];
      arr1Index ++;
    }
    
    
    while (arr2Index < length2){
      output[arr1Index + arr2Index] = arr2[arr2Index];
      arr2Index ++;
    }
    
    showArray(arr1, length1);
    showArray(arr2, length2);
    showArray(output, length1 + length2);
    cout << "-----------" << endl;
    
    
    return output;
}


int* mergeSort(int* array, int arraySize){
  if (arraySize < 2){
    return array;
  }
  
  // ---------- Split array in half ---------------
  // find midpoint of array and create left and right arrays with correct lengths
  int midpoint = arraySize / 2;
  int* leftArr = (int*)malloc(midpoint);
  int* rightArr = (int*)malloc(arraySize - midpoint);
  
  //add all elements before the midpoint to left array and elements after the midpoint to right array
  for (int i = 0; i < arraySize; i ++){
    if (i < midpoint){
      leftArr[i] = array[i];
    }else{
      rightArr[i - midpoint] = array[i];
    }
  }
  
  // Recursive case 
  int* sortedLeft = mergeSort(leftArr, midpoint);
  int* sortedRight = mergeSort(rightArr, arraySize - midpoint);
  
  return subSort(sortedLeft, sortedRight, midpoint, arraySize - midpoint);
}



int main() 
{
  int LENGTH = 5;
  int* ptr = (int*)malloc(LENGTH * sizeof(int));
  ptr[0] = 3;
  ptr[1] = 2;
  ptr[2] = 1;
  ptr[3] = 5;
  ptr[4] = 20;
  
  showArray(mergeSort(ptr, LENGTH), LENGTH);
}
