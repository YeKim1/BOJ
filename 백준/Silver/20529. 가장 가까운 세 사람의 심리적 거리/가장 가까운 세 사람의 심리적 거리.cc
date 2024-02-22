#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int t, n;

int cal(string s1, string s2) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (s1[i] != s2[i]) sum++;
	}
	return sum;
}

int main() {
	cin.tie(0); cout.tie(0); 

	cin >> t;

	while (t--) {
		cin >> n;

		vector<string> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		if (n >= 33) cout << "0\n";
		else {
			int min_sum = INT_MAX;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						if (i != j && j != k && k != i) {
							min_sum = min(min_sum, cal(v[i], v[j]) + cal(v[j], v[k]) + cal(v[k], v[i]));
						}
					}
				}
			}

			cout << min_sum << "\n";
		}
	}
}