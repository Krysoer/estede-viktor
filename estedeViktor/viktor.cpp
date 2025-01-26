#include "viktor.hpp"
namespace estede {
	template <typename T>
	class viktor {
	private:
		size_t capacity;
		size_t size;
		T* elements;
	public:
		viktor() {
			this->size = 0;
			this->capacity = STANDARD_VEC_SIZE;
			this->elements = new T[capacity];
		}
		viktor(size_t capacity) {
			this->size = 0;
			this->capacity = capacity;
			this->elements = new T[capacity];

		}
		viktor(size_t length, const T& base) {
			this->size = length;
			this->capacity = length*2;
			this->elements = new T[capacity];
			for (int i = 0; i < size; i++) {
				elements[i] = base;
			}

		}
		viktor(const viktor& src) {
			if (this->capacity < src.size) {
				this->capacity = src.capacity;
			}
			this->size = src.size;
			this->elements = new T[capacity];
			for (int i = 0; i < size; i++) {
				this->elements[i] = src.elements[i];
			}
		}
		~viktor() {
			delete[] elements;
		}

		bool empty() const {
			return size == 0;
		}
		size_t size() const {
			return size;
		}
		size_t capacity() const {
			return capacity;
		}

		T& operator[](size_t index);
		const T& operator[](size_t index) const;
		viktor& operator=(const viktor& src);

		void PushBack(const T& element);
		void PopBack();
		void Erase(size_t index);
		void Insert(size_t index);
		void Resize(size_t index);




	};
}