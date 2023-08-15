#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fibo[50] = { 0,1, };

int fibo_func(int n) {
	if (n == 0 || n == 1) return fibo[n];
	else if (fibo[n] == 0) fibo[n] = fibo_func(n - 1) + fibo_func(n - 2);
	return fibo[n];

}

int main() {
	int T, n;

	cin >> T;

	while (T--) {
		cin >> n;

		if (n == 0) cout << "1 0" << "\n";
		else cout << fibo_func(n - 1) << " " << fibo_func(n) << "\n";
	}
}