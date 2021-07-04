#include<bits/stdc++.h>
using namespace std;

int main(){
    int *arr;
    int n;
    cin >> n;
    arr = new int[n];
    int j = 1;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    int last = arr[0];
    for( int i = 1 ; i < n ; i++ ){

        if(arr[i]!= last)
        {
            last = arr[i];
            arr[j] = arr[i];
            j++;
        }
    }
    n = j;
    for( int i = 0 ; i < n ; i++ ){
        cout << arr[i] << ' ' ;
    }
}
