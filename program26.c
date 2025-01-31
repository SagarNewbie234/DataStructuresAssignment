#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int size, int* arr){
  int minIndex;
  for(int i = 0; i < size; i++){
    minIndex = i;
    for(int j = i+1; j < size; j++){
      if(arr[j] < arr[minIndex]){
        minIndex = j;
      }
    }
    swap(&arr[i], &arr[minIndex]);
  }
}

void binarySearch(int size, int* arr, int key){
  selectionSort(size, arr);
  int low = 0, high = size-1;
  while(low <= high){
    int mid = (low+high)/2;
    if(arr[mid] == key){
      printf("Element found!\n", mid);
      return;
    }
    else if(arr[mid] < key) low = mid+1;
    else high = mid-1;
  }
  printf("Element not found!\n");
}

void printArray(int size, int* arr){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(){
  int size, key;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for(int i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }
  printf("Enter the element to be searched: ");
  scanf("%d", &key);
  binarySearch(size, arr, key);
  return 0;
}