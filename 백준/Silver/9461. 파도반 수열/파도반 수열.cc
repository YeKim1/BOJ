#include <iostream>
using namespace std;

long long T, N;
long long DP[101];

int main() {
    cin >> T;

    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 2;
    DP[6] = 3;
    DP[7] = 4;
    DP[8] = 5;
    DP[9] = 7;
    DP[10] = 9;

    while (T--) {
        cin >> N;

        for (int i = 11; i <= N; i++) {
            DP[i] = DP[i - 1] + DP[i - 5];
        }

        cout << DP[N] << '\n';
    }
}