#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T, n;

	cin >> T;

	while (T--) {
		cin >> n;

		int DP[11];
		DP[0] = 0;
		DP[1] = 1;
		DP[2] = 2;
		DP[3] = 4;
		
		for (int i = 4; i <= n; i++) {
			DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
		}
		cout << DP[n] << "\n";
	}
}