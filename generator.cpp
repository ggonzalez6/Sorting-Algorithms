#include "generator.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandomNumbers() {
  // Seed the random number generator
  srand(time(0));

  ofstream outFile;
  outFile.open("data.txt");
  if (!outFile) {
    cout << "Failed to open file for writing." << endl;
  }

  // Generate a random integer within a specific range
  int min = 0;
  int max = 1000;
  for (int i = 0; i < 10000; i++) {
    int randomNumber = (rand() % (max - min + 1)) + min;
    outFile << randomNumber << endl;
  }

  outFile.close();
  cout << "10,000 random numbers written to data.txt." << endl;
  cout << endl;
  cout << endl;
}
