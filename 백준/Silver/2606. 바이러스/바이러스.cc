#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int n;
bool visited[MAX];
vector<vector<int>> edge(MAX, vector<int>());

int ans = 0;

void dfs(int cur) {
	visited[cur] = 1;
	ans++;

	for (int i = 0; i < edge[cur].size(); i++) {
		if (!visited[edge[cur][i]]) {
			dfs(edge[cur][i]);
		}
	}
}

int main() {
	cin >> n;

	int m, x, y;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		edge[x].push_back(y); edge[y].push_back(x);
	}

	dfs(1);

	// 카운트에서 1번 컴퓨터 제외
	cout << ans - 1;
}