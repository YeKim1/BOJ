#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

/*
     1,1
   2,1 2,2
 3,1 3,2 3,3
4,1 4,2 4,3 4,4

*/

int main() {
	cin >> n;

	vector<vector<int>> input(n+1, vector<int>(n+1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> input[i][j];
		}
	}

	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	dp[1][1] = input[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] = dp[i - 1][j] + input[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + input[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + input[i][j];
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]);
	}

	cout << ans;
	
}