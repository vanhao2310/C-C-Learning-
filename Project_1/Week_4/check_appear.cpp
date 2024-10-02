/*
    Problem: Week 4 - Kiểm tra xuất hiện
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, num;
    cin >> n;
    set<int> data;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(data.count(num)){
            cout << 1 << "\n";
        }else{
            data.insert(num);
            cout << 0 << "\n";
        }  

    }
    return 0;
}