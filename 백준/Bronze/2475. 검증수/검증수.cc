#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    int num;
    for (int i=0;i<5;i++) {
        cin >> num;
        ans += (num * num);
    }
    
    ans %= 10;
    
    cout << ans;
}