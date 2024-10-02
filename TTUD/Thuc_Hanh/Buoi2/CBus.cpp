#include<bits/stdc++.h>
using namespace std;

int n, K;
int f;  //chi phi hien tai
int load; //so luong khach tren xe hien tai
int best = 1e9; //loi giai toi uu nhat
int cmin = 1e9; //chi phi nho nhat giua 2 diem
int x[32];  //x[i] diem tham lan thu i
bool visited[32];   //danh dau da tham hay chua
int c[32][32];  //ma tran chi phi

void updateBest(){
    if((f + c[x[2*n]][0]) < best)
        best = f + c[x[2*n]][0];
}

bool check(int i){
    if(visited[i])
        return false;
    //neu i la diem tra
    if(i > n){
        if(!visited[i-n])
            return false;

    }else if(load+1 > K){
            return false;
    }
    return true;
}

void Try(int k){
    for(int i = 1; i <= 2*n; i++){
        if(check(i)){
            //cap nhat
            x[k] = i;   //danh dau lan thu k di den diem i
            f += c[x[k-1]][x[k]];  //cap nhat chi phi
            visited[i] = true;  //danh dau diem i da di

            if(i <= n){  //neu la diem don khach thi tang load len 1
                load++;
            }else{    //diem tra khach thi giam di 1
                load--;
            }

            if(k == 2*n){
                updateBest();
            }else{
                if((f + cmin*(2*n-k+1)) < best)
                    Try(k+1);
            }

            //undo to backtrack
            if(i <= n){
                load--;
            }else{
                load++;
            }
            f -= c[x[k-1]][x[k]];
            visited[i] = false;
        }
    }
}

int main(){
    scanf("%d", &n);
    scanf("%d", &K);
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++){
            scanf("%d", &c[i][j]);
            if(c[i][j] != 0)
                cmin = min(cmin, c[i][j]);
        }
     }

    Try(1);
    printf("%d", best);
    return 0;
}
