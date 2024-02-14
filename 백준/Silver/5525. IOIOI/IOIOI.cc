#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(); cout.tie();
	ios::sync_with_stdio(false);

	int n, m;
	string s;

	cin >> n >> m >> s;

	string comp = "I";
	for (int i = 0; i < n; i++) {
		comp += "OI";
	}

	vector<int> f;
	f.push_back(0);
	for (int i = 1; i < comp.size(); i++) {
		if (comp[i - 1] == comp[i]) f.push_back(f[i - 1] + 1);
		else f.push_back(0);
	}

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i + comp.size() > s.size()) break;

		bool isOK = true;
		for (int j = 0; j < comp.size(); j++) {
			if (s[i + j] != comp[j]) {
				isOK = false;
				break;
			}
		}
		if (isOK) ans++;
	}

	cout << ans;
}