//Ben Bartol
//ID: 2315721
//CPSC 350 Rene German
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Sorting{
  private:
    int numElements;
    double *quickSortArray;
    double *insertionSortArray;
    double *selectionSortArray;
    double *mergeSortArray;
    double *bubbleSortArray;

  public:
    Sorting();
    ~Sorting();

    void setFile(string file);
    void swap(double array[], int a, int b);

    int partition(double array[], int left, int right);

    void quickSort(double array[], int left, int right);
    void insertionSort(double array[]);
    void merge(double array[], int low, int mid, int high);
    void mergeSort(double array[], int low, int high);
    void selectionSort(double array[], int n);
    void bubbleSort(double array[], int n);

    void timedSortAll();

};
