#include<bits/stdc++.h>
using namespace std;

int main(){
    int *arr1 , *arr2;
    int n , m;
    cin >> n >> m;
    arr1 = new int[n];
    arr2 = new int[m];

    for( int i = 0 ; i < n ; i++)
        cin >> arr1[i];
    for( int j = 0 ; j < m ; j++ )
        cin>> arr2[j];

    sort( arr1 , arr1 + n );
    sort( arr2 , arr2 + m );

    int j = 0;
    for( int i = 0 ; i < n && j< m ; i++ ){
        if( arr1[i] == arr2[j] ){
            j++;
        }
    }
    if( j >= m )
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

