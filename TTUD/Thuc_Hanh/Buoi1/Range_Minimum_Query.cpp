#include<bits/stdc++.h>
using namespace std;

#define p2(i) (1<<(i)) //2^i

int n, m, a, b, Q = 0; //n: so phan tu cua mang
                //m: so luong query
                //a, b diem dau diem cuoi cua moi quety
                //Q: sum
int arr[1000001];
int M[20][1000001];/*M[i,j]: Chi so phan tu nho nhat trong doan tu phan tu arr[j] do dai 2^i phan tu*/

void preprocessing(){
    for(int i = 1; (1<<i) <= n; i++){
        for(int j = 0; j+p2(i)-1 < n; j++){
            if(arr[M[i-1][j]] < arr[M[i-1][j+p2(i-1)]]){
                M[i][j] = M[i-1][j];
            }else{
                M[i][j] = M[i-1][j+p2(i-1)];
            }
        }
    }
}

//get minimum value from i_start to i_end  of array arr
int rmq(int &i_start, int &i_end){
    int k = log2(i_end - i_start + 1);
    return arr[M[k][i_start]] <= arr[M[k][i_end - p2(k) + 1]] ? arr[M[k][i_start]] : arr[M[k][i_end - p2(k) + 1]];
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        scanf("%d", &arr[i]);
        M[0][i] = i;
    }

    preprocessing();

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        Q += rmq(a, b);
    }

    cout << Q << endl;
    return 0;
}
