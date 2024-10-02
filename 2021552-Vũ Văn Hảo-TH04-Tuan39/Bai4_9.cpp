//Vu Van Hao 20215572
/*
Bài tập 9:
Cài đặt thuật toán Dijkstra trên đồ thị vô hướng được biểu diễn bằng danh sách kề sử dụng priority_queue Cụ thể, 
bạn cần cài đặt hàm vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) nhận đầu vào là danh 
dách kề chứa các cặp pair<int, int> biểu diễn đỉnh kề và trọng số tương ứng của cạnh. 
Đồ thị gồm n đỉnh được đánh số từ 0 tới n-1. Hàm cần trả vector<int> chứa n phần tử lần lượt là khoảng cách 
đường đi ngắn nhất từ đỉnh 0 tới các đỉnh 0, 1, 2, ..., n-1
*/
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {    //adj[u] : danh sach dinh ke voi dinh u
    /*****************
    Vu Van Hao 20215572
    *****************/
    //mang luu do dai duong di tu dinhh 0  den cac dinh khac 
    vector<int> distance(adj.size(), 1e9); //ban dau do dai duong di la infinitive
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;   //greater mac dinh se so sanh gia tri cua first trong hai pair
    distance[0]= 0;
    Q.push({0, 0});
    while(!Q.empty()){
        pair<int, int> top = Q.top();   //lay ra dinh co do dai duong di nho nhat trong cac dinh chua tham
        Q.pop();    
        int u = top.second;    //u la dinh dang set
        int du = top.first;     //du la do dai duong di tu dinh 0 -> u hien tai
        if(du > distance[u])   continue;    //neu distance[u] nho hon co nghia no co duong di ngan hon tu dinh khac va duoc scap nhat roi
        for(pair<int, int> adj_u : adj[u]){     //xet cac dinh ke voi dinh u
            //adj_u la dinh ke voi dinh u dang xet
            int v = adj_u.first;   //v dinh ke voi u 
            int w = adj_u.second;   //trong so canh tu u->v
            //cap nhhat lai do dai duong di toi v
           if(distance[v] > (du + w)){  //neu duong di den v tu u nho hon thi update duong toi v di tu u
                distance[v] =  du + w;
                Q.push({distance[v], v});   //push v vao hang doi de xet cac lai v sau do
           }
        }
    }
    return distance;    //tra ve mang do dai duong di toi cac dinh tu dinh 0
}

int main() {
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}
//Vu Van Hao 20215572