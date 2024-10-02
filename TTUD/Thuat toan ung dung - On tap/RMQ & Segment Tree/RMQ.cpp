/*
Cho dãy a0, a1, …, aN-1. Cho số nguyên dương K, ta cần thực hiện K truy vấn,
mỗi truy vấn dạng RMQ(i, j) trả về chỉ số của phần tử nhỏ nhất của dãy ai, ai+1, . . ., aj
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000008

int n, a[MAX_N], q, M[20][MAX_N];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;
}

void preprocess() {
    for (int i = 0; i < n; i++) {
        M[0][i] = i;
    }

    for (int i = 1; (1 << i) <= n; i++) {
        for (int j = 0; (j + (1 << i ) - 1 < n); j++) {
            if (a[M[i-1][j]] < a[M[i-1][j + (1 << (i-1))]])
                M[i][j] = M[i-1][j];
            else
                M[i][j] = M[i-1][j + (1<<(i-1))];
        }
    }
}

int query(int i, int j) {
    int k = log2(j - i + 1);
    return a[M[k][i]] < a[M[k][j - (1<<k) + 1]] ? a[M[k][i]] : a[M[k][j - (1<<k) + 1]];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    preprocess();
    int i, j, sum = 0;
    while(q--) {
        cin >> i >> j;
        sum += query(i, j);
    }
    cout << sum;
    return 0;
}
