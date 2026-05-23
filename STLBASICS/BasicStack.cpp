/*
 * BasicStack.cpp
 *
 *  Created on: May 23, 2026
 *      Author: rodney
 */

 #include <iostream>
 #include <stack>

int main() {
    std::stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Display the top element
    std::cout << "Top element: " << myStack.top() << std::endl;

    // Pop an element from the stack
    myStack.pop();
    std::cout << "Top element after pop: " << myStack.top() << std::endl;

    // Check if the stack is empty
    if (myStack.empty()) {
        std::cout << "The stack is empty." << std::endl;
    } else {
        std::cout << "The stack is not empty." << std::endl;
    }

    return 0;
} 