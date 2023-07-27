#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X, A;
    
    cin >> N >> X;
    
    vector<int> ans;
    
    for (int i=0;i<N;i++) {
        cin >> A;
        
        if (A < X) ans.push_back(A);
    }
    
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
}