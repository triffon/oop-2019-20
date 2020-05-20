#include "Box.hpp"

// following code is NOT compilable, it's just for examples!!!
//========================================================

template<class U>
class VectorWithBoxes
{
	Box<U>* boxes;
};

//========================================================

template<class T> 
class Vector
{
	T* elements;
};

//========================================================

template<class T> 
class VectorWithPointers
{
	T** elements;
};

//========================================================

template<typename T>
class InsertItem
{
protected:
	int counter;
	T   destination; 

public:
	virtual void operator()(std::string item) {
		destination->Insert(item.c_str(), counter++);
	}

public:
	InsertItem(T argDestination) {
		counter = 0;
		destination = argDestination;
	}
};

template<typename T>
class InsertItem2 : InsertItem<T>
{
public:
	virtual void operator()(std::string item) {
		destination ->Insert2(item.c_str(), counter++, 0);
	}
};

//========================================================

template<typename T>
class Area
{
	T area;
};

class Rectangle : public Area<int>
{
	// ...
};

class Triangle : public Area<int>, public Area<double>
{
	// ...
};

template<typename T> 
class Square : public Area<T>
{
	// ...
};

//==========================================================

class Rectangle // not inheriting from any Area type
{
	// Area independent interface
};

template<typename T> 
class SpecificRectangle : public Rectangle, public Area<T>
{
	// Area dependent stuff
};

void foo(Rectangle&); // A function which works with generic rectangles

int main()
{
	SpecificRectangle<int> intrect;
	foo(intrect);

	SpecificRectangle<double> charrect;
	foo(charrect);
}

//==========================================================
// diamond problem
class Area
{
	// generic Area interface
};
template<typename U> 
class Rectangle : public virtual Area // virtual because of "diamond inheritance"
{
	// generic rectangle interface
};

template<typename T> 
class SpecificArea : public virtual Area
{
	// specific implementation of Area for type T
};

template<typename T, typename T> 
class SpecificRectangle :	public Rectangle<T>, // maybe this should be virtual as well, in case the hierarchy is extended later
							public SpecificArea<T> // no virtual inheritance needed here
{

	// specific implementation of Rectangle for type T
};

// ======================================================================
// default type for templates 
template <typename T = int>
class Foo
{

};

template<class T, class U = int> 
class A;

template<class T = float, class U> // we can not do that
class B;

template<class T, class U> 
class C 
{
public:
	T x;
	U y;
};

int main() {
	Foo f; // for C++17 and above
	Foo<> f; // for every standard of C++

	return 0;
}


