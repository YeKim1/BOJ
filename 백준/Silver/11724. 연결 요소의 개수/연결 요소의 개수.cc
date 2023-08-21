#include <iostream>
#include <vector>
using namespace std;

int N, M, u, v, cnt{0};
bool visit[1001];
vector<vector<int>> vec(1001);

void dfs(int cur) {
    visit[cur] = true;
    
    for (int i=0;i<vec[cur].size();i++) {
        if (!visit[vec[cur][i]]) dfs(vec[cur][i]);
    }
}

int main() {
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    for (int i=1;i<=N;i++) {
        if (!visit[i]) {
            dfs(i);
            cnt++;
        }
    }
    
    cout << cnt;
}