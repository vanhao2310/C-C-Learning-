#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define MAX_N 1000000
int n;
vector<pii> adj[MAX_N];
bool visited[MAX_N];
int d[MAX_N];
int pv[MAX_N];

void input() {
    cin >> n;
    int u, v, w;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        d[i] = -1;
        pv[i] = -1;
    }

}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    d[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto node : adj[u]) {
            int v = node.first;
            int w = node.second;
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                d[v] = d[u] + w;
                pv[v] = u;
            }
        }
    }

}

int find_max() {
    int d_max = -1, u = -1;
    for (int i = 1; i <= n; i++) {
        if (d[i] > d_max) {
            d_max = d[i];
            u = i;
        }
    }
    return u;

}

void solve() {
    init();
    bfs(1);
    int u = find_max();
    init();
    bfs(u);
    u = find_max();
    cout << d[u];
}

int main() {
    input();
    solve();
    return 0;
}
