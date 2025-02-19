#pragma once
#ifndef VIKTOR_HPP
#define VIKTOR_HPP

#include <stdexcept>
#include <initializer_list>

constexpr size_t STANDARD_VEC_SIZE = 10ll;

namespace estede {
    template <typename T>
    class viktor {
    private:
        size_t capacity; // number of spaces allocated for type T
        size_t size;     // number of populated spaces
        T* elements;     // ptr to heap allocated c-style array

    public:
        // Constructors and Destructor
        viktor(); // default constructor, allocates 10 spaces for type T
        viktor(size_t capacity); // allocates (capacity) spaces for type T
        viktor(size_t length, const T& base); // allocates (capacity) spaces for type T and populates them with (base)
        viktor(const viktor& src); // copy constructor v(src)
        viktor(std::initializer_list<T> list); // constructor from initializer list
        ~viktor(); // cleans up the heap allocated array

        // Capacity and Size
        bool empty() const; // returns true if no spaces are populated else returns false
        size_t getsize() const; // returns the number of populated spaces
        size_t getcapacity() const; // returns the number of spaces allocated for type T

        // Element Access
        T& operator[](size_t index); // modify element at index
        const T& operator[](size_t index) const; // get element at index
        T& at(size_t index); // same as operator[] but with bounds check (throws std::out_of_range)
        const T& at(size_t index) const; // same as operator[] but with bounds check (throws std::out_of_range)

        // Modifiers
        void PushBack(const T& element); // Push element after the last
        void PopBack(); // Remove last element (doesn't do any fancy deallocating, assumes the index may be still used in the future)
        void Erase(size_t index); // erase element at index
        void Insert(size_t index, const T& element); // inserts element at index
        void Clear(); // clears array (doesn't do any fancy deallocating, assumes the allocated space may be still used in the future)
        void ClearButFancy(); // deallocates the whole array
        void Resize(size_t newSize); // resizes the array, throws std::out_of_range when less than current size
        void ShrinkToFit(); // shrinks capacity to size

        // Assignment Operator
        viktor& operator=(const viktor& src); // assigns the elements, size, and capacity (if dest is lower) from the right hand side viktor
    };

    // Include the template definitions
    #include "viktor.inl"
}

#endif