#include <iostream>
#include <cstring>

#define MAX_NUMBER_OF_BOOKS 1000
#define MAX_STRING 128
#define ISBN_SIZE 13

using std::cin;
using std::cout;
using std::endl;

struct Book {
    char title[MAX_STRING];
    char author[MAX_STRING];
    char isbn[ISBN_SIZE];

    void read() {
        cout << "Book title:" << endl;
        cin.ignore();
        cin.getline(title, MAX_STRING);
        cout << "Book author:" << endl;
        cin.ignore();
        cin.getline(author, MAX_STRING);
        cout << "Book ISBN:" << endl;
        cin >> isbn;
    }
};

struct Library {
    Book books[MAX_NUMBER_OF_BOOKS];
    int number_of_books = 0;

    void addBookFromConsole() {
        if (number_of_books < MAX_NUMBER_OF_BOOKS) {
            Book newBook;
            newBook.read();
            books[number_of_books++] = newBook;
        } else {
            cout << "NO MORE CAPACITY" << endl;
        }
    }

    void removeBook() {
        char isbn[ISBN_SIZE];
        cout << "ISBN of Book for deletion:" << endl;
        cin >> isbn;

        bool foundBook = false;
        for (int i = 0; i < number_of_books i++) {
            if (strcmp(books[i].isbn, isbn) == 0) {
                foundBook = true;
                number_of_books--;
            }

            if(foundBook) {
                books[i] = books[i+1];
            }
        }
    }

    int numberOfBooks() {
       return number_of_books;
    }
};

void printMenu() {
    cout << "Choose option:\n";
    cout << "1 - Add Book to Library\n";
    cout << "2 - Remove Book from Library\n";
    cout << "3 - Get size of Library\n";
    cout << "0 - Exit\n";
}

int main() {
    int option;
    Library myLibrary;

    do {
        printMenu();

        cin >> option;

        switch(option) {
            case 1:
                myLibrary.addBookFromConsole();
                break;
            case 2:
                myLibrary.removeBook();
                break;
            case 3:
                cout << myLibrary.numberOfBooks() << endl;
                break;
        }
    } while(option);

    return 0;
}
