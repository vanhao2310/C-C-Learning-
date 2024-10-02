/*
    Problem: Week 6 - All pair shortest paths
    author: Vu Van Hao : 20215572
*/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 10001
#define INF 1e9

vector<vector<pair<int, int>>> adj(MAXN); //danh sach ke va trong so
int n, m;
// vector<vector<int>> distance(MAXN);

void Dijkstra(int s){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    vector<int> d_min(MAXN, INF);
    d_min[s] = 0;
    Q.push({0, s});
    while(!Q.empty()){
        pair<int, int> curr = Q.top(); Q.pop(); //lay ra dinh co duong di tu s ngan nhat
        int u = curr.second;    //u la dinh dang set
        int d_u = curr.first;   //do dai duong di tu s->u
        if(d_u > d_min[u])  continue;

        for(auto adj_u : adj[u]){   //xet cac dinh ke voi u de cap nhat duong di toi cac dinh do
            int v = adj_u.first;    //v la dinh ke voi u
            int w = adj_u.second;   //w la trong so dinh u->v
            if(d_min[v] > d_min[u] + w){  //neu duong di toi v qua u ngan hon thi cap nhat lai duong di cho v
                d_min[v] = d_min[u] + w; 
                Q.push({d_min[v], v});  //day dinh v vao queue de xet cac dinh ke voi v o lan sau
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << d_min[i] << " ";
    cout << "\n";
}

void input(){
    cin >> n >> m;
    int u, v, w;
    for(int i = 0 ; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
}
int main(){
    input();
    for(int i = 1; i <= n; i++){
        Dijkstra(i);
    }
    return 0;
}