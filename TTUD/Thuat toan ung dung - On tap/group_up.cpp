#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000], group[1000];
int res = 0;
int time_i;

void input() {
    cin >> n;
    for (int i = 0; i  < n; i++) {
        cin >> a[i];
        group[i] = a[i];
    }
}

void solve() {
    int cnt = n;
    while (cnt != 1) {
            time_i = 0;
        int a = cnt / 2;
        int b = cnt % 2;
        int i = 0;
        for (; i < a; i++) {
            group[i] = group[2*i] + group[2*i + 1];
            time_i = max(time_i, group[i]);
        }
        if(!b)
            group[i] = group[cnt];
        res += time_i;
        cnt = a + b;
    }
    cout << res;
}

int main() {
    input();
    solve();
}
