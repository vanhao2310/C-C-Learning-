#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100004

int n, t, c, res;
int a[MAX_N];

void input() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

//kiem tra voi distance nay co thoa man du c phan tu trong tap hay khong
bool check(int distance) {
    int num = 1, last = a[0];
    for (int i = 2; i < n; i++) {
        if (a[i] - last >= distance) {
            num++;
            last = a[i];
            if (num >= c)
                return true;
        }
    }
    return false;
}

void solve() {
    res = INT_MIN;
    int l = 0, r = (a[n-1] - a[0]) / (c-2);
    while (l <= r) {
        //chat nhi phan thu distance xem co thoa man khong
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--) {
        input();
        //sap xep cac phan  theo thu tu tang dan
        sort(a, a + n);
        solve();
        cout << res << "\n";
    }

    return 0;
}
