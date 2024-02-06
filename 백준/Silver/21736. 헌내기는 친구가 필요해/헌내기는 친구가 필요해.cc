#include <iostream>
using namespace std;

int N, M, cnt{ 0 };
char map[601][601];
bool visit[601][601];
int move_x[4] = { 1,-1,0,0 };
int move_y[4] = { 0,0,-1,1 };

void bfs(int x, int y) {
	if (map[x][y] == 'P') cnt++;
	
	for (int i = 0; i < 4; i++) {
		int moved_x = x + move_x[i];
		int moved_y = y + move_y[i];

		if (moved_x > 0 && moved_x <= N && moved_y > 0 && moved_y <= M && !visit[moved_x][moved_y] && map[moved_x][moved_y] != 'X') {
			visit[moved_x][moved_y] = true;
			bfs(moved_x, moved_y);
		}
	}
}

int main() {
	cin >> M >> N;

	string str;
	pair<int, int> start;
	for (int y = 1; y <= M; y++) {
		cin >> str;
		for (int x = 1; x <= N; x++) {
			map[x][y] = str[x-1];
			if (map[x][y] == 'I') {
				start = make_pair(x, y);
			}
		}
	}
	bfs(start.first, start.second);

	if (cnt == 0) cout << "TT";
	else cout << cnt;
}