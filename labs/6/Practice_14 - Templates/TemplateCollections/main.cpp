#include <iostream>

#include "ArrayVector.hpp"
#include "Set.hpp"
#include "LinkedVector.hpp"

void testArrayVector();
void testSet();

int main()
{
	LinkedVector<int> linked;
	linked.add(5);
	linked.add(6);
	linked.add(7);
	linked.print();
	//testArrayVector();
	testSet();
}

void testSet()
{
	ArrayVector<std::string> words;
	words.add("pesho");
	words.add("petyr");
	words.add("pedrak");

	Set<std::string> uniqueWords = Set<std::string>(words);
	uniqueWords.print();
	uniqueWords.add("pesho");
	uniqueWords.add("pesho2");
	uniqueWords.print();

}

void testArrayVector()
{
	ArrayVector<std::string> words;
	words.add("pesho");
	words.add("petyr");
	words.add("pedrak");
	words.add("pedrak2");
	words.add("pedrak3");
	words.print();
	words.remove("pedrak3");
	words.print();
	words.remove("pesho");
	words.print();
	words.remove("pedrak");
	words.print();

	std::cout << std::boolalpha << words.member("pesho") << std::endl;
	std::cout << std::boolalpha << words.member("pesho123") << std::endl;
}
