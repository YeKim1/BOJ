#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    
    cin >> N;
    
    double* arr = new double[N];
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+N);
    
    double M = arr[N-1];
    
    double sum = 0;
    for (int i=0;i<N;i++) {
        sum += arr[i] / M * 100;
    }
    
    cout << sum / N; 
    
    
    
}