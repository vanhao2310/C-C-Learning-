/*
    Problem: Week 5 - Hamiton Cycle
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

vector<set<int>> adj;   //danh sach canh ke
vector<bool> visited;    // danh dau dinh da duoc tham hay chua
vector<int> visit_node;      //danh dau dinh duoc tham o lan tham thu i
bool iscycle = false;

void Try(int k, int n){
    if(iscycle)
        return;
    for(int i = 1; i <= n; i++){
        if(!visited[i] && adj[visit_node[k-1]].count(i)){    //neu dinh i chua duoc tham va co duong di tu dinh trc do toi dinh i 
                visit_node[k] = i;
                visited[i] = true;
                if(k == n){
                    if(adj[i].count(1)){    //neu tu dinh cuoi cung co duong di quay tro lai dinh 1 thi co chu trinh
                        iscycle = true;
                        return;
                    }
                }else   Try(k+1, n);

                visited[i] = false;
        }
    }
}

int main(){
    int n;  //number graph
    int node, edge;
    int v1, v2; //2 dinh cua do thi 
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> node >> edge;
        adj.resize(node+1);
        visited.resize(node + 1);
        visit_node.resize(node+1);
        // memset(&visit_node[0], 0, sizeof(int)*node);
        for(int j = 1; j <= n; j++)    //danh dau false: tat ca cac dinh deu chua tham
            visited[j] = false;
        for(int j = 0; j < edge; j++){
            cin >> v1 >> v2;
            adj[v1].insert(v2);
            adj[v2].insert(v1);
        }
        visit_node[0] = 1;
        Try(1, node);
        if(iscycle)
            cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}
