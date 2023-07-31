#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T;
    string str;

    cin >> T;

    stack<char> s;

    while (T--) {
        cin >> str;

        while (!s.empty()) s.pop();

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                s.push(str[i]);
            }
            else if (str[i] == ')') {
                if (s.empty()) s.push(str[i]);
                else {
                    if (s.top() == '(') s.pop();
                    else s.push(str[i]);
                }
            }
        }

        if (s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}