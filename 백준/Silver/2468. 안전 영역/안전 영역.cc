#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int N, max_height;
int map[MAX][MAX];
bool visited[MAX][MAX];
int x_move[4] = { 1, -1, 0, 0 };
int y_move[4] = { 0,0,-1,1 };

void init(int h) {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (map[x][y] <= h) visited[x][y] = true;
			else visited[x][y] = false;
		}
	}
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int new_x = x + x_move[i];
		int new_y = y + y_move[i];

		if (new_x <= 0 || new_x > N || new_y <= 0 || new_y > N) continue;
		if (visited[new_x][new_y]) continue;

		dfs(new_x, new_y);
	}
}

int main() {
	cin >> N;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> map[x][y];
			max_height = (max_height < map[x][y] ? map[x][y] : max_height);
		}
	}

	int ans = 1;
	for (int h = 1; h < max_height; h++) {
		init(h);

		int cnt = 0;
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (!visited[x][y]) {
					dfs(x, y);
					cnt++;
				}
			}
		}

		if (cnt > ans) ans = cnt;
	}
	
	cout << ans;
}