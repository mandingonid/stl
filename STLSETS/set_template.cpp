#include <iostream>
#include <set>


int main(int argc, char *argvp[]){
	
	int result= -1;
	std::set<int> setA{1, 2, 3, 5, 7, 11, 5};
	setA.insert(1);
	setA.insert(2);
	setA.insert(-13);
	
	std::cout << "5?: " << setA.count(5) << std::endl;
	std::cout << "5? " << setA.contains(5) << std::endl;
	
	auto found = setA.find(7);
	if(found != setA.end()){
		for(auto index: setA)
			std::cout << index << std::endl;
		std::cout << "We guess " << *found <<  " is no longer lost" << std::endl;
		setA.erase(*found);
		std::cout << "Changed our minds and erased " << *found << std::endl;
		for(auto index: setA)
			std::cout << index << std::endl;
		result = 0;
	}
	
	return result;
	
}