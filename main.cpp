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
  cout << "3. Generate 10,000 random numbers" << endl;   
  cout << "4. Review how long it took to sort the data" << endl;
  cout << "8. Exit this program" << endl;

  cout << endl;
  cout << "Please enter a number of choice now: " << choice;

  while(choice != "8") {
    if(choice == "1") {
      insertSort(numbers, count);
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
      generateRandomNumbers();
      cout << "Exit now to review the results, or continue to an algorithm: ";
    }
    else if (choice == "4") {   
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
