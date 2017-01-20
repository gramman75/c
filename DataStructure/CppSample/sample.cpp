#include <iostream>
#include <string>


void greeting(char *name) {
	std::cout << "Hello " << name << std::endl;
}
void main(void) {
	std::cout << "Hello Wordl!"<<std::endl;

	greeting("Kim");
}