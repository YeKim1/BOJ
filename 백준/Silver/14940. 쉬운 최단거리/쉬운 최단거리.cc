#include <iostream>
#include <queue>
using namespace std;
#define X first 
#define Y second 

int m, n;
int map[1001][1001];
int dis[1001][1001];
bool visit[1001][1001];

int x_move[] = { 1,-1,0,0 };
int y_move[] = { 0,0,-1,1 };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    queue<pair<int, int>> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[j][i];
            dis[j][i] = -1;
            if (map[j][i] == 2) {
                q.push(make_pair(j, i));
                dis[j][i] = 0;
                visit[j][i] = true;
            }
            else if (map[j][i] == 0) {
                dis[j][i] = 0;
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tmp_x = cur.X + x_move[i];
            int tmp_y = cur.Y + y_move[i];
            if (0 < tmp_x && tmp_x <= m && 0 < tmp_y && tmp_y <= n && !visit[tmp_x][tmp_y]) {
                visit[tmp_x][tmp_y] = true;
                if (map[tmp_x][tmp_y] == 1) {
                    dis[tmp_x][tmp_y] = dis[cur.X][cur.Y] + 1;
                    q.push(make_pair(tmp_x, tmp_y));
                }
            }
        }
    }

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            cout << dis[x][y] << " ";
        }
        cout << "\n";
    }

}