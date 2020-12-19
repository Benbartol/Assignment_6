//Ben Bartol
//ID: 2315721
//CPSC 350 Rene German
#include "assignment6.h"
using namespace std;

Sorting::Sorting(){

}

Sorting::~Sorting(){
  delete[] quickSortArray;
  delete[] insertionSortArray;
  delete[] mergeSortArray;
  delete[] selectionSortArray;
  delete[] bubbleSortArray;
}

void Sorting::setFile(string file){
  string nElements;
  string line;
  double size;
  int numLine = 1;

  ifstream inFS;
  inFS.open(file.c_str());

  getline(inFS, nElements);
  numElements = atoi(nElements.c_str());

  quickSortArray = new double[numElements];
  insertionSortArray = new double[numElements];
  mergeSortArray = new double[numElements];
  selectionSortArray = new double[numElements];
  bubbleSortArray = new double[numElements];



  for(int i = 0; i < numElements; ++i){
    numLine++;

    getline(inFS, line);

    try{
      size = atof(line.c_str());
    }catch(exception e){
      cout << "Invalid Format" << endl;
      return;
    }

    quickSortArray[i] = size;
    insertionSortArray[i] = size;
    mergeSortArray[i] = size;
    selectionSortArray[i] = size;
    bubbleSortArray[i] = size;

  }

  inFS.close();
  timedSortAll(numElements);
}

void Sorting::swap(double array[], int a, int b){
  double tempArray = array[a];
  array[a] = array[b];
  array[b] = tempArray;
}

int Sorting::partition(double array[], int left, int right){

  int center = array[(left + right) / 2];

  while (left <= right){
    while(array[left] < center){
      left++;
    }


    while(array[right] > center){
      right--;
    }

    if(left <= right){
      swap(array, left, right);
      left++;
      right--;
    }
  }
  return left;
}

void Sorting::quickSort(double array[], int left, int right){
  int idx = partition(array, left, right);

  if(left < idx - 1){
    quickSort(array, left, idx - 1);
  }
  if(right > idx){
    quickSort(array, idx, right);
  }
}

void Sorting::insertionSort(double array[]){
  //making marker
  for(int j =1; j < numElements; ++j){
    //keeping marker
    double temp = array[j];
    //moving marker
    int k = j;

    while(k > 0 && array[k-1] >= temp){
      array[k] = array[k-1];
      --k;
    }

    array[k] = temp;
  }
}

void Sorting::merge(double array[], int low, int mid, int high){

  int temp[high + 1];
  int i = low;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= high){
    if(array[i] <= array[j]){
      temp[k++] = array[j++];
    }else{
      temp[k++] = array[j++];
    }
  }

  while(i <= mid){
    temp[k++] = array[i++];
  while(j <= high){
    temp[k++] = array[j++];
  }

  k--;
  while(k >= 0){
    array[k + low] = temp[k];
    k--;
    }
  }
}

void Sorting::mergeSort(double array[], int low, int high){

  int mid;

  if(low < high){
    mid = (low + high) / 2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);
    merge(array, low, mid, high);
  }
}

void Sorting::selectionSort(double array[], int n){

  int i, j, min, temp;
  for(i = 0; i < n - 1; i++){
    min = i;
    for(j = i + 1; j < n; j++){
      if(array[j] < array[min]){
        min = j;
      }
      if(min != i){
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
      }
    }
  }
}

void Sorting::bubbleSort(double array[], int n){

  for(int i = 0; i < n; i++){
    int swaps = 0; //just detecting if swap or not
    for(int j = 0; j < n - i - 1; j++){
      if(array[j] > array[j+1]){
        swap(array, array[j], array[j+1]);
        swaps = 1;
      }
    }
    if(!swaps){
      break;
    }
  }
}

void Sorting::timedSortAll(){
  clock_t clockStart;
  clock_t clockEnd;
  float calculatedTime;

  cout << "Beginning Sorting Process..." << endl;

  //Quick Sort
  clockStart = clock();
  quickSort(quickSortArray, 0, numElements - 1);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "Quick Sort took " << calculatedTime << "ms to finish sorting the file" << endl;

  //Insertion Sort
  clockStart = clock();
  insertionSort(insertionSortArray);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "Insertion Sort took " << calculatedTime << "ms to finish sorting the file" << endl;

  //Merge Sort
  clockStart = clock();
  mergeSort(mergeSortArray, low, high);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "Merge Sort took " << calculatedTime << "ms to finish sorting the file" << endl;

  //Selection Sort
  clockStart = clock();
  selectionSort(selectionSortArray, numElements);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "Selection Sort took " << calculatedTime << "ms to finish sorting the file" << endl;

  //Bubble Sort
  clockStart = clock();
  bubbleSort(bubbleSortArray, numElements);
  clockEnd = clock();

  calculatedTime = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  cout << "Bubble Sort took " << calculatedTime << "ms to finish sorting the file" << endl;

  cout << "Sorting Completed..." << endl;
}
