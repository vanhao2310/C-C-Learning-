#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000

int n, m;
vector<int> adj[MAX_N];
bool visited[MAX_N];
int low[MAX_N];
int num[MAX_N];
int cnt;
stack<int> scc; //stack chua cac dinh thuoc cung 1 thanh phan lien thong
bool inStack[MAX_N];
int nbscc;

void input() {
    cin >> n >> m;
    int u, v;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
}


void dfs(int s, int ps) {
    cnt++;
    num[s] = cnt;
    low[s] = num[s];
    visited[s] = true;
    scc.push(s);
    inStack[s] = true;
    for (auto v : adj[s]) {

        if (visited[v]){ //canh nguoc
            if (inStack[v])
                low[s] = min(low[s], num[v]);
        } else {
            dfs(v, s);
            //dfs v da duyet xong -> cap nhat low[s]
            low[s] = min(low[s], low[v]);
        }
    }
    //kiem tra co thanh phan lien thong manh khong
    if (low[s] == num[s]) {
        //goc cua thanh phan lien thong manh
        //loai bo cac dinh thuoc 1 tp lien thong ra khoi stack
        while (true) {
            int tmp = scc.top();
            scc.pop();
            inStack[tmp] = false;
            if (tmp == s)
                break;
        }
        nbscc++;
    }

}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i, -1);
    }

    cout << nbscc;
}


int main() {
    input();
    solve();
    return 0;
}
