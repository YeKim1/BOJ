#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int ans = 1;
    int cur = 1;
    while (N > cur) {
        cur += (6 * ans);
        ans++;
    }
    cout << ans;
}