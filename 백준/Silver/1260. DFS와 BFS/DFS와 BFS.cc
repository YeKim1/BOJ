#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<vector<int>> graph(1001, vector<int>());
bool visit[1001];

void DFS(int cur) {
    cout << cur << " ";
    visit[cur] = 1;

    for (int i = 0; i < graph[cur].size(); i++) {
        if (!visit[graph[cur][i]]) DFS(graph[cur][i]);
    }
}

void BFS() {
    queue<int> q;
    q.push(V);
    visit[V] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int i = 0; i < graph[cur].size(); i++) {
            if (!visit[graph[cur][i]]) {
                q.push(graph[cur][i]);
                visit[graph[cur][i]] = 1;
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;

    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 0; i <= N; i++) {
        visit[i] = 0;
        sort(graph[i].begin(), graph[i].end());
    }
    DFS(V);
    cout << "\n";
    for (int i = 0; i <= N; i++) {
        visit[i] = 0;
    }
    BFS();


}