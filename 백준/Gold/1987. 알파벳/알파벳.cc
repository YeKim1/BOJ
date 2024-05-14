#include <iostream>
#include <queue>
using namespace std;
#define MAX 21

int R, C;
char map[MAX][MAX];

int ans;
bool check[26];

int x_move[4] = { 0,0,-1,1 };
int y_move[4] = { -1,1,0,0 };

void dfs(int x, int y, int depth) {
	if (depth > ans) ans = depth;
	check[map[x][y] - 'A'] = true;

	for (int i = 0; i < 4; i++) {
		int cur_x = x + x_move[i];
		int cur_y = y + y_move[i];

		if (cur_x <= 0 || cur_x > C || cur_y <= 0 || cur_y > R) continue;
		if (check[map[cur_x][cur_y] - 'A']) continue;

		dfs(cur_x, cur_y, depth + 1);

		check[map[cur_x][cur_y] - 'A'] = false;

	}
}

int main() {
	cin >> R >> C;

	string s;
	for (int y = 1; y <= R; y++) {
		cin >> s;
		for (int x = 1; x <= C; x++) {
			map[x][y] = s[x - 1];
		}
	}

	dfs(1, 1, 1);

	cout << ans;
}