#include <iostream>
#include <queue>
using namespace std;

int N, K;
int arr[100001];
bool visit[100001];

int main() {
    cin >> N >> K;

    queue<int> Q;

    Q.push(N);
    arr[N] = 0;

    while (!Q.empty()) {
        int cur = Q.front();

        if (cur == K) {
            cout << arr[cur];
            return 0;
        }

        Q.pop();

        if (0 <= cur - 1 && cur - 1 <= 100000 && !visit[cur - 1]) {
            Q.push(cur - 1);
            arr[cur - 1] == 0 ? arr[cur - 1] = arr[cur] + 1 : arr[cur - 1] = min(arr[cur] + 1, arr[cur - 1]);
            visit[cur - 1] = true;
        }
        if (0 <= cur + 1 && cur + 1 <= 100000 && !visit[cur + 1]) {
            Q.push(cur + 1);
            arr[cur + 1] == 0 ? arr[cur + 1] = arr[cur] + 1 : arr[cur + 1] = min(arr[cur] + 1, arr[cur + 1]);
            visit[cur + 1] = true;
        }
        if (0 <= cur * 2 && cur * 2 <= 100000 && !visit[cur * 2]) {
            Q.push(cur * 2);
            arr[cur * 2] == 0 ? arr[cur * 2] = arr[cur] + 1 : arr[cur * 2] = min(arr[cur] + 1, arr[cur * 2]);
            visit[cur * 2] = true;
        }

    }


}