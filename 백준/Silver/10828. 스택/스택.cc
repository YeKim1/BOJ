#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

void push(int X) {s.push(X);}
void pop() {
    if (s.empty()) cout << -1 << "\n";
    else {
        cout << s.top() << "\n";
        s.pop();
    }
}
void size() {cout << s.size() << "\n";}
void empty() {
    if (s.empty()) cout << 1 << "\n";
    else cout << 0 << "\n";
}
void top() {
    if (s.empty()) cout << -1 << "\n";
    else cout << s.top() << "\n";
}

int main() {
    
    int N, X;
    string str;
    
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> str;
        if (str=="push") {
            cin >> X;
            push(X);
        }
        else if (str=="pop") {
            pop();
        }
        else if (str=="size") {
            size();
        }
        else if (str=="empty") {
            empty();
        }
        else {
            top();
        }
    }
}