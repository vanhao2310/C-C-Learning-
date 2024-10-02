/*
    Problem: Week 5 - Sequence of nodes visited by BFS
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

vector<list<int>> adj;
void BFS(){
    vector<bool> visited(adj.size(), false);    //danh dau diem da duoc tham hay chua
    queue<int> Q;   

    Q.push(1);
    visited[1] = true;
    bool exit = false;
    while(!exit){
        while(!Q.empty()){
            int v = Q.front();
            cout << v << " ";
            Q.pop();    //lay v ra khoi hang doi va tham

            while(!adj[v].empty()){  // them cac dinh ke voi v chua duoc day vao queue
                int tmp = adj[v].front();
                adj[v].pop_front();
                if(!visited[tmp]){
                    Q.push(tmp);
                    visited[tmp] = true;    //danh dau dinh tmp da duoc tham
                }
            }
        }
        exit = true;
        //kiem tra xem co dinh khong duoc lien ket khong 
        for(int i = 1; i < visited.size(); i++){
            if(!visited[i]){    //dinh i chua tham thi day vao queue va duyet BFS voi nhanh i 
                Q.push(i);
                visited[i] = true;
                exit = false;  
                break;
            }
        }
    }
        
}
bool ss(int a, int b){
    return a < b;
}
int main(){
    bool (*s)(int, int) = &ss;
    int n, m;   //n: so dinh do thi
                //m: so canh do thi
    cin >> n >> m;
    adj.resize(n+1);
    int v1, v2;     //v1 v2 la hai dinh cua do thi
    for(int i = 0; i < m; i++){
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    for(int i = 0; i < adj.size(); i++)
        adj[i].sort(s);  //sap xep lai jcac dinh ke theo thu tu tu be den lon
    BFS();
    return 0;
}