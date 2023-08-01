#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie();
    
    int N, num;
    cin >> N;
    
    int arr[10001];
    for (int i=0;i<10001;i++) {arr[i] = 0;}
    
    for (int i=0;i<N;i++) {
        cin >> num;
        
        arr[num]++;
    }
    
    for (int i=1;i<=10000;i++) {
        for (int j=0;j<arr[i];j++) cout << i << "\n";
    }
}