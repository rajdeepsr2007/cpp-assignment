#include<bits/stdc++.h>
using namespace std;

int main(){
    int *arr;
    int n;
    cin >> n;
    arr = new int[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    int ans = INT_MIN , sum = 0 ;
    for( int i = 0 ; i < n ; i++ ){
        sum = sum + arr[i];
        ans = max( ans , sum );
        if( sum <= 0 ){
            sum = 0;
        }
    }
    cout << ans;
}
