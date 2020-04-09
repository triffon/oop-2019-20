#include <iostream>
#include <fstream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;

class Event {

public:
    Event() {
        id = 0;
        name[0] = 0;
    }
    Event(int _id, const char * _name) {
        id = _id;
        strcpy(name, _name);
    }
    friend std::istream& operator>>(std::istream& istr, Event& e) {
        istr >> e.id >> e.name;
        return istr;
    }
    friend std::ostream& operator<<(std::ostream& ostr, Event& e) {
        ostr << e.id << ' ' << e.name;
        return ostr;
    }

private:
    int id;
    char name[256];

};

class EventDyn {

public:
    EventDyn() {
        id = 0;
        name = nullptr;
    }
    EventDyn(int _id, const char * _name) {
        id = _id;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }
    ~EventDyn() {
        delete[] name;
    }
    friend std::istream& operator>>(std::istream& istr, EventDyn& e) {
        istr >> e.id;
        char c;
        /*
            1   Event Number 1\n
        */
        while (istr.peek() == ' ') {
            istr.get(c);
        }

        char namebuf[2048];
        istr.getline(namebuf, 2048);
        if (e.name != nullptr) {
            delete[] e.name;
        }
        e.name = new char[strlen(namebuf) + 1];
        strcpy(e.name, namebuf);

        return istr;
    }
    friend std::ostream& operator<<(std::ostream& ostr, EventDyn& e) {
        ostr << e.id << ' ' << e.name;
        return ostr;
    }

private:
    int id;
    char * name;

};


int main() {
    fstream fin("test.txt", std::ios::in);
    fstream fout("test1.txt", std::ios::out);

    int i;
    while (!fin.eof()) {
        fin >> i;
        cout << i << endl;
        fout << i << endl;
    }

    fin.close();
    fout.close();

    Event events[128];

    fin.open("events.txt", std::ios::in);
    int n = 0;
    while (!fin.eof()) {
        fin >> events[n++];
    }
    fin.close();

    for (int i = 0; i < n; ++i) {
        cout << events[i] << endl;
    }

    fout.open("events1.txt", std::ios::out);
    for (int i = 0; i < n; ++i) {
        fout << events[i];
        if (i < n - 1) {
            fout << endl;
        }
    }
    fout.close();

    EventDyn eventsDyn[128];

    fin.open("events2.txt", std::ios::in);
    n = 0;
    while (!fin.eof()) {
        fin >> eventsDyn[n++];
    }
    fin.close();

    for (int i = 0; i < n; ++i) {
        cout << eventsDyn[i] << endl;
    }

    return 0;
}
