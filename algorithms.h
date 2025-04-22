#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <string>

using namespace std;

const int SIZE = 10000;

void insertSort(int arr[], int& n);
void countingSort(int inputArray[], int& n);
void bubbleSort(int arr[], int& n);
void quickSortWrapper(int arr[], int& n);
void mergeSortWrapper(int arr[], int& n);
void runAllSorts();
void readData(int arr[], int& n);
void writeData(const string& filename, int arr[], int n);

#endif //ALGORITHMS_H
