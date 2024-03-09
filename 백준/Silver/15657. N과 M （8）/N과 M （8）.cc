#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> map;
int save[10001];
bool visit[10001];

void dfs(int cur, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << save[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = cur; i < n; i++) {
		save[depth] = map[i];
		dfs(i, depth + 1);
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> n >> m;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		map.push_back(tmp);
	}

	sort(map.begin(), map.end());

	dfs(0, 0);
	
}