#include "algorithms.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Insertion Sort Function
void insertSort (int arr[], int& n) {
  ifstream inFile("data.txt");
  n = 0;
  while (inFile >> arr[n] && n < SIZE) {
    n++;
  }

  inFile.close();

  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// Counting Sort Function
void countingSort(int inputArray[], int& n) {
  ifstream inFile("data.txt");
  n = 0;
  int maxVal = 0;

  while (inFile >> inputArray[n] && n < SIZE) {
    if (inputArray[n] > maxVal)
      maxVal = inputArray[n];
    n++;
  }
  inFile.close();

  int countArray[maxVal + 1];
  for (int i = 0; i <= maxVal; i++)
    countArray[i] = 0;

  for (int i = 0; i < n; i++)
    countArray[inputArray[i]]++;

  for (int i = 1; i <= maxVal; i++)
    countArray[i] += countArray[i - 1];

  int outputArray[SIZE];
  for (int i = n - 1; i >= 0; i--) {
    int value = inputArray[i];
    outputArray[countArray[value] - 1] = value;
    countArray[value]--;
  }

  for (int i = 0; i < n; i++)
    inputArray[i] = outputArray[i];
}

// Utility Functions
void readData(int arr[], int& n) {
  ifstream inFile("data.txt");
  n = 0;
  while (inFile >> arr[n] && n < SIZE) n++;
  inFile.close();
}

void writeData(const string& filename, int arr[], int n) {
  ofstream outFile(filename);
  for (int i = 0; i < n; i++) outFile << arr[i] << endl;
  outFile.close();
}

// Unified Runtime Test
void runAllSorts() {
  int original[SIZE], temp[SIZE], n;
  readData(original, n);

  auto testSort = [&](auto sortFunc, const string& name, const string& outputFile) {
		    for (int i = 0; i < n; i++) temp[i] = original[i];
		    auto start = high_resolution_clock::now();
		    sortFunc(temp, n);
		    auto end = high_resolution_clock::now();
		    auto duration = duration_cast<milliseconds>(end - start);
		    cout << name << " took " << duration.count() << " ms" << endl;
		    writeData(outputFile, temp, n);
		  };

  testSort(insertSort, "Insertion Sort", "insertion_result.txt");
  testSort(countingSort, "Counting Sort", "counting_result.txt");
}
