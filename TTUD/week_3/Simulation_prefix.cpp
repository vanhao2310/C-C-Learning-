/*
Bàitậpminh họa(P.02.02.01). Cho dãy số a1, a2, …, an. Thực hiện Q truy vấn, mỗi truy vấn được đặc trưng bởi
 cặp chỉ số (i, j) trong đó ta cần tính tổng ai + ai+1 + . . . + aj.
*/
//mảng cộng dồn: xử lý trước đến khi truy vấn chỉ lấy ra không cần chạy for(i->j)
//Mảng S với S[k] là tổng các phần tử từ A[0]->A[k]
//=> Tổng các phần từ từ A[i] -> A[j] = S[j] - S[i-1]
#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[100001], S[100001];
    int n, tmp, Q, a1, a2;
    cin >> n;
    cin >> A[1];
    S[1] = A[1];
    for(int i = 2; i <= n; i++){
        cin >> A[i];
        S[i] = S[i-1] + A[i];
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> a1 >> a2;
        cout << S[a2] - S[a1-1] << endl;
    }
}
