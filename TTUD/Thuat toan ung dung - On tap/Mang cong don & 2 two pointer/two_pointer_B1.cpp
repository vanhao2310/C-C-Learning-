#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000004

int n, a[MAX_N];
int m, res;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //sap xep cac phan tu
    sort(a, a + n);
}

void solve() {
    int left = 0, right = n-1;
    while (left < right) {
        if (a[left] + a[right] == m) {
            res++;
            left--;
            right--;
        } else if (a[left] + a[right] < m) {
            left++;
        } else {
            right++;
        }
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}
