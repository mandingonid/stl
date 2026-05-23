#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <random>
#include <algorithm>

// Node structure definition
template <typename T>
struct Node {
    T value;
    std::shared_ptr<Node<T>> left;
    std::shared_ptr<Node<T>> right;
    int depth;

    Node(T val, int d = 0) : value(val), left(nullptr), right(nullptr), depth(d) {}
};

// MultiLevelTree class definition
template <typename T>
class MultiLevelTree {
private:

    // Internal binary tree insertion method with duplicate removal check
    void insertBST(std::shared_ptr<Node<T>> node, T val, int depth) {
        if (val == node->value) {
            return; // No duplicates allowed
        }
        else if (val < node->value) {
            if (!node->left) node->left = std::make_shared<Node<T>>(val, depth);
            else insertBST(node->left, val, depth + 1);
        } else {
            if (!node->right) node->right = std::make_shared<Node<T>>(val, depth);
            else insertBST(node->right, val, depth + 1);
        }
        
    }

    //
    void updateLevels() {
        if (!root) return;
        levels.clear();
        std::queue<std::shared_ptr<Node<T>>> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            std::vector<T> currentLevel;
            for (int index = 0; index < size; ++index) {
                auto node = q.front();
                q.pop();
                currentLevel.push_back(node->value);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levels.push_back(currentLevel);
        }
    }

/******************************************************************
 *  The traversal methods (inorder, preorder, postorder) and their reverse counterparts are implemented recursively.
 * ****************************************************************/
 

    // Recursive traversal method inorder
    void inorderRec(std::shared_ptr<Node<T>> node) {
        if (!node) return;
        inorderRec(node->left);
        std::cout << node->value << " ";
        inorderRec(node->right);
    }

    // Recursive traversal method preorder
    void preorderRec(std::shared_ptr<Node<T>> node) {
        if (!node) return;
        std::cout << node->value << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    // Recursive traversal method postorder
    void postorderRec(std::shared_ptr<Node<T>> node) {
        if (!node) return;
        postorderRec(node->left);
        postorderRec(node->right);
        std::cout << node->value << " ";
    }

    // Recursive traversal method reverse inorder
    void reverseInorderRec(std::shared_ptr<Node<T>> node) {
        if (!node) return;
        inorderRec(node->right);
        std::cout << node->value << " ";
        inorderRec(node->left);
    }

    // Recursive traversal method reverse preorder
    void reversePreorderRec(std::shared_ptr<Node<T>> node) {
        if (!node) return;
        std::cout << node->value << " ";
        preorderRec(node->right);
        preorderRec(node->left);
    }

    // Recursive traversal method reverse postorder
    void reversePostorderRec(std::shared_ptr<Node<T>> node) {
        if (!node) return;
        postorderRec(node->right);
        postorderRec(node->left);
        std::cout << node->value << " ";
    }

public:
    MultiLevelTree() : root(nullptr) {}

    std::shared_ptr<Node<T>> root;
    std::vector<std::vector<T>> levels;

    // Public wrapper for traversal methods
    void inorder() { inorderRec(root); std::cout << std::endl; }
    void preorder() { preorderRec(root); std::cout << std::endl; }
    void postorder() { postorderRec(root); std::cout << std::endl; }
    void reverseInorder() { reverseInorderRec(root); std::cout << std::endl; }
    void reversePreorder() { reversePreorderRec(root); std::cout << std::endl; }
    void reversePostorder() { reversePostorderRec(root); std::cout << std::endl; }

    // Public method to insert values into the tree
    void insert(T val) {
        if (!root) 
        {
            root = std::make_shared<Node<T>>(val, 0);
        }
        else
        {
            insertBST(root, val, 1);
        }
        updateLevels();
    }


    // Method to print a vector (for debugging)
    void printVector(const std::vector<T>& vec) {
        for (const auto& val : vec) std::cout << val << " ";
        std::cout << std::endl;
    }

    // Method to print the graph levels
    void printGraph() {
        for (size_t index = 0; index < levels.size(); ++index) {
            std::cout << "Level " << index << ": ";
            for (const auto& val : levels[index]) std::cout << val << " ";
            std::cout << std::endl;
        }
    }

    // Method to calulate the median of random numbers
    int calculateMedian(std::vector<int>& nums) {
        std::cout << "Random Numbers: ";
        printVector(nums); // For debugging
        std::vector<int> scratchPad = nums;
        if (scratchPad.empty()) return 0;
        std::sort(scratchPad.begin(), scratchPad.end());
        size_t mid = scratchPad.size() / 2;
        return (scratchPad.size() % 2 == 0) ? (scratchPad[mid - 1] + scratchPad[mid]) / 2 : scratchPad[mid];
    }

};

int main() {
    MultiLevelTree<int> tree;
    // ... (Your existing initialization code)
    const int AMOUNT_NUMBERS = 201; // Reduced for cleaner output
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> randomNumber(0, 100);
    std::vector<int> randomNumbers;

    //
    for (int index = 0; index < AMOUNT_NUMBERS; index++){
        int num = randomNumber(rng);
        randomNumbers.push_back(num);
    }  

    // Calculate the median of the random numbers and initialize tree  
    int median = tree.calculateMedian(randomNumbers);
    std::cout << "Median: " << median << std::endl;
    std::cout << std::endl;
    tree.insert(median); // Insert the median as the root to ensure a balanced tree

    // Insert random values
    for (int index = 0; index < AMOUNT_NUMBERS; index++){
        tree.insert(randomNumbers[index]);
    }

    //
    tree.printGraph(); // Print the graph levels

    // Normal left to right traversals
    std::cout << "\nInorder Traversal (should be in ascending order):" << std::endl;
    tree.inorder();

    std::cout << "\nPreorder Traversal:" << std::endl;
    tree.preorder();

    std::cout << "\nPostorder Traversal:" << std::endl;
    tree.postorder();

    std::cout << "\nInorder Reverse Traversal (should be in ascending order):" << std::endl;
    tree.reverseInorder();
    std::cout << std::endl;

    std::cout << "\nPreorder Reverse Traversal:" << std::endl;
    tree.reversePreorder();

    std::cout << "\nPostorder Reverse Traversal:" << std::endl;
    tree.reversePostorder();

    return 0;
} 