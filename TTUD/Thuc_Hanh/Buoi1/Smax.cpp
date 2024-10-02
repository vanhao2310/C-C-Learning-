#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1000][1000];
int h[1000][1000];
int smax = -1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0;  j < m; j++){
            cin >> a[i][j];
        }
    }

    //proproccessor
    //h[i][j] tong so bit 1 lien tiep theo hang doc ket thuc tai h[i][j]
    for(int j = 0; j < m; j++){
        h[0][j] = a[0][j];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0)
                h[i][j] = 0;
            else
                h[i][j] = h[i-1][j] + 1;
        }
    }

    //solve
    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < m; j++) {
            if(a[i][j]==0)
                continue;

            int left  = j, right = j;
            //tim vi tri xa nhat ben trai co chieu cao >= chieu cao h[i][j]
            while((left-1)>=0 && h[i][left - 1] >= h[i][j])
                left--;
            //tim vi tri xa ben phai co chieu cao >= h[i][j]
            while((right+1)<m && h[i][right + 1] >= h[i][j])
                right++;
            int width = right - left + 1;   //chieu rong hcn
            int height = h[i][j];
            smax = max(smax, width*height);
        }
    }
    cout <<smax;

    return 0;
}
