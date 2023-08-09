#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

    while (true) {
        string str = "";

        stack<char> s;
        getline(cin, str, '.');

        if (str == "\n") return 0;

        bool isY = 1;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '[') {
                s.push('[');
            }
            else if (str[i] == ']') {
                if (s.empty()) {
                    isY = 0;
                    break;
                }
                else if (s.top() == '[') s.pop();
                else {
                    s.push(']');
                }
            }

            else if (str[i] == '(') {
                s.push('(');
            }

            else if (str[i] == ')') {
                if (s.empty()) {
                    isY = 0;
                    break;
                }
                else if (s.top() == '(') s.pop();
                else {
                    s.push(']');
                }
            }
        }

        if (!isY || !s.empty()) cout << "no\n";
        else cout << "yes\n";
    }
}