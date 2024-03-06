#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSelf[10001];

int main() {
	for (int i = 1; i <= 10000; i++) {
		int sum = 0;
		string str = to_string(i);
		for (int i = 0; i < str.size(); i++) sum = sum + stoi(str.substr(i, 1));
		if (i + sum <= 10000) isSelf[i + sum] = true;
	}

	for (int i = 1; i <= 10000; i++) {
		if (!isSelf[i]) cout << i << "\n";
	}
}
