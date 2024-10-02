#include<bits/stdc++.h>
using namespace std;

int n, m, r, c;
int a[1000][1000];
bool visited[1000][1000];
int moveX[] = {0, -1, 0, 1};
int moveY[] = {-1, 0, 1, 0};
queue<pair<int, int>> q;
map<pair<int, int>, int> d;//luu so buoc di duoc tu start den diem co toa do (x,y)

int  main(){
    cin >> n >> m >> r >> c;

    //nhap vao ma tran n*m
    for(int i = 1 ; i <= n; ++i){
        for(int j = 1 ; j <=m ; ++j){
            cin>> a[i][j];
        }
    }

    pair<int,int> start = make_pair(r, c);
    q.push(start);
    visited[r][c] = true;
    d[start] = 1;

    while(!q.empty()){
        pair<int,int> u
         = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int x = u.first + moveX[i];
            int y = u.second + moveY[i];
            if(!visited[x][y] && !a[x][y]){ //chua tham va a[x][y] = 0
                pair<int, int> v = make_pair(x, y);
                q.push(v);
                visited[x][y] = true;
                d[v] = d[u] + 1;    //so buoc di den v = so buoc den u u + 1
                if(x==1 || y == 1 || x==n || y ==m){ //di ra khoi me cung
                    cout << d[v];
                    return 0;
                }
            }
        }
    }

    cout << -1;
    return 0;

}
