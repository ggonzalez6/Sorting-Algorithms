#include "algorithms.h"
#include "generator.h"
#include <iostream>
#include <fstream>


using namespace std;

int main() {
  int numbers[SIZE];
  int count = 0;
  string choice;
  cout << "Welcome to the Sorting Factory Dr. Wang!" << endl;
  cout << "Before you explore the menu, you must first generate the list of numbers!" << endl;
  cout << "Please choose an option from the menu: " << endl;
  cout << "1. Insertion Sort" << endl;
  cout << "2. Counting Sort" << endl;
  cout << "3. Bubble Sort" << endl;
  cout << "4. Quick Sort" << endl;
  cout << "5. Merge Sort" << endl;
  cout << "6. Generate 10,000 random numbers" << endl;
  cout << "7. Review how long it took to sort the data" << endl;
  cout << "8. Exit this program" << endl;

  cout << endl;
  cout << "Please enter a number of choice now: " << choice;

  while(choice != "8") {
    if(choice == "1") {
      insertSort(numbers, count);
      // Write the sorted numbers to a file
      ofstream outFile("insertion_result.txt");
      if (!outFile) {
	cout << "Failed to open insertion_result.txt for writing." << endl;
	return 1;
      }

      for (int i = 0; i < count; i++) {
	outFile << numbers[i] << endl;
      }

      outFile.close();
      cout << "Sorted numbers written to insertion_result.txt." << endl;
      cout << endl << endl;
      cout << "Exit now to review the results, or continue to a different algorithm: ";
    }
    else if (choice == "2") {
      countingSort(numbers, count);
      // Write to output file
      ofstream outFile("counting_result.txt");
      if (!outFile) {
	cout << "Failed to open counting_result.txt for writing." << endl;
	return 1;
      }

      for (int i = 0; i < count; i++) {
	outFile << numbers[i] << endl;
      }

      outFile.close();
      cout << "Sorted numbers written to counting_result.txt." << endl;
      cout << endl << endl;
      cout << "Exit now to review the results, or continue to a different algorithm: ";
    }
    else if (choice == "3") {
      bubbleSort(numbers, count);
      // Write to bubble_result.txt
      ofstream outFile("bubble_result.txt");
      if (!outFile) {
	cerr << "Failed to open bubble_result.txt for writing." << endl;
	return 1;
      }

      for (int i = 0; i < count; i++) {
	outFile << numbers[i] << endl;
      }

      outFile.close();
      cout << "Sorted numbers written to bubble_result.txt." << endl;
      cout << endl << endl;
      cout << "Exit now to review the results, or continue to a different algorithm: ";
    }
    else if (choice == "4") {
      quickSortWrapper(numbers, count);
      // Write to quick_result.txt
      ofstream outFile("quick_result.txt");
      if (!outFile) {
	cout << "Failed to open quick_result.txt for writing." << endl;
	return 1;
      }

      for (int i = 0; i < count; i++) {
	outFile << numbers[i] << endl;
      }

      outFile.close();
      cout << "Sorted numbers written to quick_result.txt." << endl;
      cout << endl << endl;
      cout << "Exit now to review the results, or continue to a different algorithm: ";
    }
    else if (choice == "5") {
      mergeSortWrapper(numbers, count);
      // Write to merge_result.txt
      ofstream outFile("merge_result.txt");
      if (!outFile) {
	cout << "Failed to open merge_result.txt for writing." << endl;
	return 1;
      }

      for (int i = 0; i < count; i++) {
	outFile << numbers[i] << endl;
      }

      outFile.close();
      cout << "Sorted numbers written to merge_result.txt." << endl;
      cout << endl << endl;
      cout << "Exit now to review the results, or continue to a different algorithm: ";
    }
    else if (choice == "6") {
      generateRandomNumbers();
      cout << "Exit now to review the results, or continue to an algorithm: ";
    }
    else if (choice == "7") {
      runAllSorts();
      cout << "Exit now to review the results, or continue to an algorithm: ";
    }
    else {
    }
    cin >> choice;
    cout << endl;
  }
  return 0;
}
