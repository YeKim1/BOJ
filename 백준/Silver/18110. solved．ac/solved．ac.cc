#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;

    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());        
    
    int except = round(n * 0.15);

    double ans = 0;
    for (int i = except; i < (n - except); i++) {
        ans += v[i];
    }

    ans = round(ans / (n - except * 2));
    cout << ans;

}