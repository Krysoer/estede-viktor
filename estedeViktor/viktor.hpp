#pragma once
constexpr size_t STANDARD_VEC_SIZE = 10;
namespace estede {
	template <typename T>
	class viktor {
	private:
		size_t capacity;//number of spaces allocated for type T
		size_t size;//number of populated spaces
		T* elements;//heap allocated c-style array
	public:
		viktor();//default constructor, allocates 10 spaces for type T
		viktor(size_t capacity);//allocates (capacity) spaces for type T
		viktor(size_t capacity, const T& base);//allocates (capacity) spaces for type T and populates them with (base)
		viktor(const viktor& src);//copy constructor v(src);
		~viktor();//cleans up the heap allocated array

		bool empty() const;//returns true if no spaces are populated else returns false
		size_t size() const;//returns the number of populated spaces
		size_t capacity() const;//returns the number of spaces allocated for type T

		T& operator[](size_t index);//modify element at index
		const T& operator[](size_t index) const;//get element at index
		viktor& operator=(const viktor& src);//todo

		void PushBack(const T& element);//Push element after the last
		void PopBack();//Remove last element
		void Erase(size_t index);//Remove element at index
		void Insert(size_t index);//Insert element at index
		void Resize(size_t newCapacity);//Resizes the array




	};
}