#include <iostream>
#include <string>


int main(int argc, char *argv[]){
	
	int result;
	
	std::string  sPad("mike");
	sPad += "asdjklqwerucvpozxcm137d";
	std::cout << sPad.size() << std::endl;
	sPad += "123asd456jkl765eryti432";
	std::cout << sPad.size() << std::endl;
	sPad += "Now is the time for all good men to come to the aide of their country";
	std::cout << sPad.size() << std::endl;
	sPad.append("\0");
	std::cout << &sPad << std::endl;
	std::cout << sPad.data() << std::endl;
	
	sPad.shrink_to_fit();
	std::cout << sPad.capacity() << std::endl;
	std::cout << std::endl;


	result = 0;
	return result;
	
}
