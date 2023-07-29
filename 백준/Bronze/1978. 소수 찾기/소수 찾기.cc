#include <iostream>
using namespace std;

bool isP(int n) {
    if (n==1) return false;
    
    for (int i=2;i<=n-1;i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N, num;
    cin >> N;
    
    int ans=0;
    for (int i=0;i<N;i++) {
        cin >> num;
        if (isP(num)) ans++;
    }
    cout << ans;
}