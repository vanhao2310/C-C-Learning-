#include<bits/stdc++.h>
using namespace std;

int n, M, a[100000], x[100000];
int res = 0;

//tinh tong aj*xj j 0->i-1
int sum(int i){
    int s = 0;
    for(int j = 0; j < i; j++)
        s += a[j]*x[j];
    return s;
}

void Try(int i){    //chon so thu i
    int si = sum(i);
    int maxXi = (M-si)/a[i];
    for(int j = 1; j <= maxXi ; j++){
        x[i] = j;
        if(i == (n-1)){
            if((si + a[i]*x[i]) == M)
                res++;
        }else
            Try(i+1);
    }
}

int main() {
    //input
    cin >> n >> M;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Try(0);

    cout << res;
    return 0;
}
