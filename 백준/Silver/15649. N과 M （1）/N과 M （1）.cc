#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visit[9];
int arr[9];

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < depth; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[depth] = i + 1;
			dfs(depth + 1);
			visit[i] = false;
		}
	}

}

int main() {
	cin >> n >> m;

	dfs(0);
}