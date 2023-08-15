#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50
using namespace std;

int T, M, N, K;

int graph[MAX][MAX];
bool visited[MAX][MAX];

int x_move[4] = { 1, -1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

int ans = 0;

void dfs(int x, int y) {
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int new_x = x + x_move[i];
        int new_y = y + y_move[i];

        if (0 <= new_x && new_x < M && 0 <= new_y && new_y < N && !visited[new_x][new_y] && graph[new_x][new_y] == 1) {
            dfs(new_x, new_y);
        }
    }
}

int main() {
    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        int x, y;
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            graph[x][y] = 1;
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (!visited[x][y] && graph[x][y] == 1) {
                    ans++;
                    dfs(x, y);
                }
            }
        }

        cout << ans << "\n";

        ans = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                graph[x][y] = 0;
                visited[x][y] = 0;
            }
        }
    }
}