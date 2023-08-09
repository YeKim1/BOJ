#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    queue<int> q;
    for (int i = 1; i <= N; i++) q.push(i);

    cout << "<";
    while (!q.empty()) {
        int tmp;
        for (int i = 0; i < K - 1; i++) {
            tmp = q.front();
            q.pop(); q.push(tmp);
        }
        if (q.size() == 1) {
            cout << q.front() << ">";
        }
        else cout << q.front() << ", ";
        q.pop();
    }



}