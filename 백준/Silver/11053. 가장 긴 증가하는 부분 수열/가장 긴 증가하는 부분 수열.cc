#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> n;

	vector<int> v(n + 1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (v[i] > v[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}

	cout << ans + 1;

}