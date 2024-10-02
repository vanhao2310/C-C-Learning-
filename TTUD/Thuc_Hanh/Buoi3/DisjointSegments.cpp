#include <bits/stdc++.h>
using namespace std;

int max_end;
int n;
pair<int, int> segments[100000];
int res;

void input(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> segments[i].first >> segments[i].second;
    }

    //sap xep theo diem ket thuc som nhat
    sort(segments, segments+n, [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });
}

void solve(){
    for(int i = 0; i < n; i++){
        if(segments[i].first > max_end){
            res++;
            max_end = segments[i].second;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();

    cout << res;

}
