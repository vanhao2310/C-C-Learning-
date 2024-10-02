/*
    Problem: Week 6 - Shortest Path between 2 nodes on a directed graph with non-negative weights
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 100001
#define INF 1e9

int n, m; //so dinh va so canh
int s, t;   //tim duong di ngan nhat giua s va t
vector<vector<pair<int, int>>> adj(MAXN); //danh sach canh ke

void Dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;  //greater se so sanh first cua pair
    vector<int> distance(MAXN, INF);    //ban dau do dai duong di tu s -> cac dinh la vo cung
    vector<int> prev(MAXN);   //luu dinh duoc di tu dinh nao truoc do
    Q.push({0, s}); //duong di tu s->s = 0 va push vao hang doi uu tien
    distance[s] = 0;
    prev[s] = s;

    while(!Q.empty()){
        pair<int, int> current = Q.top(); Q.pop();    //lay ra dinh co duong di tu s nho nhat trong hang doi
        int u = current.second; //dinh dang xet
        int d = current.first;  //khoang cach tu s->u
        if(d > distance[u])     continue;   //neu d > distance co nghia dinh da co duong di tu dinh khac nho hon roi khong tiep tuc set

        for(auto adj_u : adj[u]){   //cap nhat duong di cho cac dinh ke voi u
            int v = adj_u.first;    //v: dinh ke voi dinh u
            int w = adj_u.second;   //w: trong so tu dinh u->v
            if(distance[v] > distance[u] + w){  //neu duong di toi v thong qua u ngan hon duong di truoc do thi cap nhat lai duong di cho v
                distance[v] = distance[u] + w;
                Q.push({distance[v], v});   //day dinh v vao hang doi de set lai cac dinh ke voi v 
                prev[v] = u;
            }
        }
    }
    //in ra duong di tu s->t
    int tmp = t;
    vector<int> path;
    while(tmp != prev[tmp]){
        path.push_back(tmp);
        tmp = prev[tmp];
    }
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;

    cout << distance[t];
}

void input(){
    cin >> n >> m;
    int u, v, w;    //u: dinh dau | v: dinh cuoi | w: trong so
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cin >> s >> t;
}

int main(){

    input();
    Dijkstra();
    return 0;
}