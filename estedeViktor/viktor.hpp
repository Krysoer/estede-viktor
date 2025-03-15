#pragma once
#ifndef VIKTOR_HPP
#define VIKTOR_HPP

#include <stdexcept>
#include <initializer_list>
#include <algorithm>

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
        constexpr bool empty() const noexcept; // returns true if no spaces are populated else returns false
        constexpr size_t getsize() const noexcept; // returns the number of populated spaces
        constexpr size_t getcapacity() const noexcept; // returns the number of spaces allocated for type T

        // Element Access
        constexpr T& operator[](size_t index); // modify element at index
        constexpr const T& operator[](size_t index) const; // get element at index
        constexpr T& at(size_t index); // same as operator[] but with bounds check (throws std::out_of_range)
        constexpr const T& at(size_t index) const; // same as operator[] but with bounds check (throws std::out_of_range)

        // Modifiers
        constexpr void PushBack(const T& element); // Push element after the last
        constexpr void PopBack(); // Remove last element (doesn't do any fancy deallocating, assumes the index may be still used in the future)
        constexpr void Erase(size_t index); // erase element at index
        constexpr void Insert(size_t index, const T& element); // inserts element at index
        constexpr void Clear() noexcept; // clears array (doesn't do any fancy deallocating, assumes the allocated space may be still used in the future)
        constexpr void ClearButFancy(); // deallocates the whole array
        constexpr void Resize(size_t newSize); // resizes the array, throws std::out_of_range when less than current size
        constexpr void ShrinkToFit(); // shrinks capacity to size
        constexpr void SwapViktor(viktor<T>& other) noexcept;//swap contents (and size if needed) of viktors

        // Assignment Operator
        constexpr viktor& operator=(const viktor& src); // assigns the elements, size, and capacity (if dest is lower) from the right hand side viktor
        //Algorithms
        constexpr void BubbleSort() noexcept;
        constexpr void BubbleRsort() noexcept;
    };

    // Include the template definitions
    #include "viktor.inl"
}

#endif