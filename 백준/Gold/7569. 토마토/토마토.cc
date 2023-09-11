#include <iostream>
#include <queue>
using namespace std;


int M, N, H;
int cnt = 0;

int m_arr[] = { 1,-1,0,0,0,0 };
int n_arr[] = { 0,0,-1,1,0,0 };
int h_arr[] = { 0,0,0,0,1,-1 };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N >> H;

    vector<vector<vector<int>>> tomato(M, vector<vector<int>>(N, vector<int>(H)));
    vector<vector<vector<int>>> dis(M, vector<vector<int>>(N, vector<int>(H)));

    queue<pair<pair<int, int>, int>> q;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                dis[k][j][i] = 0;
                cin >> tomato[k][j][i];
                if (tomato[k][j][i] == 1) {
                    q.push(make_pair(make_pair(k, j), i));
                }
            }
        }
    }

    int day = 0;

    while (!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();

        if (day < dis[cur.first.first][cur.first.second][cur.second]) day = dis[cur.first.first][cur.first.second][cur.second];

        for (int i = 0; i < 6; i++) {
            int move_m = cur.first.first + m_arr[i];
            int move_n = cur.first.second + n_arr[i];
            int move_h = cur.second + h_arr[i];

            if (0 <= move_m && move_m < M && 0 <= move_n && move_n < N && 0 <= move_h && move_h < H) {
                if (tomato[move_m][move_n][move_h] == 0) {
                    q.push(make_pair(make_pair(move_m, move_n), move_h));
                    dis[move_m][move_n][move_h] = dis[cur.first.first][cur.first.second][cur.second] + 1;
                    tomato[move_m][move_n][move_h] = 1;
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (tomato[k][j][i] == 0) {
                    day = -1;
                    break;
                }
            }
        }
    }

    cout << day;
}