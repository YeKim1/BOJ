#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;

    cin >> N;

    vector<int> dp(N + 1);

    for (int i = 0; i < N + 1; i++) {
        dp[i] = -1;
    }

    dp[N] = 0;

    for (int i = N; i >= 0; i--) {
        if (i % 2 == 0 && (dp[i / 2] > dp[i] + 1 || dp[i / 2] == -1)) {
            dp[i / 2] = dp[i] + 1;
        }

        if (i % 3 == 0 && (dp[i / 3] > dp[i] + 1 || dp[i / 3] == -1)) {
            dp[i / 3] = dp[i] + 1;
        }

        if (i - 1 >= 1 && (dp[i - 1] > dp[i] + 1 || dp[i - 1] == -1)) {
            dp[i - 1] = dp[i] + 1;
        }
    }

    cout << dp[1];
}