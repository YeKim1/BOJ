#include <iostream>
#include <vector>
using namespace std;
#define root 1
#define MAX 100001

int N;
vector<int> vec[MAX];
int parents[MAX];

void dfs(int cur) {

	for (int i = 0; i < vec[cur].size(); i++) {
		int tmp = vec[cur][i];
		if (parents[tmp] == 0) {
			parents[tmp] = cur;
			dfs(tmp);
		}
	}
}

int main() {
	cin >> N;

	int a, b;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	dfs(root);

	for (int i = 2; i <= N; i++) {
		cout << parents[i] << "\n";
	}
}