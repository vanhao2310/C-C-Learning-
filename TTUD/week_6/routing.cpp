#include<bits/stdc++.h>
using namespace std;


int n, K, Q;
int c[32][32];
int d[32];  //so luong package diem thu i can
bool visitted[32];
int load[32];
int f;
int c_min = 1e9;
int f_min = 1e9;
int x[32];
int y[32];
int segment, nbR;

void input(){
    cin >> n >> K >> Q;
    for(int i = 1; i <= n; i++)
        cin >> d[i];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cin >> c[i][j];
            if(c[i][j] != 0)
                c_min = min(c_min, c[i][j]);
        }
    }
}

bool check_X(int v, int k){
    if(v > 0 && visitted[v])
        return false;
    if(load[k] + d[v] > Q)
        return false;

    return true;

}

//thu tim diem tiep theo cua diem v cho xe k
void Try_X(int s, int k){
    if(s == 0){
        if(k < K)
            //lap lich cho xe tiep theo
            Try_X(y[k+1], k+1);

        return;
    }

    for(int v = 0; v <= n; v++){
        if(check_X(v, k)){
            x[s] = v;
            visitted[v] = true;
            segment++;
            load[k] += d[v];
            f += c[s][v];

            if(v > 0){  //chua phai quay ve kho
                //-> tim diem tiep theo cho xe k
                if(f + c_min*(n+nbR - segment) < f_min)
                    Try_X(v, k);
            }else{
                //quay ve kho -> lap lich cho xe tiep
                if(k < K){
                    //neu chua lap lich cho het xe
                    if(f + c_min*(n+nbR - segment) < f_min)
                        Try_X(y[k+1], k+1);
                } else {
                    //neu da laplich cho tat ca cac xe
                    //kiem tra da giao het chua thi cap nhat ki luc
                    if(segment == n+nbR)
                        f_min = min(f_min, f);
                }
            }

            //unmark for backtrack
            visitted[v] = false;
            f -= c[s][v];
            load[k] -= d[v];
            segment--;
        }
    }
}


bool check_Y(int v, int k){
    if(v == 0)
        return true;
    if(visitted[v])
        return false;
    if(load[k] + d[v] > Q)
        return false;

    return true;

}

//thu tim diem xuat phat cho xe thu k
void Try_Y(int k){
    int s = 0;
    if(y[k-1] > 0)
        s = y[k-1] + 1;
    for(int v = s; v <= n; v++){
        if(check_Y(v, k)){
            y[k] = v;
            visitted[v] = true;
            load[k] += d[v];
            f+= c[0][v];
            if(v > 0)
                segment++;

            if(k < K)
                Try_Y(k+1);
            else{
                nbR = segment;
                Try_X(y[1], 1);
            }

            //unmark for backtrack
            visitted[v] = false;
            load[k] -= d[v];
            f -= c[0][v];
            if(v > 0)
                segment--;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    Try_Y(1);

    cout << f_min;


    return 0;
}
