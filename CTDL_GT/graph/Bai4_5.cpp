//Vu Van Hao 20215572
/*
Bài tập 5:
Viết hàm thực hiện thuật toán DFS không sử dụng đệ quy trên đồ thị biểu diễn bằng danh sách kề vector< list<int> >. 
Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán DFS xuất phát từ đỉnh 1. Các đỉnh được thăm theo thứ tự 
ưu tiên từ trái sang phải trong danh sách kề. Yêu cầu hàm trả ra thứ tự các đỉnh được thăm 
(những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
*/
#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    
    /*****************
    Vu Van Hao 20215572
    *****************/
    while(!S.empty()){
        int v = S.top();
        if( !visited[v] ){
            //neu dinh v chua tham thi in ra v va danh dau v da duoc tham
            visited[v] = true;
            cout << v << endl;
        }
        if( !adj[v].empty() ){  
            int tmp = adj[v].front();
            //lay ra dinh ke cua v
            adj[v].pop_front();
            if(!visited[tmp]){  //neu dinh ke do chua dc tham thi push vao stack de xet(goi de quy tham dinh ke cua v) 
                S.push(tmp);
            }
            
        }else{  //v khong con dinh ke nua
            S.pop();    //loai bo v ra khoi stack
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
    dfs(adj);
    return 0;
}
//Vu Van Hao 20215572