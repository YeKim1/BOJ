#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	map<string, string> m;

	int N, M;
	string site, passwd;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> site >> passwd;
		m[site] = passwd;
	}

	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << m[site] << "\n";
	}
}