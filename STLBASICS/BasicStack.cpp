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
    myStack.push(1);
    myStack.push(3);
    myStack.push(5);
    myStack.push(7);
    myStack.push(11);
    myStack.push(13);
    myStack.push(17);
    myStack.push(19);
    myStack.push(23);
    myStack.push(29);
    myStack.push(31); 
    myStack.push(37);
    myStack.push(41);
    myStack.push(43);
    myStack.push(47);
    myStack.push(53);
    myStack.push(59);
    myStack.push(61);
    myStack.push(67);
    myStack.push(71);
    myStack.push(73);
    myStack.push(79);
    myStack.push(83);
    myStack.push(89);
    myStack.push(97);   

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