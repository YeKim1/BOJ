#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int t, a, b;
bool visit[10000];

void run() {
	queue<pair<int, string>> q;
	q.push(make_pair(a, ""));
	visit[a] = true;

	while (!q.empty()) {
		int cur_num = q.front().first;
		string cur_op = q.front().second;
		q.pop();

		if (cur_num == b) {
			cout << cur_op << "\n";
			return;
		}

		int D, S, L, R;

		D = cur_num * 2 > 9999 ? cur_num * 2 % 10000 : cur_num * 2;
		if (!visit[D]) {
			q.push(make_pair(D, cur_op + "D"));
			visit[D] = true;
		}

		S = cur_num == 0 ? 9999 : cur_num - 1;
		if (!visit[S]) {
			q.push(make_pair(S, cur_op + "S"));
			visit[S] = true;
		}

		L = (cur_num % 1000) * 10 + (cur_num / 1000);
		if (!visit[L]) {
			q.push(make_pair(L, cur_op + "L"));
			visit[L] = true;
		}

		R = cur_num / 10 + (cur_num % 10) * 1000;
		if (!visit[R]) {
			q.push(make_pair(R, cur_op + "R"));
			visit[R] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> t;

	while (t--) {
		cin >> a >> b;
		memset(visit, false, sizeof(visit));
		run();
	}
}