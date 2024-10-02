/*
    Problem: Week 4 - Hash Over Strings
    author: Vu Van Hao - 20215572
*/

//(a+b+c)%m = (a%m + b%m + c%m)%m
//(a*b*c)%m = [(a%m)*(b%m)*(c%m)]%m
#include<bits/stdc++.h>
using namespace std;
int hash_string(string s, int m){
    int len = s.length();
    int result = 0;
    for(int i = 0; i < len; i++){
        result = ((result*256)%m + s[i]%m ) % m;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    string s;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        cout << hash_string(s, m) << '\n'; 
    }
}