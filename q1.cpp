#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s , char last){
    if( s.length() == 0 ){
        return "";
    }
    if( s[0] == last ){
        return removeDuplicates(s.substr(1) , last);
    }else{
        return  s[0] + removeDuplicates(s.substr(1) , s[0]);
    }
}

int main(){
    string s;
    cin >> s;
    s = removeDuplicates(s , '\0');
    cout << s;
}
