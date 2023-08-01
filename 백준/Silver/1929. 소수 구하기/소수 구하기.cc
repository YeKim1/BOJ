#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie();

    int M, N;

    cin >> M >> N;

    int* arr = new int[N + 1];

    for (int i = 0; i <= N; i++) {
        arr[i] = 0;
    }

    for (int i = 2; i <= N; i++) {
        if (i != 1 && arr[i] == 0) {
            if (i >= M) cout << i << "\n";

            int cur = 1;
            while (true) {
                if (i * cur > N) break;
                else arr[i * cur] = 1;
                cur++;
            }
        }
    }
}