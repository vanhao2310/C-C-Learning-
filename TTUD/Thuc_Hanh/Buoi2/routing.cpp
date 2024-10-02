#include<bits/stdc++.h>
using namespace std;

int n, K, Q;
int d[32];  //so package ma diem i can  (toi da co 12 diem)
int c[32][32];  //ma tran chi phi
int cmin = 1e9;
bool visited[32];
int x[32];  //diem giao tiep theo cua diem i
int y[32];  //diem giao dau tien cua xe thu k (toi da 5 xe)
int load[32]; //trong luong hien tai cua xe thu k
int f;  // tong quang duong hien tai cua tat ca cac xe
int f_min = 1e9; //phuong an tot nhat
int segments;   //so chang da di duoc
int nbR;    //so xe duoc lap lo trinh

void input(){
    cin >> n >> K >> Q;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cin >> c[i][j];
            if(c[i][j] != 0)
                cmin = min(c[i][j], cmin);
        }
    }
}

bool check_X(int v, int k){
    if(v>0 && visited[v])
        return false;
    if(load[k] + d[v] > Q)
        return false;

    return true;
}

//thu diem tiep theo cua diem s cho xe k
void Try_X(int s, int k){

    //s = 0 quay ve diem xuat phat thi duyet cho xe k+1
    if(s == 0){
        if(k < K)   Try_X(y[k+1], k+1);

        //return tranh lap duong di cho xe khong dc giao viec
        return;
    }

    //duyet cac dinh tiep theo cho s
    for(int v = 0; v <= n; v++){
        if(check_X(v, k)){
            //danh giau va cap nhat chi phi
            x[s] = v;
            visited[v] = true;
            load[k] += d[v];
            f += c[s][v];
            segments++;

            if(v > 0) {  //neu chua phai quay ve diem xuat phat,

                //kiem tra dieu kien cat nhanh
                if(f + cmin*(n + nbR - segments) < f_min)
                    //tim diem tiep theo cho diem v
                    Try_X(v, k);

            }else {  //v = 0 co nghia xe thu k quay ve 0

                //Neu da xay dung du het cho K xe
                if(k == K) {
                    //di du tat ca cac chang duong de giao cho tat ca cac diem
                    if(segments == n + nbR)
                        //updateBest
                        f_min = min(f_min, f);

                }else { //chua lap lich cho du K xe

                    //kiem tra dieu kien cat nhanh
                    if(f + cmin*(n + nbR - segments) < f_min)
                        //lap lich cho xe k+1, bat dau tu diem y[k+1]
                        Try_X(y[k+1], k+1);
                }
            }

            //redo for backtrack
            visited[v] = false;
            load[k] -= d[v];
            f -= c[s][v];
            segments--;
        }
    }
}

//thu diem dau la v cho xe k
bool check_Y(int v, int k){
    if(v == 0)
        return true;
    //kiem tra diem v co duoc tham boi xe nao chua
    if(visited[v])
        return false;
    //kiem tra trong luong
    if(load[k] + d[v] > Q)
        return false;

    return true;
}

//thu cac diem den dau tien cua xe thu k
void Try_Y(int k){
    int s = 0;
    if(y[k-1] > 0)
        s = y[k-1] + 1;
    for(int v = s; v <= n; v++){
        if(check_Y(v, k)) {
            y[k] = v;
            if(v > 0)   segments++;
            visited[v] = true;
            load[k] += d[v];
            f += c[0][v];

            if(k < K)
                Try_Y(k+1);
            else{
                //cac xe da co diem xuat phat dau tien
                //=> lap duong di cho cac xe
                nbR = segments;
                Try_X(y[1], 1);
            }
            //redo for backtrack
            if(v > 0)   segments--;
            visited[v] = false;
            load[k] -= d[v];
            f -= c[0][v];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    y[0] = 0;
    Try_Y(1);
    cout << f_min;

    return 0;
}

