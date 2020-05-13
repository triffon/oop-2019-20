

template <typename T>
void Set<T>::copy(const Set<T>& s) {
	this->size = s.size;
	this->capacity = s.capacity;
	this->data = new T[this->capacity];

	for (int i = 0; i < this->size; i++) {
		this->data[i] = s.data[i];
	}
}

template <typename T>
void Set<T>::erase() {
	delete[] this->data;
}

template <typename T>
void Set<T>::resize() {
	this->capacity *= 2;
	T* oldData = data;
	this->data = new T[this->capacity];\

	for (int i = 0; i < this->size; i++) {
		this->data[i] = oldData[i];
	} 

	delete[] oldData;
}

template <typename T>
Set<T>::Set() {
	this->capacity = SET_INITIAL_CAPACITY;
	this->size = 0;
	this->data = new T[this->capacity];
}

template <typename T>
Set<T>::Set(const Set<T>& s) {
	copy(s);
}


template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& other) {
	if (&other != this) {
		erase();
		copy(other);
	}
	return *this;
}

template <typename T>
Set<T>::~Set<T>() {
	erase();
}

template <typename T>
int Set<T>::getSize() const {
	return size;
}


template <typename T>
bool Set<T>::add(T element) {
	if (contains(element)) {
		return false;
	}

	if (size >= capacity) {
		resize();
	}

	data[size++] = element;

	return true;
}

template <typename T>
bool Set<T>::contains(T element) const {
	for (int i = 0; i < size; i++) {
		if (data[i] == element) {
			return true;
		}
	}

	return false;
}

template <typename T>
bool Set<T>::isEmpty() {
	return (size == 0);
}


template <typename T>
bool Set<T>::remove(T element) {
	if (!contains(element)) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (data[i] == element) {
			for (int j = i; j < size - 1; j++) {
				data[j] = data[j + 1];
			}
			size--;
			data[size] = T();
			break;
		}
	}

	return true;
}

template <typename T>
T Set<T>::operator[](const int index) const {
	if (index >= size) {
		cerr << "Index out of bound" << endl;
	}
	return data[index];
}


template <typename T>
bool Set<T>::operator==(const Set<T>& other) const {
	if (size != other.size) {
		return false;
	}

	if (capacity != other.capacity) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (!contains(other.data[i])) {
			return false;
		}
	}

	return true;
}

template <typename T>
Set<T> Set<T>::operator+(const Set<T>& other) const {
	Set<T> set = *this;

	for (int i = 0; i < other.size; i++) {
		set.add(other.data[i]);
	}

	return set;
}

template <typename T>
Set<T> Set<T>::operator*(const Set<T>& other) const {
	Set<T> set;

	for (int i = 0; i < this->size; i++) {
		if (other.contains(data[i])) {

			set.add(data[i]);
		}
	}

	return set;
}

template <typename T>
Set<T> Set<T>::operator-(const Set<T>& other) const {
	Set<T> set = *this;

	for (int i = 0; i < other.size; i++) {
		set.remove(other.data[i]);
	}

	return set;
}

template <typename T>
ostream& operator<<(ostream& os, const Set<T>& set) {
	for (int i = 0; i < set.getSize(); i++) {
		os << set[i] << " ";
	}

	return os;
}


