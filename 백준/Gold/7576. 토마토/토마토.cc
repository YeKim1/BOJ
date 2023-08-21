#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int M, N;
int graph[1001][1001];
int dis[1001][1001];

int x_move[4] = { 0,0,-1,1 };
int y_move[4] = { 1,-1,0,0 };

queue<pair<int, int>> Q;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> M >> N;

    // 그래프 초기화
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> graph[x][y];
            // 익은 토마토는 큐에 push
            if (graph[x][y] == 1) Q.push(make_pair(x, y));
        }
    }

    int max_dis = 0;

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = x + x_move[i];
            int new_y = y + y_move[i];

            if (0 < new_x && new_x <= M && 0 < new_y && new_y <= N && graph[new_x][new_y] == 0) {
                Q.push(make_pair(new_x, new_y));
                graph[new_x][new_y] = 1;

                dis[new_x][new_y] = dis[x][y] + 1;

                max_dis = max(dis[new_x][new_y], max_dis);
            }
        }
    }

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            if (graph[x][y] == 0) {
                max_dis = -1;
                break;
            }
        }
    }

    cout << max_dis;

}