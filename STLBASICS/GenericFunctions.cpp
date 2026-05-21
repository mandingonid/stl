/*
 * GenericFunctions.cpp
 *
 *  Created on: May 7, 2026
 *      Author: rodney
 */

#include <iostream>
#include <list>



//
template <typename T>
class Calculator {
public:
	//
	//  template <typename T>
	T add(T a, T b) {
		return a + b;
	}

	//
	//  template <typename T>
	T subtract(T a, T b){
		return a - b;
	}
	
	//
	//	template <typename T>
	T multiply(T a, T b){
		return a * b;
	}
	
	//
	// template <typename T>
	T divide(T a, T b){
		return a / b;
	}
	
};



/**********************************************************
* Main body of calculator program
***********************************************************/

int main(int argc, char* argv[]){
	
	Calculator<int> intHandDev;
	Calculator<float> floatHandDev;
	
	std::cout << intHandDev.add(9, 13) << std::endl;
	std::cout << floatHandDev.add(9.7, 13.8) << std::endl;
	
	std::cout << intHandDev.subtract(9, 13) << std::endl;
	std::cout << floatHandDev.subtract(9.7, 13.8) << std::endl;
	
	std::cout << intHandDev.multiply(9, 13) << std::endl;
	std::cout << floatHandDev.multiply(13.3, 17.7) << std::endl;

	std::cout << intHandDev.divide(28, 7) << std::endl;
	std::cout << floatHandDev.divide(43.7, 5.3) << std::endl;
	
	
	/*
	*	Implement List TemplateI sent the email to Ms Nguyen at housing and copied you so that you know I was working on it.

I got the email/letter from Conrad yesterday.  I am waiting on Ms. Nguyen, Thanks.;
	*/
	std::list<int> myList;
	myList.push_back(7);
	myList.push_back(