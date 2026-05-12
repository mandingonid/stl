#include <iostream>
#include <string>


int main(int argc, char *argv[]){
	
	int result;
	
	std::string  sPad("mike");
	sPad += "asdjklqwerucvpozxcm137d";
	sPad += "123asd456jkl765eryti432";
	sPad += "Now is the time for all good men to come to the aide of their country";
	sPad.append("\0");
	std::cout << &sPad << std::endl;
	std::cout << sPad.data() << std::endl;
	
	result = 0;
	return result;
	
}