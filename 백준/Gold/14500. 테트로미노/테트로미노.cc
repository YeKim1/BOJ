#include <iostream>
#include <vector>
using namespace std;

int N, M, ans;
vector<vector<int>> map(501, vector<int>(501, 0));
bool visit[501][501];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };




void dfs(int x, int y, int depth, int sum) {
	if (depth > 3) {
		if (ans < sum) ans = sum;
		return;
	}

	if (x <= 0 || x > M || y <= 0 || y > N || visit[x][y]) {
		return;
	}

	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		dfs(x + dx[i], y + dy[i], depth + 1, sum + map[x][y]);
	}
	visit[x][y] = false;
}

int main() {
	cin >> N >> M;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> map[x][y];
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			dfs(x, y, 0, 0);
		}
	}

	int tmp = 0;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (x + 2 <= M && y + 1 <= N) {
				tmp = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
				if (ans < tmp) ans = tmp;
			}
			if (x + 1 <= M && y + 2 <= N) {
				tmp = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1];
				if (ans < tmp) ans = tmp;
			}
			if (x - 1 > 0 && y + 2 <= N) {
				tmp = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x - 1][y + 1];
				if (ans < tmp) ans = tmp;
			}
			if (x - 1 > 0 && x + 1 <= M && y + 1 <= N) {
				tmp = map[x][y] + map[x][y + 1] + map[x - 1][y + 1] + map[x + 1][y + 1];
				if (ans < tmp) ans = tmp;
			}
		}
	}

	/*
	{{0,1,2,1}, {0,0,0,1}},
	{{0,0,0,1}, {0,1,2,1}},
	{{0,0,0,-1}, {0,1,2,0}},
	{{0,0,-1,1}, {0,1,1,1}}
	*/
	cout << ans;
		
}