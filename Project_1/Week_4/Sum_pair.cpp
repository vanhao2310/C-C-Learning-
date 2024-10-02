/*
    Problem: Week 4 - Sum pair of sequence equal to a number
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, M, num, count = 0;
    cin >> n >> M;
    set<int> data;
    for(int i = 0; i < n; i++){
        cin >> num;
        data.insert(num);
    }
    for(auto it = data.begin(); it != data.end(); it++){
        if(data.count(M-(*it)))
            count ++;
    }
    cout << count/2;
    return 0;
}