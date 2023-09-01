#include <iostream>
using namespace std;

int main() {
    int n;
    int DP[1001];
    
    cin >> n;
    
    DP[1] = 1;
    DP[2] = 3;
    
    for (int i=3;i<=n;i++) {
        DP[i] = (DP[i-1] + DP[i-2] * 2) % 10007;
    }
    
    cout << DP[n];
}