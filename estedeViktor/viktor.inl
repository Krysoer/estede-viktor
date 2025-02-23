// Constructors and Destructor
template <typename T>
estede::viktor<T>::viktor() : size(0ll), capacity(STANDARD_VEC_SIZE), elements(new T[STANDARD_VEC_SIZE]) {}

template <typename T>
estede::viktor<T>::viktor(size_t capacity) : size(0ll), capacity(capacity), elements(new T[capacity]) {}

template <typename T>
estede::viktor<T>::viktor(size_t length, const T& base) : size(length), capacity(length * 2ll), elements(new T[length * 2ll]) {
    for (size_t i = 0ll; i < size; i++) {
        elements[i] = base;
    }
}

template <typename T>
estede::viktor<T>::viktor(const viktor& src) : capacity(src.capacity), size(src.size), elements(new T[src.capacity]) {
    for (size_t i = 0ll; i < size; i++) {
        elements[i] = src.elements[i];
    }
}

template <typename T>
estede::viktor<T>::viktor(std::initializer_list<T> list) : size(list.size()), capacity(list.size() * 2), elements(new T[list.size() * 2ll]) {
    size_t iter = 0ll;
    for (const T& val : list) {
        elements[iter] = val;
        iter++;
    }
}

template <typename T>
estede::viktor<T>::~viktor() {
    delete[] elements;
}

// Capacity and Size
template <typename T>
bool estede::viktor<T>::empty() const {
    return size == 0ll;
}

template <typename T>
size_t estede::viktor<T>::getsize() const {
    return size;
}

template <typename T>
size_t estede::viktor<T>::getcapacity() const {
    return capacity;
}

// Element Access
template <typename T>
T& estede::viktor<T>::operator[](size_t index) {
    return elements[index];
}

template <typename T>
const T& estede::viktor<T>::operator[](size_t index) const {
    return elements[index];
}

template <typename T>
T& estede::viktor<T>::at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Attempted to access index out of bounds");
    }
    else [[likely]] {
        return elements[index];
        }
}

template <typename T>
const T& estede::viktor<T>::at(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Attempted to access index out of bounds");
    }
    else [[likely]] {
        return elements[index];
        }
}

// Modifiers
template <typename T>
void estede::viktor<T>::PushBack(const T& element) {
    if (size == capacity) [[unlikely]] {
        // MSVC resizes the array by 1.5 times while most other vector implementations (clang, GCC) resize by 2x
        #ifdef _MSC_VER
        if (capacity < 2ll)
            capacity = 2ll;
        capacity *= 1.5;
        T* temp = new T[capacity];
        #else
        if (capacity < 2ll)
            capacity = 2ll;
        capacity *= 2ll;
        T* temp = new T[capacity];
        #endif
        for (size_t i = 0ll; i < size; i++) {
            temp[i] = elements[i];
        }
        delete[] elements;
        elements = temp;
    }
    elements[size] = element;
    size++;
}

template <typename T>
void estede::viktor<T>::PopBack() {
    if (size > 0ll) [[likely]] {
        size--;
    }
    else {
        throw std::out_of_range("why dude");
    }
}

template <typename T>
void estede::viktor<T>::Erase(size_t index) {
    for (size_t i = index; i < size - 1ll; i++) {
        elements[i] = elements[i + 1ll];
    }
    size--;
}

template <typename T>
void estede::viktor<T>::Insert(size_t index, const T& element) {
    if (size == capacity) [[unlikely]] {
        // MSVC resizes the array by 1.5 times while most other vector implementations (clang, GCC) resize by 2x
        #ifdef _MSC_VER
        if (capacity < 2ll)
            capacity = 2ll;
        capacity *= 1.5;
        T* temp = new T[capacity];
        #else
        if (capacity < 2ll)
            capacity = 2ll;
        capacity *= 2ll;
        T* temp = new T[capacity];
        #endif
        for (size_t i = 0ll; i < size; i++) {
            temp[i] = elements[i];
        }
        delete[] elements;
        elements = temp;
    }
    for (size_t i = index; i < size; i++) {
        elements[i + 1ll] = elements[i];
    }
    elements[index] = element;
    size++;
}

template <typename T>
void estede::viktor<T>::Clear() {
    size = 0;
}

template <typename T>
void estede::viktor<T>::ClearButFancy() {
    size = 0ll;
    capacity = 0ll;
    T* temp = new T[capacity];
    delete[] elements;
    elements = temp;
}

template <typename T>
void estede::viktor<T>::Resize(size_t newSize) {
    if (newSize >= size) [[likely]] {
        capacity = newSize;
        T* temp = new T[capacity];
        for (size_t i = 0ll; i < size; i++) {
            temp[i] = elements[i];
        }
        delete[] elements;
        elements = temp;
    }
    else {
        throw std::out_of_range("Viktor resize failed");
    }
}

template <typename T>
void estede::viktor<T>::ShrinkToFit() {
    capacity = size;
    T* temp = new T[capacity];
    for (size_t i = 0ll; i < size; i++) {
        temp[i] = elements[i];
    }
    delete[] elements;
    elements = temp;
}

// Assignment Operator
template <typename T>
estede::viktor<T>& estede::viktor<T>::operator=(const viktor& src) {
    if (this->capacity < src.capacity) {
        this->capacity = src.capacity;
    }
    this->size = src.size;
    delete[] elements;
    this->elements = new T[capacity];
    for (size_t i = 0ll; i < size; i++) {
        this->elements[i] = src.elements[i];
    }
    return *this;
}
