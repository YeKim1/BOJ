#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long T, k, n;
	char c;

	cin >> T;
	while (T--) {
		multiset <long long> s;
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> c >> n;
			if (c == 'I') s.insert(n);
			else if (c == 'D' && !s.empty()) {
				if (n == -1) s.erase(s.begin());
				else s.erase(--s.end());
			}
		}

		if (s.empty()) cout << "EMPTY\n";
		else cout << *--s.end() << " " << *s.begin() << "\n";
	}
}