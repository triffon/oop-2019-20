## Inheritance
When we encounter "is a/an" type of relationships we use inheritance.
### Example:
Student "is a" Human.Then Student should inherit Human.  
In C++ we will write:  
```
Student : public Human
```
## Composition
Composition is basically putting something as member data. Data is usually an undivisible part of the object that contains it.  Thus we are responsible for its deallocation.(look for agregation below)  
When we encounter "has a/an" or "is part of" type of relationships we usually use composition.  
### Example:
Car "has an" engine
```
Thus:
class Car{
	Engine e;
	public:
		// some code here
}
```
## Aggregation
Pretty close to composition except that the data can exist without the object.    
Answers the questions "uses a/an" or sometimes "has a" (I feel the pain ツ)  
### Example
Person "uses a" car.

## OOP Fundamentals
* Abstraction
* Encapsulation
* Polymorphism
* Inheritance  
Pretty much tells us what a language should be able to do to be considered as an Object oriented language.

## Solid principles
* Single-responsibility principle  
  * A class must be responsible for one thing only.  
* Open–closed principle  
  * Every software component(class, functions,library) should be open for extension but closed for modification.  
* Liskov substitution principle  
  * Objects in a program should be replaceable with instances of their subtypes without altering the correctness of that program.  
* Interface segregation principle  
  * Many small specific interfaces are better than one big general-purpose interface.  
* Dependency inversion principle  
  * You should use/depend on abstractions(interfaces) not on concrete realisations of the abstractions.  
A set of good practices to create good software architecture. 

## Static functions and variables
Those are functions and variables that are part of the class instead of a part of a specific instance.  Or we could look at it as something that is part of every instance.  The idea is that static members are shared between all the instances and can be accessed without even creating an instance.  
Accessed using only the class name and the scope resolution operator ::. 
```
MyClass::staticMember;
MyClass::staticFunction();
myObject::staticMember;
myObject::staticFunction();
``` 
## Design Patterns
* Singleton
* Command pattern
A templates for solving commonly seen problems.
