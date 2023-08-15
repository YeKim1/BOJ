#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 26
using namespace std;

int N;

vector<vector<int>> graph(MAX, vector<int>(MAX));
bool visited[MAX][MAX];
int cnt_tmp = 0;
int ans = 0;

int x_move[4] = { 1, -1, 0, 0 };
int y_move[4] = { 0,0,-1,1 };

void dfs(int x, int y) {
	cnt_tmp++;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int new_x = x + x_move[i];
		int new_y = y + y_move[i];

		if (0 < new_x && new_x <= N && 0 < new_y && new_y <= N && !visited[new_x][new_y] && graph[new_x][new_y] == 1) {
			dfs(new_x, new_y);
		}
	}
}

int main() {
	cin >> N;

	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= N; j++) {
			graph[j][i] = str[j - 1] - '0';
		}
	}

	vector<int> cnt;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (!visited[x][y] && graph[x][y] == 1) {
				ans++;
				cnt_tmp = 0;
				dfs(x, y);
				cnt.push_back(cnt_tmp);
			}
		}
	}

	sort(cnt.begin(), cnt.end());

	cout << ans << "\n";
	for (int i = 0; i < cnt.size(); i++) {
		cout << cnt[i] << "\n";
	}
}