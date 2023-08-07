#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    
    int res = 1;
    for (int i=n;i>=1;i--) res *= i;
    
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << factorial(n) / (factorial(k) * factorial(n-k));
}