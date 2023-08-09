#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int n, num, cur{ 1 };
stack<int> s;
string ans = "";

void pop() {
    ans += "-\n";
    s.pop();
}

void push() {
    ans += "+\n";
    s.push(cur++);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    bool* isExist = new bool[n + 1];
    for (int i = 0; i < n + 1; i++) isExist[i] = 0;

    for (int i = 0; i < n; i++) {
        cin >> num;

        // push 반복 -> pop
        if (num > cur) {
            while (cur != (num + 1)) {
                isExist[cur] = 1;
                push();
            }
            isExist[num] = 0;
            pop();
        }
        // push -> pop
        else if (num == cur) {
            push();
            pop();
        }
        // isExist 체크 -> pop 반복
        else if (num < cur) {
            if (!isExist[num]) {
                cout << "NO";
                return 0;
            }
            else {
                while (s.top() != num) {
                    isExist[s.top()] = 0;
                    pop();
                }
                isExist[s.top()] = 0;
                pop();
            }
        }
    }

    cout << ans;
}