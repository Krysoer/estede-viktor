#include <iostream>
#include <stdexcept>
#include "viktor.hpp"

estede::viktor<float> vec(10,3.5f);

int main(int argc, char** argv) {
	
	vec.Insert(3, 4.5f);
	std::cout << vec.at(3) << ' ' << vec.getsize() << ' ' << vec.getcapacity() << '\n';
	for (int i = 0; i < vec.getsize(); i++) {
		std::cout << vec.at(i) << '\n';
	}
	vec.Erase(0);
	std::cout << "\n\n\n";
	for (int i = 0; i < vec.getsize(); i++) {
		std::cout << vec.at(i) << '\n';
	}
	estede::viktor<float> vec2 = vec;
	std::cout << "\n\n\n";
	std::cout << vec2.at(3) << ' ' << vec2.getsize() << ' ' << vec2.getcapacity() << '\n';
	estede::viktor<int> abc = { 2,3,4,5 };
	for (int i = 0; i < abc.getsize(); i++) {
		std::cout << abc.at(i) << '\n';
	}
	return 0;
}