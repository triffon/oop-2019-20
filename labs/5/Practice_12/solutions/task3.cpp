#include <iostream>
#include <string>

using namespace std;

char toUpper(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        ch += ('A' - 'a');
    }

    return ch;
}

int main() {
    locale loc;
    string text;
    const string OPEN_TAG = "<upcase>";
    const string CLOSE_TAG = "</upcase>";

    getline(cin, text);

    int start = text.find(OPEN_TAG);
    while(start > 0) {
        text.erase(start, OPEN_TAG.length());

        int end = text.find(CLOSE_TAG);
        text.erase(end, CLOSE_TAG.length());

        for (int i = start; i < end; i++) {
            text[i] = toUpper(text[i]);
            //text[i] = toupper(text[i], loc);
        }

        start = text.find(OPEN_TAG);
    }

    cout << text << endl;

    return 0;
}
