#include <iostream>
#include <algorithm>
using namespace std;

char arr[101][101];
bool visit[101][101];
int N;

int ans_n{ 0 }, ans_y{ 0 };

int x_arr[] = {0,0,1,-1};
int y_arr[] = {1,-1,0,0};

void dfs_n(int x, int y) {
    visit[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int new_x = x + x_arr[i];
        int new_y = y + y_arr[i];

        if (1 <= new_x && new_x <= N && 1 <= new_y && new_y <= N && !visit[new_x][new_y]) {
            if (arr[new_x][new_y] == arr[x][y]) {
                dfs_n(new_x, new_y);
            }
        }
    }
}

void dfs_y(int x, int y) {
    visit[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int new_x = x + x_arr[i];
        int new_y = y + y_arr[i];

        if (1 <= new_x && new_x <= N && 1 <= new_y && new_y <= N && !visit[new_x][new_y]) {
            if (arr[x][y] != 'B' && arr[new_x][new_y] != 'B') {
                dfs_y(new_x, new_y);
            }
            else if (arr[x][y] == 'B' && arr[new_x][new_y] == 'B') {
                dfs_y(new_x, new_y);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    string s;

    for (int y = 1; y <= N; y++) {
        cin >> s;
        for (int x = 1; x <= N; x++) {
            arr[x][y] = s[x - 1];
        }
    }

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            if (!visit[x][y]) {
                ans_n++;
                dfs_n(x, y);
            }
        }
    }

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            visit[x][y] = false;
        }
    }

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            if (!visit[x][y]) {
                dfs_y(x, y);
                ans_y++;
            }
        }
    }

    cout << ans_n << " " << ans_y;



}