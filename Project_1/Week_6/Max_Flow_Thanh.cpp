#include <iostream>
#include <queue>
#include <cstring>

#define MAX_V 10004
using namespace std;

int n, m, s, t;
vector<int> adj[MAX_V];
int capacity[MAX_V][MAX_V];


void input() {
    cin >> n >> m >> s >> t;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >>u >> v >> w;
        adj[u].push_back(v);
        capacity[u][v] = w;
    }
}

// tìm đường đi có số cạnh ngắn nhất từ s tới t, lưu đường đi vào mảng parent
bool bfs(int s, int t, int parent[]) {
    bool visited[MAX_V];
    memset(visited, false, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
           if (!visited[v] && capacity[u][v] > 0) {
                q.push(v);
                visited[v] = true;
                parent[v] = u; 
                if (v == t) return true;
           }
        }
    }
    return false;
}

int Edmonds_Karp(int s, int t) {
    int parent[MAX_V];
    int max_flow = 0;

    while(bfs(s, t, parent)) {
        
        // tìm giá trị đường tăng luồng
        int augment = 1e9;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            augment = min(augment, capacity[u][v]);
        }

        //cập nhập lại giá trị của khả năng thông qua trên các cạnh.
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= augment;
        }

        max_flow += augment; // tăng luồng
    }

    return max_flow;
}

int main() {
    input();
    cout << Edmonds_Karp(s, t);
}