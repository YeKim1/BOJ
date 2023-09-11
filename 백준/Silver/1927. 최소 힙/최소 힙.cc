#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, i;

    cin >> N;

    while (N--) {
        cin >> i;

        if (i == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(i);
        }
    }

}