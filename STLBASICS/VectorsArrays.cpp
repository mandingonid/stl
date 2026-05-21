/*
 * VectorsArrays.cpp
 *
 *  Created on: May 20, 2026
 *      Author: rodney
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <list>
#include <tuple>


// Function to display contents of a vector
int displayVector(const std::vector<int>& vec) {
  for (const auto& num : vec) {
    std::cout << num << " ";  
  }
  std::cout << std::endl;
  return 0;
}

int main(int argc, char* argv[]){     
  const int AMOUNT_NUMBERS = 31;
  int result = -1;
  std::mt19937 rng;
  // Seed the engine with a non-deterministic seed for better randomness
  std::random_device rd;
  rng.seed(rd());

  std::uniform_int_distribution<> randomNumber(0, AMOUNT_NUMBERS);
  std::vector<int> randomNumbers;

  for (int i = 0; i < AMOUNT_NUMBERS; ++i) {
    randomNumbers.push_back(randomNumber(rng));
  }
  std::cout << "Size of random numbers vector: " << randomNumbers.size() << std::endl;
  std::cout << "Random numbers:" << std::endl;
  for (const auto& num : randomNumbers) {
    std::cout << num << " ";  
  }
  std::cout << std::endl;

  /***********************************************************************
  *  Test Vector Template methods by accessing random numbers    
  ***********************************************************************/
 
  std::cout << "Size: " << randomNumbers.size() << std::endl;
  std::cout << "Max size: " << randomNumbers.max_size() << std::endl;
  std::cout << "Capacity: " << randomNumbers.capacity() << std::endl;
  randomNumbers.resize(20);
  std::cout << "Size after resize to 20: " << randomNumbers.size() << std::endl;
  if (randomNumbers.empty()) {
    std::cout << "Vector is empty." << std::endl;
  } else {
    std::cout << "Vector is not empty." << std::endl;
  }

  std::cout << "Element at index 5: " << randomNumbers[5] << std::endl;
  std::cout << "Element at(0) is: " << randomNumbers.at(0) << std::endl;
  std::cout << "First element: " << randomNumbers.front() << std::endl; 
  std::cout << "Last element: " << randomNumbers.back() << std::endl;   

  randomNumbers.clear();
  std::cout << "Size after clear: " << randomNumbers.size() << std::endl;
  std::cout << "Capacity after clear: " << randomNumbers.capacity() << std::endl;
  if(randomNumbers.empty()) {
    std::cout << "Vector is empty after clear." << std::endl;
  } else {
    std::cout << "Vector is not empty after clear." << std::endl;
  }


  // Repopulate vector with new random numbers
  std::cout << "\nRepopulating vector with new random numbers:" << std::endl; 
  for (int i = 0; i < AMOUNT_NUMBERS; ++i) {
    randomNumbers.push_back(randomNumber(rng));
  }
  result = displayVector(randomNumbers);

  //
  std::cout << "\nInsert new element 69 at index 10:" << std::endl; 
  randomNumbers.insert(randomNumbers.begin() + 10, 69);
  result = displayVector(randomNumbers);

  // Erase element at index 24
  std::cout << "\nErase element at index 24:" << std::endl;
  randomNumbers.erase(randomNumbers.begin() + 24);
  result = displayVector(randomNumbers);  

  // Remove last element
  std::cout << "\nPop (remove) last element:" << std::endl;
  randomNumbers.pop_back();
  result = displayVector(randomNumbers);
    
  std::cout << std::endl;
  return 0;
}