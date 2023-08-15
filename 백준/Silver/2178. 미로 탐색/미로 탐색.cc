#include <iostream>
#include <vector>
#include <queue>
using namespace std; 
#define MAX 101

int N, M;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

void bfs(int start_x, int start_y) {
	visited[start_x][start_y] = 1;
	q.push(make_pair(start_x, start_y));
	dist[start_x][start_y]++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + x_move[i];
			int new_y = y + y_move[i];

			if (0 < new_x && new_x <= M && 0 < new_y && new_y <= N && visited[new_x][new_y] == false && graph[new_x][new_y] == 1) {
				q.push(make_pair(new_x, new_y));
				visited[new_x][new_y] = 1;
				dist[new_x][new_y] = dist[x][y] + 1;
			}
		}
	}
}

int main() {

	cin >> N >> M;

	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++) {
			graph[j][i] = str[j - 1] - '0';
		}
	}

	bfs(1, 1);

	cout << dist[M][N];
	
	
}