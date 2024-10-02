/*
    Problem: Week 4 - Store & Search String
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    set<string> database;
    string c;
    while(cin >> c){
        if(c == "*")
            break;
        database.insert(c);
    }
    string s;
    while(cin >> c){
        if(c == "***")
            break;
        cin >> s;
        if(c == "find"){
            if(database.find(s) != database.end())
                cout << 1 << "\n";
            else 
                cout << 0 << "\n";

        }else if(c == "insert"){
            if(database.count(s))   //s da ton tai trong set
                cout << 0 << "\n";
            else{
                database.insert(s);
                cout << 1 << '\n';
            }
        }
    }
    return 0;
}