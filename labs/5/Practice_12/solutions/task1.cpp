#include <iostream>
#include <vector>

using namespace std;

int main() {
    string text, tmp;
    vector<pair<string, int>> counters;

    do {
        getline(cin, tmp);
        text += " " + tmp;
    } while (tmp.length() > 0);

    int wordEnd = text.find(" ");
    while (wordEnd > -1) {
        string currentWord = text.substr(0, wordEnd);
        text.erase(0, wordEnd + 1); // remove current word and ' '

        bool found = false;
        for (int i = 0; i < counters.size(); i++) {
            if (counters[i].first == currentWord) {
                counters[i].second++;
                found = true;
                break;
            }
        }

        if (!found) {
            counters.push_back(make_pair(currentWord, 1));
        }

        wordEnd = text.find(' ');
    }

    int mxWord = 0;
    string word;
    for (int i = 0; i < counters.size(); i++) {
        if (counters[i].second > mxWord) {
            word = counters[i].first;
            mxWord = counters[i].second;
        }
    }

    cout << word << " - " << mxWord << endl;

    return 0;
}
