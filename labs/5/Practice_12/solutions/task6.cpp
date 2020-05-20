#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    string word;
    vector<int> symbols(256, 0);

    cin >> word >> n;

    int word_length = word.length();
    int max_freq = 0;
    char symbol;

    for (int i = 0; i < word_length; i++) {
        char c = word[i];

        symbols[c]++;

        if(symbols[c] > max_freq) {
            max_freq = symbols[c];
            symbol = c;
        }
    }

    word.insert(word_length - 1, n, symbol);
    word.insert(0, n, symbol);

    cout << word;


    return 0;
}
