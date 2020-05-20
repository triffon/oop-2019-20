#include <iostream>

using namespace std;

int main() {

    string text;

    cin >> text;

    for(int i=0; i<text.length(); i++) {
        if (text[i] == text[i+1]) {
            int k = 0;
            while(text[i] == text[i + k + 1]) {
                k++;
            }
            text.erase(i, k);
        }
    }

    cout << text << endl;

    return 0;
}
