#include <iostream>
#include <climits>
using namespace std;

int n, m;
int map[101][101];

int main() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			map[i][j] = 50000;
		}
	}

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	int min_num = 0;
	int min_ans = INT_MAX;

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j) sum += map[i][j];
		}

		if (min_ans > sum) {
			min_num = i;
			min_ans = sum;
		}
	}

	cout << min_num;
}