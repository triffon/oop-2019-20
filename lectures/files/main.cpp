#include <iostream>
#include <fstream>

#include "student.h"

void printTextFile(char const* filename) {
    std::ifstream fi(filename);
    const int MAX = 1000;
    char line[MAX] = "";
    unsigned counter = 0;
    while (fi.getline(line, MAX))
        std::cout << ++counter << ": " << line << std::endl;
}

void printBinaryFile(char const* filename) {
    std::ifstream fi(filename, std::ios::in | std::ios::binary);
    const int MAX = 1000;
    char byte = 0; // [-128; 127]
    // unsigned char: [0; 255]
    unsigned counter = 0;
    while (fi.get(byte))
        std::cout << std::dec << ++counter << ": " << std::hex << (int)(unsigned char)byte << std::endl;
}

void writeBottlesSong(char const* filename, int bottles = 10) {
    std::ofstream fo(filename);
    for(; bottles > 0; bottles--)
        fo << "There are " << bottles << " green bottles hanging on the wall,\n"
           << "there are " << bottles << " green bottles hanging on the wall,\n"
           << "and if one green bottle accidentally falls\n"
           << "there will be " << bottles - 1 << " green bottles hanging on the wall!\n\n";
}

void countInBinary(char const *filename, int to = 10, int from = 0) {
    std::ofstream fo(filename, std::ios::out | std::ios::binary);
    for(char i = from; i <= to; i++)
        fo.put(i);
}

bool safeReadInt(int& x, std::istream& is = std::cin) {
    std::cout << "Моля, въведете цяло число: ";
    is >> x;
    while (!is) {
        if (is.rdstate() & (std::ios::badbit | std::ios::eofbit)) {
            std::cerr << "Възникна фатална грешка!" << std::endl;
            return false;
        }
        std::clog << "is.rdstate() = " << is.rdstate() << std::endl;
        is.clear();
        is.get(); // изхвърляме проблемния символ
        std::clog << "is.rdstate() = " << is.rdstate() << std::endl;
        is >> x;
        std::clog << "is.rdstate() = " << is.rdstate() << std::endl;
    }
    return true;
}

void testistream() {
    int x;
    std::cin >> x;
    std::cout << "std::cin.good() = " << std::cin.good() << std::endl;
    std::cout << "std::cin.bad() = " << std::cin.bad() << std::endl;
    std::cout << "std::cin.eof() = " << std::cin.eof() << std::endl;
    std::cout << "std::cin.fail() = " << std::cin.fail() << std::endl;
    std::cout << "std::cin.rdstate() = " << std::cin.rdstate() << std::endl;
}

void testSafeRead() {
    int x = 0; // инициализиране на числото
    if (safeReadInt(x))
        std::cout << "Успешно прочетено число: " << x << std::endl;
    else
        std::cout << "Неуспешно прочитане на числото" << std::endl;
}

void changeTextFile(char const* filename) {
    std::fstream file(filename);
    char line[100];
    file.getline(line, 100);
    file << "#include <cmath>\n//";
}

unsigned readStudents(Student* students) {
    char more;
    unsigned count = 0;
    do {
        std::clog << "Въведете Ф№, оценка и име на един ред, разделени с интервали:" << std::endl;
        std::cin >> students[count++];
        std::clog << "Ще въвеждате ли още? [y/n]";
        more = std::cin.get();
    } while (more == 'y' || more == 'Y');
    return count;
}

void writeStudentsToFile(Student* students, unsigned count, char const* textFile) {
    std::clog << "Записваме " << count << " студенти във файла " << textFile << std::endl;
    std::ofstream text(textFile);
    text << count << std::endl;
    for(int i = 0; i < count; i++)
        text << students[i];
}

// максимален брой студенти = n (4 байта = sizeof(unsigned))
// масив от n студенти от тип Student, така че Ф№ X да е на позиция X - 40000
void writeStudentsToBook(char const* textFile, char const* bookFile) {
    std::ifstream text(textFile);
    std::ofstream book(bookFile, std::ios::out | std::ios::binary );
    unsigned count;
    text >> count;
    Student student;
    const unsigned MAX_STUDENTS = 1000;
    // заглавната част на главната книга
    // TODO: да се запише интервала от Ф№, които са записани в книгата
    book.write((const char*)&MAX_STUDENTS, sizeof(unsigned));
    for(int i = 0; i < count; i++) {
        text >> student;
        student.write(book);
    }
}

bool increaseGrade(char const* bookFile, unsigned fn) {
    std::fstream book(bookFile, std::ios::in | std::ios::out | std::ios::binary );
    Student s;
    s.read(book, fn);
    if (!book || s.fn != fn)
        return false;
    std::clog << "Прочетена оценка: " << s.grade << std::endl;
    s.grade = std::min( 6.0, s.grade + 1 );
    s.write(book);
    std::clog << "Записана оценка: " << s.grade << std::endl;
    return book.good();
}

void SUSI() {
    Student students[1000];
    /*
    unsigned count = readStudents(students);
    writeStudentsToFile(students, count, "students.txt");
    writeStudentsToBook("students.txt", "main.bk");
    */
    std::clog << "На кой студент да повишим оценката? ";
    unsigned fn;
    std::cin >> fn;
    bool success = increaseGrade("main.bk", fn);
    std::clog << "Увеличаването ";
    if (!success)
        std::clog << "НЕ ";
    std::clog << "беше успешно!" << std::endl;

    /*
    Student fmi[8][1000];
    // fmi[0][0], fmi[0][1], ... fmi[0][999], fmi[1][0], fmi[1][1], ... fmi[7][999]
    */
}

/*
void readFMI(Student fmi[][1000], unsinged specCount) {
    // sizeof(fmi[0])
}
*/

bool compareBinaryFiles(const char* filename1, const char* filename2, unsigned skipHeader = 0) {
    std::ifstream f1(filename1, std::ios::binary);
    std::ifstream f2(filename2, std::ios::binary);
    f1.seekg(skipHeader);
    f2.seekg(skipHeader);

    while (!f1.eof() && !f2.eof()) {
        if (f1.get() != f2.get())
          return false;
    }
    return f1.eof() && f2.eof();
}

int main() {
//    testistream();
    // testSafeRead();
    // printTextFile("main.cpp");
    // printBinaryFile("build/files");
    // writeBottlesSong("bottles10.txt");
    // writeBottlesSong("bottles100.txt", 100);
    /*
    countInBinary("numbers.bin", 100);
    countInBinary("numbers.bin", 50, 30);
    printBinaryFile("numbers.bin");
    */
    // changeTextFile("main.cpp");
    SUSI();
    return 0;
}