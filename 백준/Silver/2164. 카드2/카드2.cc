#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, num;
    deque<int> q;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        q.push_back(i);
    }

    while (q.size() > 1) {
        q.pop_front();
        int tmp = q.front();
        q.pop_front();
        q.push_back(tmp);
    }

    cout << q.front();
}