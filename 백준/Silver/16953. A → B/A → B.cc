#include <iostream>
#include <queue>
using namespace std;

int a, b;

int main() {
	cin >> a >> b;

	queue<pair<long long, long long>> q;
	q.push(make_pair(a, 1));

	bool flag = false;
	while (!q.empty()) {
		pair<long long, long long> cur = q.front();
		q.pop();

		if (cur.first == b) {
			cout << cur.second++;
			flag = true;
			break;
		}

		if (cur.first * 2 <= b) q.push(make_pair(cur.first * 2, cur.second + 1));
		if (cur.first * 10 + 1 <= b) q.push(make_pair(cur.first * 10 + 1, cur.second + 1));
	}

	if (flag == false) cout << -1;
}