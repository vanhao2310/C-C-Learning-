#include<bits/stdc++.h>
using namespace std;

bool mark[10][10];
int H, W, n;
int wi[10], hi[10];
int x[10], y[10], o[10];

bool check(int vo, int vx, int vy, int k){
    int wk, hk;
    if(!vo){
        wk = w[k];
        hk = h[k];
    }else{
        wk = h[k];
        hk = w[k];
    }

    if((vx+wk) > W || (vy+hk) > H)
            return false;

    for(int i = vx; i <= (vx+wk-1); i++){
        for(int j = vy, j <= (vy+hk-1); j++){
            if(mark[i][j])
                return false;
        }
    }
    return true;
}

void doMark(int vo, int )

void Try(int k){
    for(int vo = 0 ; vo <= 1; vo++){
        int wk, hk;
        if(vo==0){
            wk = w[k];
            hk = h[k];
        }else{
            wk = h[k];
            hk = w[k];
        }
        for(int vx = 0; vx <= (W-wk); vx++){
            for(int vy = 0; vy <= (H-hk); vy++){
                if(check(vo, vx, vy, k)){
                    x[k] = vx; y[k] = vy; o[k] = vo;
                }
            }
        }
    }
}

int main() {

}
