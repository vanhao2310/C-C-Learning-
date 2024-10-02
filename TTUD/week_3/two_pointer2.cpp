/*
Bàitậpminh họa2.2 (P.02.02.04). Cho dãy số không âm a[1], a[2], . . ., a[n]. Cho trước giá trị Q, hãy tìm dãy
 con (gồm một số phần tử đứng liên tiếp cạnh nhau) dài nhất mà có tổng nhỏ hơn hoặc bằng Q.
*/
#include <bits/stdc++.h>
using namespace  std;

int arr[1000001];
int n, Q;
int res = 0;


int main() {
    scanf("%d%d", &n, &Q);
    for(int i = 0;  i < n; i++){
        scanf("%d", &arr[i]);
    }
    int L = 0, R = 0, S = 0;    //S: tong cac phan tu tu L -> R
    for(; R < n; ++R){
        S += arr[R];
        while(S > Q){
            S -= arr[L];
            ++L;
        }
        res = max(res, R-L+1);
    }

    cout << res;
}
