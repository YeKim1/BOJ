#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int map[MAX][MAX];
int dist[MAX][MAX][2];
int N, M;

int x_move[4] = {1, -1, 0, 0};
int y_move[4] = { 0, 0, -1, 1 };

int ans;

void bfs() {
	queue<pair<pair<int, int>, bool>> q;
	q.push(make_pair(make_pair(1, 1), false));

	while (!q.empty()) {
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		bool isBreak = q.front().second;
		q.pop();

		if (cur_x == M && cur_y == N) {
			ans = dist[cur_x][cur_y][isBreak] + 1;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + x_move[i];
			int next_y = cur_y + y_move[i];

			if (next_x <= 0 || next_x > M || next_y <= 0 || next_y > N) continue;

			if (map[next_x][next_y] == 1) {
				if (isBreak == false) {
					q.push(make_pair(make_pair(next_x, next_y), true));
					dist[next_x][next_y][true] = dist[cur_x][cur_y][false] + 1;
				}
			}
			else {
				if (dist[next_x][next_y][isBreak] != 0) continue;
				q.push(make_pair(make_pair(next_x, next_y), isBreak));
				dist[next_x][next_y][isBreak] = dist[cur_x][cur_y][isBreak] + 1;
			}
		}
	}

	ans = -1;
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> N >> M;

	string s;
	for (int y = 1; y <= N; y++) {
		cin >> s;
		for (int x = 0; x < M; x++) {
			map[x + 1][y] = s[x] - '0';
		}
	}

	bfs();

	cout << ans;

}