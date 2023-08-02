#include <iostream>
using namespace std;

int main() {
    int T, k, n;

    cin >> T;

    while (T--) {
        cin >> k >> n;

        int dp[15][15]; // 층-호

        for (int i = 0; i <= 14; i++) {
            dp[0][i] = i;
        }

        for (int i = 0; i <= 14; i++) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 2; j <= n; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }

        cout << dp[k][n] << '\n';
    }
}