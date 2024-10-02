/*
    Problem: Week 6 - Max Flow
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10001     //so dinh toi da
#define MAX_M 1000001   //so cung toi da

int N, M;   //so dinh va so sanh
int s, t;   //dinh nguon va dinh dich
vector<vector<pair<int, int>>> adj(MAX_N);   //danh sach canh ke cua network voi kha nang thong qua (capacity)
vector<vector<pair<int, int>>> F(MAX_N);     //luong
vector<vector<pair<int, int>>> CF(MAX_N);    //trong so danh sach ke cua do thi luong du
vector<int> d(MAX_N, -1);   //danh dau duong di

void BuildResidualGraph(){  //xay dung do thi luong du voi danh sach ke va luong F hien co
    for(int i = 1; i <= N; i++){
        CF[i].clear();
    }
    for(int i = 1; i <= N; i++){    //xet cac dinh cua do thi va luong hien co de xay dung luong du
        for(int j = 0; j < adj[i].size(); j++){
            int u = adj[i][j].first;    //sinh ke voi dinh i  
            int capacity = adj[i][j].second;   //kha nang thong qua cua canh tu i->u  
            int fl = F[i][j].second;    //gia tri hien tai cua luong tu i->u
            if(fl < capacity){   //neu luong chua den gioi han capacity
                CF[i].push_back({u, capacity - fl});
            }
            if(fl > 0){
                CF[u].push_back({i, fl});
            }
        }
    }
}

void BFS(){     
    vector<int> visited(N+1, 0);    //danh dau cac dinh da tham
    memset(&d[0], -1, sizeof(int)*(N+1));
    queue<int> Q;
    Q.push(s);
    visited[s] = 1;
    d[s] = s;
    while(!Q.empty()){
        int curr = Q.front(); Q.pop();  //lay ra dinh o dau Q va tham
        if(!CF[curr].empty()){
            for(auto i : CF[curr]){    //duyet cac canh ke voi curr
                if(!visited[i.first]){
                    Q.push(i.first);
                    d[i.first] = curr;
                    visited[i.first] = 1;
                }
            }
        }
    }

}

bool check(int u, int v){
    for(auto a : adj[u]){
        if(a.first == v )
            return true;
    }
    return false;
}

void Agument(int delta){     //tang luong len delta
    int v = t;
    while(v != d[v]){
        if(check(d[v], v)){
            for(int i = 0; i < F[d[v]].size(); i++){
                if(F[d[v]][i].first == v && F[d[v]][i].second < adj[d[v]][i].second ){
                    F[d[v]][i].second += delta;
                    break;
                }
            }
        }else{
            for(auto &a : F[v]){
                if(a.first == d[v])
                    a.second += delta;
            }
        }
        v = d[v];
    }
}

void FordFulkerson(){
    while(1){
        BuildResidualGraph();       //thiet lap do thi luong dư
        BFS();      //gọi BFS lưu đường đi vào vector d ( d[i] = u: i được thăm từ u)
        if(d[t] == -1)
            break;  //khong co duong den dinh dich 

        //find delta
        int v = t;
        int delta = 1e9;
        while(d[v] != v){
            for(auto a : CF[d[v]]){
                if(a.first == v && a.second < delta){
                    delta = a.second;
                }
            }
            v = d[v];
        }
        Agument(delta);
    }

}

int GetFlowValue(){
    int value = 0;
    for(auto a : F[s])
        value += a.second;
    return value;
}

void input(){
    cin >> N >> M;
    cin >> s >> t;
    int u, v, w;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        F[u].push_back({v, 0});
    }
}


int main(){
    input();    
    FordFulkerson();
    cout << GetFlowValue();
    return 0;
}
