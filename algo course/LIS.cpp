#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int LIS(int a[], int n) {
    int lis[n+5] = {0};
    for(int i = 0; i < n; i++) {
        lis[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j] && lis[i] <= lis[j])
                lis[i] = 1 + lis[j];
        }
    }
    int mx= INT_MIN;
    for(int i = 0; i < n; i++) {
        mx= max(mx,lis[i]);
    }
    return mx;
}


int main()
{
    int n; cin >> n;
    int arr[n+10];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << LIS(arr,n);
    return 0;
}
