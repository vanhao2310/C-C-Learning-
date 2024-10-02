#include<bits/stdc++.h>
using namespace std;

int H, W, n;
int h[10], w[10];
int mark[10][10];
int x[10], y[10], o[10];
int countSolution = 0;

//vo : co xoay 90 do khong
//vx toa do x
//vy toa do y
//k : mieng thu k can cat
bool check(int vo, int vx, int vy, int k){
    int hk, wk;
    if(!vo){
        //khong xoay 90 do
        hk = h[k];
        wk = w[k];
    }else{
        hk = w[k];
        wk = h[k];
    }

    if(vx + wk > W)
        return false;
    if(vy + hk > H)
        return false;
    for(int i = vx; i < (vx + wk); i++){
        for(int j = vy; j < (vy + hk); j++)
            if(mark[i][j])
                return false;
    }
    return true;
}

void doMark(int vo, int vx, int vy, int k, bool mark_value){
    int wk, hk;
    if(!vo){
        hk = h[k];
        wk = w[k];
    }else{
        hk = w[k];
        wk = h[k];
    }
    for(int i = vx; i < vx+wk; i++){
        for(int j = vy; j < vy+hk; j++){
            mark[i][j] = mark_value;
        }
    }
}


void Try(int k){
    for(int vo = 0; vo <= 1; vo++){
        int hk, wk;
        if(!vo){
            //khong xoay 90
            hk = h[k];
            wk = w[k];
        }else{
            hk = w[k];
            wk = h[k];
        }
        for(int vx = 0; vx <= W - wk; vx++){
            for(int vy = 0; vy <= H-hk; vy++){
                if(check(vo, vx, vy, k)){
                    x[k] = vx;
                    y[k] = vy;
                    o[k] = vo;
                    doMark(vo, vx, vy, k, true);
                    if(k == n){
                        countSolution++;
                    }else
                        Try(k+1);

                    //unMark
                    doMark(vo, vx, vy, k, false);

                }
            }
        }
    }
}

void input(){
    cin >> H >> W;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i];
        cin >> w[i];
    }

}

int main(){
    input();
    Try(0);
    if(countSolution)
        cout << 1;
    else
        cout << 0;

}
