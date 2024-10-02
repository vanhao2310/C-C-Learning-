/*
    Problem: Week 5 - Minimum Spanning Tree - Kruskal
    author: Vu Van Hao 20215572
*/
#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u, v;   //u dinh dau v dinh cuoi
    int w;  // trong so canh
    edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int n, m;   //n: so dinh, m: so canh
const int MAX_VERTEX = 100001;
int parent[MAX_VERTEX]; //cha goc cua node
int sizze[MAX_VERTEX];   //kich thuoc cay
vector<edge> Edge;  //edge of graph

//khoi tao cac tap hop
void make_set(){    
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sizze[i] = 1;
    }
}

//tim cha cua u
int find(int u){
    if(u == parent[u])  return u;
    return parent[u] = find(parent[u]);
}

//keim tra va hop tap hop voi nhau
bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) //neu a va b da cung 1 tap hop thi khong ket hop nua
        return false;
    
    if(sizze[b] > sizze[a])  swap(a, b);
    parent[b] = a;
    sizze[a] += sizze[b];
    return true;
}

void input(){
    cin >> n >> m;  //n: so dinh va m: so canh
    int u, v, w;    //dinh dau dinh cuoi va trong so cua canh
    for(int i = 0; i < m ; i++){
        cin >> u >> v >> w;
        edge e = edge(u, v, w);
        Edge.push_back(e);
    }
}


void kruskal(){
    vector<edge> MST;   //edge of minimum spanning tree
    int weight = 0;     //trong so cua MST
    //sort cac canh theo trong so
    sort(Edge.begin(), Edge.end(), [](edge a, edge b) -> bool { return a.w < b.w;   });

    //duyet cac canh theo trong so tu be den lon
    for(int i = 0 ; i < m; i++){
        if(MST.size() == n-1)   break;  //MST da co du tat ca cac dinh

        edge e = Edge[i];   
        if(Union(e.u, e.v)){    //neu them canh e vao MST khong tao thanh chu trinh
            MST.push_back(e);   //them e vao MST
            weight += e.w;      //cong them trong so
        }
    }
    cout << weight;
}

int main(){
    input();
    make_set();
    kruskal();
    return 1;
}