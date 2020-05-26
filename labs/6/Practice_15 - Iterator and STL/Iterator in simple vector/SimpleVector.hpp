#include <iostream>


template <typename T>
class MyVector
{
public:
	class iterator {
	public:
		T* it;

		explicit iterator(T* elements) : it(elements) {};

	public:
		iterator<T>& operator++() {
			++this->it;
			return *this;
		}
		const iterator<T> operator++(int) {
			iterator it(*this);
			this->operator++();
			return it;
		}

		iterator<T>& operator--() {
			--this->it;
			return *this;
		}
		const iterator<T> operator--(int) {
			iterator it(*this);
			this->operator--();
			return it;
		}

		inline bool operator==(const iterator<T>& other) const { return it == other.it; }
		inline bool operator!=(const iterator<T>& other) const { return !(*this == other); }
		inline bool operator<(const iterator<T>& other) const { return it < other.it; }
		inline bool operator>(const iterator<T>& other) const { return *this < other; }
		inline bool operator<=(const iterator<T>& other) const { return !(*this > other); }
		inline bool operator>=(const iterator<T>& other) const { return !(*this < other); }


		inline T* operator->() { return (this->it); }
		inline T& operator*() { return *(this->it); }

	};

private:
	T* elements;
	size_t size;
	size_t capacity;

public:
	MyVector<T>( size_t capacity );
	MyVector<T>( const MyVector<T>& other );
	MyVector<T>& operator=( const MyVector<T>& other );
	~MyVector<T>();

	iterator<T> begin() const { return iterator<T>(elements); }
	iterator<T> end() const { return iterator<T>(elements+size); }

	size_t getSize() const
	{
		return size;
	}
private:
	void resize( size_t newSize );
	void copy( const MyVector<T>& other );


	
public:
	void push_back(T element );
	T& pop_back();
	T& pop_front();

	const T operator[](size_t) const;
	T&operator[](size_t);
};


template <typename T>
MyVector<T>::MyVector(size_t cap) : capacity(cap) {
	elements = new T[capacity];
}

template <typename T>
void MyVector<T>::copy(const MyVector<T>& other) {

	elements = new T[other.size];
	capacity = other.capacity;

	for (size_t i = 0; i < size; i++)
		elements[i] = other.elements[i];

}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& vec) {
	copy(vec);
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
	if(this != &other) {
		delete[] elements;
		copy(other);
	}
	return *this;
}

template <typename T>
MyVector<T>::~MyVector() {
	delete[] elements;
}

template <typename T>
void MyVector<T>::resize(size_t newSize) {
	if (coeff == nullptr) {

		coeff = new T[newSize];
		maxDeg = newSize;
	} else {

		T* old = coeff;
		coeff = new T[newSize];

		for (size_t i = 0; i < maxDeg; i++)
			coeff[i] = old[i];

		delete[] old;
		maxDeg = newSize;
	}
}

template<typename T>
void MyVector<T>::push_back(T element) {
	if(size >= capacity) {
		size_t newCap = (capacity == 0) ? 2 : capacity*2;
		resize(newCap);
	}
	data[size++] = element;
}

template<typename T>
T& MyVector<T>::pop_back() {
	T element;
	if(size > 0) {
		element = data[size--];
		if(size <= capacity/4) {
			resize(capacity/2);
		}
	}

	return element;
}

template<typename T>
T& MyVector<T>::pop_front() {
	T element;
	if(size > 0) {
		element = data[0];
		for (int i = 0; i < size-1; ++i) {
			data[i] = data[i+1];
		}
		if(size <= capacity/4) {
			resize(capacity/2);
		}
	}

	return element;
}

template<typename T>
const T MyVector<T>::operator[](size_t pos) const {
	if(size >= pos) {
		throw std::out_of_range("out of range");
	}
	return data[pos];
}

template<typename T>
T& MyVector<T>::operator[](size_t pos) {
	if(pos >= size) {
		resize(pos+1);
	}
	return data[pos];
}


int main()
{
	MyVector<int> vec(5);
	for ( int i = 0; i < 10; ++i )
	{
		vec.push_back( i );
	}

	for ( size_t i = 0; i < vec.getSize(); ++i )
	{
		std::cout << vec[ i ] << ' ';
	}

	for ( int i = vec.getSize() - 1; i >= 0; --i )
	{
		std::cout << vec[ i ] << ' ';
	}

	for ( MyVector<int>::iterator it = vec.begin(); it != vec.end(); ++it )
	{
		std::cout << *it << ' ';
	}

	for ( MyVector<int>::iterator it = vec.end() - 1; it >= vec.begin(); --it )
	{
		std::cout << *it << ' ';
	}

	MyVector<int>::iterator it = vec.begin();
	for ( MyVector<int>::iterator it : vec )
	{
		std::cout << *it << ' ';
	}

	return 0;
}