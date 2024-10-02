/*
Bài tập minh họa(P.02.02.02). Cho mảng 2 chiều a[1..n, 1..m]. Ta cần thực hiện Q truy vấn, mỗi truy vấn có
 dạng được đặc trưng bởi bộ chỉ số (a, b, c, d) và được định nghĩa như sau:
*/
/*
ý tưởng:
S[i;j] = tong cac phan tu tu a[0;o] den a[i;j]
*/
#include<bits/stdc++.h>
using namespace std;
int A[1001][1001], S[1001][1001];
int row, column;
int q;
int a, b, c, d;


int main(){
    scanf("%d%d", &row,  &column);
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= column; j++){
            scanf("%d", &A[i][j]);
        }
    }
    scanf("%d", &q);
    //preprocess
    for(int i = 0; i <= row; i++)
        S[i][0] = 0;
    for(int j = 0; j <= column; j++)
        S[0][j]= 0;
    for(int i = 1; i<= row; i++){
        for(int j = 1; j <= column; j++){
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j];
        }
    }
    for(int i = 0 ; i < q ; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        cout << (S[c][d] - S[a-1][d] - S[c][b-1]+ S[a-1][b-1]) << endl;
    }
}
