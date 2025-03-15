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
	estede::viktor<float> vec2(vec);
	std::cout << "\n\n\n";
	std::cout << vec2.at(3) << ' ' << vec2.getsize() << ' ' << vec2.getcapacity() << '\n';
	estede::viktor<int> abc = { 2,3,4,5 };
	std::cout << "\n\n\n";
	std::cout << "Size: " << abc.getsize() << " Capacity: " << abc.getcapacity() << '\n';
	for (int i = 0; i < abc.getsize(); i++) {
		std::cout << abc.at(i) << '\n';
	}
	std::cout << "\n\n\n";
	abc.ShrinkToFit();
	std::cout << "Size: " << abc.getsize() << " Capacity: " << abc.getcapacity() << '\n';
	for (int i = 0; i < abc.getsize(); i++) {
		std::cout << abc.at(i) << '\n';
	}
	std::cout << "\n\n\n";
	estede::viktor<int> a{45747541, 2123, 33, 4312, 5, 6, 318723217, 7, 1328, 7548, 8855, 8, 4588, 4597897, 888, 8897888, 888};
	estede::viktor<int> b{2, 45377547, 5, 34574572, 2978, 745432, 47545745, 74554, 665454 };
	for (size_t i = 0; i < a.getsize(); i++) {
		std::cout << "vec a, index: " << i << " val: " << a.at(i) << '\n';
	}
	for (size_t i = 0; i < b.getsize(); i++) {
		std::cout << "vec b, index: " << i << " val: " << b.at(i) << '\n';
	}
	a.SwapViktor(b);
	std::cout << "\n\n\n";
	for (size_t i = 0; i < a.getsize(); i++) {
		std::cout << "vec a, index: " << i << " val: " << a.at(i) << '\n';
	}
	for (size_t i = 0; i < b.getsize(); i++) {
		std::cout << "vec b, index: " << i << " val: " << b.at(i) << '\n';
	}
	a.BubbleSort();
	std::cout << "\n\n\n";
	std::cout << "\n\n\n";
	for (size_t i = 0; i < a.getsize(); i++) {
		std::cout << "vec a, index: " << i << " val: " << a.at(i) << '\n';
	}
	std::cout << "\n\n\n";
	std::cout << "\n\n\n";
	b.BubbleRsort();
	for (size_t i = 0; i < b.getsize(); i++) {
		std::cout << "vec b, index: " << i << " val: " << b.at(i) << '\n';
	}


	return 0;
}