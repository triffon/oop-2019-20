#include <iostream>
using namespace std;

const int SIZE = 100;

struct Book
{
    char title[SIZE];
    char author[SIZE];
    char genre[SIZE];
    double price;
    int sales;
};


void initialize(Book& b) {
 	cout << "Title: " << endl;
 	cin.sync();
    cin.getline(b.title, SIZE);

 	cout << "Author: " << endl;
 	cin.sync();
    cin.getline(b.author, SIZE);

 	cout << "Genre: " << endl;
 	cin.sync();
    cin.getline(b.genre, SIZE);

 	cout << "Price: " << endl;
 	cin >> b.price;

 	cout << "Sales: " << endl;
 	cin >> b.sales;
}

void print(const Book& b) {
	cout << "Title: " << b.title << endl;
 	cout << "Author: " << b.author << endl;
 	cout << "Genre: " << b.genre << endl;
 	cout << "Price: " << b.price << endl;
 	cout << "Sales: " << b.sales << endl;
}


void printBookWithLowestPrice(Book* books, size_t count) {
	double lowestPrice = books[0].price;
	int bookWithLowestPrice = 0;
	for (int i = 1; i < count; ++i)
	{
		if (books[i].price < lowestPrice) {
			lowestPrice = books[i].price;
			bookWithLowestPrice = i;
		}
	}

	print(books[bookWithLowestPrice]);
}

Book& getBestBook(Book* books, size_t count) {
	double highestSales = books[0].sales;
	int bookWithHighestSales = 0;

	for (int i = 1; i < count; ++i)
	{
		if (books[i].sales > highestSales) {
			highestSales = books[i].sales;
			bookWithHighestSales = i;
		}
	}

	return books[bookWithHighestSales];
}

int main() {

	const int booksCount = 3;
	Book books[booksCount];

	for (int i = 0; i < booksCount; ++i)
	{
		cout << "Book :" << i + 1 << endl;
		initialize(books[i]);
	}

	cout << "Best book" << endl;

	print(getBestBook(books, booksCount));

	return 0;
}