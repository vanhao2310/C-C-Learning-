/*
    Problem: Compute C_k_n
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
const long long M = 1e9 + 7;

long long compute(int k, int n, long long **C){
    if(C[n][k] != -1)
        return C[n][k];
    else if(k == n || k == 0)
        return 1;
    else if (k == 1)
        return n;
    else {    
        long long result = (compute(k, n-1, C)%M + compute(k-1, n-1, C)%M) % M;
        C[n][k] = result;
        return result;    
    }
}

int main(){
    int k, n;
    std::cin >> k >> n;

    //cap phat dong mang co cac phan tu = -1
    long long **C = new long long*[n+1];
    for(int i = 0; i <= n; i++){
        C[i] = new long long[k+1];
        for(int j = 0; j <= k; j++)
            C[i][j] = -1;
    }

    std::cout << compute(k, n, C);
    
    //giai phong bo nho
    for(int i = 0; i <= n; i++){
        delete[] C[i];
    }
    delete[] C;
    return 0;
}