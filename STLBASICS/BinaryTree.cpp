/*
 * BinaryTree.cpp
 *
 *  Created on: May 20, 2026
 *      Author: rodney
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>
#include <list>
#include <tuple>


struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int val) : value(val), left(nullptr), right(nullptr) {}
};  

// Function to display contents of a vector
int displayVector(const std::vector<int>& vec) {
  for (const auto& num : vec) {
    std::cout << num << " ";  
  }
  std::cout << std::endl;
  return 0;
}


class BinaryTree {

public:
  BinaryTree() : root(nullptr) {}   

  void insert(int value) {
    root = insertRec(root, value);
  }                         

  void inorder() {
    inorderRec(root);
  }       
 
  

private:  Node* insertRec(Node* node, int value) {
    if (node == nullptr   ) {
      return new Node(value);
    }
    if (value < node->value) {
      node->left = insertRec(node->left, value);
    } else {
      node->right = insertRec(node->right, value);
    }
    return node;
  }

  void inorderRec(Node* node) {
    if (node != nullptr) {
      inorderRec(node->left);
      std::cout << node->value << " ";
      inorderRec(node->right);
    }
  }  

  Node* root;     

};                  

int main(int argc, char* argv[]){   
  
  const int AMOUNT_NUMBERS = 37;
  int result = -1;
  std::mt19937 rng;
  // Seed the engine with a non-deterministic seed for better randomness
  std::random_device rd;
  rng.seed(rd());

  std::uniform_int_distribution<> randomNumber(0, AMOUNT_NUMBERS);
  std::vector<int> randomNumbers;  
  
  BinaryTree tree;

  for (int index = 0; index < AMOUNT_NUMBERS; ++index) {
    int num = randomNumber(rng);
    randomNumbers.push_back(num);
    // **** tree.insert(num);
  }                                                                                             

  std::vector<int> scratchVector = randomNumbers; // Sorts the vector and returns the median value, but we ignore the return value here
  result = displayVector(randomNumbers); // Display the random numbers in the vector  
  // **** std::cout << "Median value: " << median << std::endl; // Display the median value 
  result = displayVector(scratchVector); // Display the sorted random numbers in the scratch vector
  std::sort(scratchVector.begin(), scratchVector.end()); // Sort the scratch vector to get the median value
  int median = scratchVector[scratchVector.size() / 2]; // Get the median value from the sorted scratch vector
  std::cout << "\nMedian value: " << median << std::endl; // Display the median value
  result = displayVector(scratchVector); // Display the sorted random numbers in the scratch vector again after sorting 

  tree.insert(median); // Insert the median value into the binary tree

  for (const auto& loadNumber : randomNumbers) {
    tree.insert(loadNumber);  // Insert the random numbers into the binary tree
  }

  std::cout << "\nInorder traversal: ";
  tree.inorder();
  std::cout << std::endl;

  return 0;
} 

