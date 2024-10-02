/*
    Problem: Week 5 - List order of nodes visited by a DFS
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;    //danh sach ke


//DFS 
void DFS(){
    vector<bool> visited(adj.size(), false);
    stack<int> S;
    S.push(1);
    while(!S.empty()){
        //lay ra dinh o dau stack va tham
        int v = S.top();   
        if(!visited[v]){
            visited[v] = true;  
            cout << v << " ";
        }

        if(!adj[v].empty()){    //neu dinh v co cac dinh ke thi tham cac dinh ke voi v
            int tmp = adj[v].front();   //dinh ke dau tien voi v
            adj[v].erase(adj[v].begin());
            if(!visited[tmp]){
                //neu dinh tmp chua duoc tham
                S.push(tmp);
            }
        }else{//neu cac dinh ke voi v da duoc tham roi
            S.pop();    //loai bo dinh v ra khoi stack
        }
    }
}

int main(){
    int n, m;
    cin  >> n >> m; //n so dinh
                    //m so canh
    adj.resize(n+1);
    int v1, v2;     //v1 v2 2 dinh nhap ke nhau 
    for(int i = 0; i < m; i++){
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    DFS();
    return 0;
}