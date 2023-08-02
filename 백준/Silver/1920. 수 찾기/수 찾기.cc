#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    
    int N, M, num;
    
    cin >> N;
    
    int* arr = new int[N];
    
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+N);
    
    cin >> M;
    
    for (int i=0;i<M;i++) {
        cin >> num;
        
        int left = 0;
        int right = N-1;
        int mid;
        
        int TF = 0;
        while(left <= right) {
            mid = (left + right) / 2;
            if (arr[mid] == num) {
                TF = 1;
                break;
            }
            else if (arr[mid] > num) {
                right = mid - 1;
            }
            else if (arr[mid] < num) {
                left = mid + 1;
            }
        }
        
        cout << TF << '\n';
    }
    
}