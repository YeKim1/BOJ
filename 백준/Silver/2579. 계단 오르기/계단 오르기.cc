#include <iostream>
using namespace std;

int n, sum{ 0 };
int DP[301];
int score[301];

int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }

    DP[1] = score[1];
    DP[2] = score[1] + score[2];

    for (int i = 3; i <= n; i++) {
        DP[i] = max(DP[i - 2] + score[i], DP[i - 3] + score[i - 1] + score[i]);
    }

    cout << DP[n];
}