#include <iostream>
using namespace std;

int main() {
    string s;

    while (true) {
        cin >> s;
        if (s == "0") return 0;

        bool isT = 1;
        if (s.size() != 1) {
            for (int i = 0; i <= (s.size() / 2) - 1; i++) {
                if (s[i] != s[s.size() - 1 - i]) isT = 0;
            }
        }

        if (isT) cout << "yes\n";
        else cout << "no\n";
    }
}