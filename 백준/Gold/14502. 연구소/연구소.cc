#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int n, m;
int ans = 0;
int map[9][9];
int map_cp[9][9];
bool visit[9][9];
queue<pair<int, int>> q;
vector<pair<int, int>> v;

int x_move[4] = { 1,-1,0,0 };
int y_move[4] = { 0,0, -1,1 };

void bfs() {
	queue<pair<int, int>> q_cp(q);
	
	while (!q_cp.empty()) {
		pair<int, int> cur = q_cp.front();
		q_cp.pop();
		for (int i = 0; i < 4; i++) {
			int moved_x = cur.X + x_move[i];
			int moved_y = cur.Y + y_move[i];

			if (moved_x >= 1 && moved_x <= n && moved_y >= 1 && moved_y <= m) {
				if (map_cp[moved_x][moved_y] != 1 && visit[moved_x][moved_y] == false) {
					map_cp[moved_x][moved_y] = 2;
					visit[moved_x][moved_y] = true;
					q_cp.push(make_pair(moved_x, moved_y));
				}
			}
		}
	}
}

void count_safe() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map_cp[i][j] == 0) {
				cnt++;
			}
		}
	}
	if (cnt > ans) ans = cnt;
}

void start() {
	for (int i = 0; i < v.size(); i++) {
		pair<int, int> cur1 = v[i];
		for (int j = 0; j < v.size(); j++) {
			if (i != j) {
				pair<int, int> cur2 = v[j];
				for (int k = 0; k < v.size(); k++) {
					if (j != k && k != i) {
						pair<int, int> cur3 = v[k];
						for (int x = 1; x <= n; x++) {
							for (int y = 1; y <= m; y++) {
								map_cp[x][y] = map[x][y];
								visit[x][y] = false;
							}
						}

						map_cp[cur1.X][cur1.Y] = 1;
						map_cp[cur2.X][cur2.Y] = 1;
						map_cp[cur3.X][cur3.Y] = 1;
						bfs();
						count_safe();
					}
				}
			}
		}
	}

}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) q.push(make_pair(i, j));
			if (map[i][j] == 0) v.push_back(make_pair(i, j));
		}
	}

	start();
	cout << ans;
}