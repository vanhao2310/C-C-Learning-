/*
    Problem: Week 3 - Simulation Stack
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    string query;
    stack<int> st;
    while(getline(cin, query)){
        if(query == "#")
            break;
        int index_space = query.find(' ');
        if(index_space < 0)
        {
            if(st.empty())
                cout << "NULL" << endl;
            else{
                cout << st.top() << endl;
                st.pop();
            }
        }else{
            int num = stoi(query.substr(index_space + 1, query.length()- index_space -1 ));
            st.push(num);
        }
    }    
    return 0;
}