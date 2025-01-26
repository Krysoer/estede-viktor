#include <iostream>
#include <stdexcept>
#include "viktor.hpp"

estede::viktor<float> vec(2,2.0f);

int main(int argc, char** argv) {
	std::cout << vec.getcapacity() <<'\n';
	vec.PushBack(2.5f);
	std::cout << vec.getcapacity() <<'\n';
	vec.PushBack(2.5f);
	std::cout << vec.getcapacity() <<'\n';
	vec.PushBack(2.5f);
	std::cout << vec.getcapacity() << '\n';
	vec.PushBack(2.5f);
	std::cout << vec.getcapacity() <<'\n';
	vec.PushBack(2.5f);
	std::cout << vec.getcapacity() << '\n';
	vec.PushBack(2.5f);
	std::cout << vec.getcapacity() << '\n';
	vec.PushBack(2.5f);
	std::cout << vec.getcapacity() << '\n';
	vec.PushBack(2.5f);
	std::cout << vec.getcapacity() << '\n';
	for (int i = 0; i < vec.getsize(); i++) {
		std::cout << vec.at(i) << '\n';
	}
	return 0;
}