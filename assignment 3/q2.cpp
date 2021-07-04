#include<bits/stdc++.h>
using namespace std;

int findDoublet( int *arr , int x , int start , int end ){
    int i = start , j = end;
    int ans = 0;
    while( i < j ){
        int sum = arr[i] + arr[j];
        if( sum > x ){
            j--;
        }else if( sum < x ){
            i++;
        }else{
            int count1 = 0, a = arr[i];
            int count2 = 0 , b = arr[j];
            if( arr[i] == arr[j] ){
                ans += ((j - i + 1)*(j - i)) / 2;
                return ans;
            }else{
                while( arr[i] == a ){
                    i++;
                    count1 ++;
                }
                while( arr[j] == b ){
                    j--;
                    count2++;
                }
                ans+=(count1*count2);
            }
        }
    }
    return ans;
}

int main(){
    int *arr;
    int n , x;
    int ans = 0;
    cin >> n >> x;
    arr = new int[n];
    for( int i = 0;  i < n ; i++ )
        cin >> arr[i];
    sort(arr , arr+n);
    for( int i = 0 ; i < n - 2 ; i++ )
        ans = ans + findDoublet( arr , x - arr[i] ,i + 1 , n-1 );
    cout << ans;
}

