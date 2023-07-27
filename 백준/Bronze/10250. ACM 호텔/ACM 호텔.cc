#include <iostream>
using namespace std;

int main() {
    int T, H, W, N;
    cin >> T;
    
    while(T--) {
        cin >> H >> W >> N;
        
        int H_ans = N % H;
        int W_ans = N / H;
        
        if (H_ans == 0) H_ans = H;
        else W_ans++;
        
        if (W_ans < 10) cout << H_ans << 0 << W_ans << "\n";
        else cout << H_ans << W_ans << "\n";
    }
}