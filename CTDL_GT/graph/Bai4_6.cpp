//Vu Van Hao 20215572
/*
Bài tập 6:
Viết hàm thực hiện thuật toán BFS không sử dụng đệ quy trên đồ thị biểu diễn bằng danh sách kề vector< list<int> >. 
Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán BFS xuất phát từ đỉnh 1. Các đỉnh được thăm theo thứ tự ưu tiên 
từ trái sang phải trong danh sách kề. Yêu cầu hàm trả ra thứ tự các đỉnh được thăm 
(những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
*/
#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;
void bfs(vector< list<int> > adj) {
    queue<int> Q;   //hang doi cac dinh can duoc tham
    vector<bool> visited(adj.size());   //vector danh dau xem dinh do duoc day vao hang doi chua
    Q.push(1); // Bắt đầu từ đỉnh số 1
    visited[1] = true;  //danh dau dinh 1 da duoc day vao hang doi de cho duoc tham
    
    /*****************
    Vu Van Hao 20215572
    *****************/
    while(!Q.empty()){
        int v = Q.front();  //lay ra dinh dau  tien cua hang doi
        cout << v << endl;
        Q.pop();    //tham  dinh do va loai bo ra khoi hang doi
        if(!adj[v].empty()){ //kiem tra xem v co canh ke khong
            for(int u : adj[v]){
                //duyet cac dinh ke voi v 
                if(!visited[u]){
                    //neu dinh nay chua duoc day vao queue thi day vao queue va danh dau da duoc day vao queue roi
                    Q.push(u);
                    visited[u] = true;
                }
            }
        }
    }
}
int main(){
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    bfs(adj);
    return 0;
}
//Vu Van Hao 20215572