#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, n;

int main() {
    cin >> T;

    while (T--) {
        cin >> n;
        vector<vector<int>> v(2, vector<int>(n, 0));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }

        vector<vector<int>> dp(2, vector<int>(n, 0));

        dp[0][0] = v[0][0];
        dp[1][0] = v[1][0];
        if (n > 1) {
            dp[0][1] = v[0][1] + dp[1][0];
            dp[1][1] = v[1][1] + dp[0][0];
        }

        for (int j = 2; j < n; j++) {
            dp[0][j] = v[0][j] + max(dp[1][j - 1], dp[1][j - 2]);
            dp[1][j] = v[1][j] + max(dp[0][j - 1], dp[0][j - 2]);
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }
}