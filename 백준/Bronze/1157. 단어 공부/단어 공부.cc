#include <iostream>
#include <string>
using namespace std;

int main() {
    int alphabet[26] = { 0 };

    string str;

    cin >> str;

    char c;

    int max = 0;
    for (int i = 0; i < str.length(); i++) {
        c = str[i];

        if (c >= 'a') c -= ('a' - 'A');

        int idx = c - 'A';

        alphabet[idx]++;

        if (alphabet[max] < alphabet[idx]) max = idx;
    }

    for (int i = 0; i < 26; i++) {
        if (alphabet[max] == alphabet[i] && i != max) {
            cout << '?';
            return 0;
        }
    }
    c = 'A' + max;
    cout << c;
}