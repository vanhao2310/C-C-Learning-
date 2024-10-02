/*
    Problem: Week 3 - Simulation Queue
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    string query;
    while(getline(cin, query)){
        if(query == "#")
            break;
        else{
            int index_space = query.find(' ');
            if(index_space < 0){
                if(q.empty())
                    cout << "NULL" << endl;
                else{
                    cout << q.front() << endl;
                    q.pop();
                }   
            }else{
                int num = stoi(query.substr(index_space + 1, query.length() - index_space - 1));
                q.push(num);
            }

        }
    }
    return 0;
}