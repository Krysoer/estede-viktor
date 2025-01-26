#pragma once
#ifndef VIKTOR_HPP
#define VIKTOR_HPP
#include <stdexcept>
constexpr size_t STANDARD_VEC_SIZE = 10;
namespace estede {
	template <typename T>
	class viktor {
	private:
		size_t capacity;//number of spaces allocated for type T
		size_t size;//number of populated spaces
		T* elements;//heap allocated c-style array
	public:
		viktor() {//default constructor, allocates 10 spaces for type T
			this->size = 0;
			this->capacity = STANDARD_VEC_SIZE;
			this->elements = new T[capacity];
		}
		viktor(size_t capacity) {//allocates (capacity) spaces for type T
			this->size = 0;
			this->capacity = capacity;
			this->elements = new T[capacity];

		}
		viktor(size_t length, const T& base) {//allocates (capacity) spaces for type T and populates them with (base)
			this->size = length;
			this->capacity = length*2;
			this->elements = new T[capacity];
			for (int i = 0; i < size; i++) {
				elements[i] = base;
			}

		}
		viktor(const viktor& src) {//copy constructor v(src);
			this->capacity = src.capacity;
			this->elements = new T[capacity];
			this->size = src.size;
			for (int i = 0; i < size; i++) {
				this->elements[i] = src.elements[i];
			}
		}
		~viktor() {//cleans up the heap allocated array
			delete[] elements;
		}

		bool empty() const {//returns true if no spaces are populated else returns false
			return size == 0;
		}
		size_t getsize() const {//returns the number of populated spaces
			return size;
		}
		size_t getcapacity() const {//returns the number of spaces allocated for type T
			return capacity;
		}

		T& operator[](size_t index) {//modify element at index
			return elements[index];
		}
		const T& operator[](size_t index) const {//get element at index
			return elements[index];
		}
		viktor& operator=(const viktor& src) {//assigns the elements, size, and capacity (if dest is lower) from the right hand side vector
			if (this->capacity < src.capacity) {
				this->capacity = src.capacity;
			}
			this->size = src.size;
			delete[] elements;
			this->elements = new T[capacity];
			for (int i = 0; i < size; i++) {
				this->elements[i] = src.elements[i];
			}

		}
		T& at(size_t index) {//same as operator[] but with bounds check (throws std::out_of_range)
			if (index >= capacity) {
				throw std::out_of_range("Attempted to access index out of bounds");
			}
			else [[likely]] {
				return elements[index];
				}
		}
		const T& at(size_t index) const {//same as operator[] but with bounds check (throws std::out_of_range)
			if (index >= size) {
				throw std::out_of_range("Attempted to access index out of bounds");
			}
			else [[likely]]{
				return elements[index];
			}
		}

		void PushBack(const T& element) {//Push element after the last
			if (size == capacity) {
				#ifdef _MSC_VER//MSVC resizes the array by 1.5 times while most other vector implementations (clang, GCC) resize by 2x
				if (capacity < 2)
					capacity = 2;
				capacity *= 1.5;
				T* temp = new T[capacity];
				#else
				if (capacity < 2)
					capacity = 2;
				capacity *= 2;
				T* temp = new T[capacity];
				#endif
				for (int i = 0; i < size; i++) {
					temp[i] = elements[i];
				}
				delete[] elements;
				elements = temp;
			}
			elements[size] = element;
			size++;
		}
		void PopBack() {//Remove last element (doesn't do any fancy deallocating, assumes the index may be still used in the future)
			if (size > 0)
				size--;
			else
				throw std::out_of_range("why dude");
		}
		void Erase(size_t index) {
			for (int i = index; i < size-1; i++) {
				elements[i] = elements[i + 1];
			}
			size--;
		}//erase element at index
		void Insert(size_t index, const T& element) {
			if (size == capacity) {
				#ifdef _MSC_VER//MSVC resizes the array by 1.5 times while most other vector implementations (clang, GCC) resize by 2x
				if (capacity < 2)
					capacity = 2;
				capacity *= 1.5;
				T* temp = new T[capacity];
				#else
				if (capacity < 2)
					capacity = 2;
				capacity *= 2;
				T* temp = new T[capacity];
				#endif
				for (int i = 0; i < size; i++) {
					temp[i] = elements[i];
				}
				delete[] elements;
				elements = temp;
			}
			for (int i = index; i < size; i++) {
				elements[i + 1] = elements[i];
			}
			elements[index] = element;
		}
		void Clear() {//clears array (doesn't do any fancy deallocating, assumes the allocated space may be still used in the future)
			size = 0;
		}
		void Resize(size_t newSize) {//resizes the array, throws std::out_of_range when less than size
			if (newSize >= size) {
				this->capacity = newSize;
				T* temp = new T[capacity];
				for (int i = 0; i < size; i++) {
					temp[i] = elements[i];
				}
				delete[] elements;
				elements = temp;
			}
			else
				throw std::out_of_range("Viktor resize failed");
		}
		void ShrinkToFit() {//shrinks capacity to size
			capacity = size;
			T* temp = new T[capacity];
			for (int i = 0; i < size; i++) {
				temp[i] = elements[i];
			}
			delete[] elements;
			elements = temp;
		}
	};
}
#endif