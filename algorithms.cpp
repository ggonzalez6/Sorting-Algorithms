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

// Bubble Sort Function
void bubbleSort(int arr[], int& n) {
  ifstream inFile("data.txt");
  n = 0;
  while (inFile >> arr[n] && n < SIZE) {
    n++;
  }
  inFile.close();

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
	// Swap if in wrong order
	int temp = arr[j];
	arr[j] = arr[j + 1];
	arr[j + 1] = temp;
      }
    }
  }
}


// Partition function
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return i + 1;  // Return the partition index
}

// Quick Sort recursive function
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);  // partition index

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// QuickSort wrapper that handles file input
void quickSortWrapper(int arr[], int& n) {
  ifstream inFile("data.txt");
  n = 0;
  while (inFile >> arr[n] && n < SIZE) {
    n++;
  }
  inFile.close();

  quickSort(arr, 0, n - 1);
}

// Merges two sorted halves of arr[left..mid] and arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Temporary arrays
  int L[n1], R[n2];

  // Copy data into temp arrays
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  // Merge temp arrays back into arr[left..right]
  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy remaining elements of L[]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy remaining elements of R[]
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Recursive merge sort
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);      // Sort first half
    mergeSort(arr, mid + 1, right); // Sort second half
    merge(arr, left, mid, right);   // Merge both halves
  }
}

void mergeSortWrapper(int arr[], int& n) {
  ifstream inFile("data.txt");
  if (!inFile) {
    cout << "Failed to open data.txt." << endl;
    exit(1);
  }

  n = 0;
  while (inFile >> arr[n] && n < SIZE) {
    n++;
  }

  inFile.close();

  mergeSort(arr, 0, n - 1);
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
  testSort(bubbleSort, "Bubble Sort", "bubble_result.txt");

  for (int i = 0; i < n; i++) temp[i] = original[i];
  auto start = high_resolution_clock::now();
  quickSort(temp, 0, n - 1);
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start);
  cout << "Quick Sort took " << duration.count() << " ms" << endl;
  writeData("quick_result.txt", temp, n);

  for (int i = 0; i < n; i++) temp[i] = original[i];
  start = high_resolution_clock::now();
  mergeSort(temp, 0, n - 1);
  end = high_resolution_clock::now();
  duration = duration_cast<milliseconds>(end - start);
  cout << "Merge Sort took " << duration.count() << " ms" << endl;
  writeData("merge_result.txt", temp, n);
}
