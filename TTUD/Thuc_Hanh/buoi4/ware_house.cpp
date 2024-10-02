#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1004
#define MAX_T 101

int N, a[MAX_N], t[MAX_N], T, D;
int f[MAX_N][MAX_T];
                    //f[i][j]: luong ham lon nhat lay duoc o diem i voi thoi gian con lai j
int res = INT_MIN;

void input() {
    cin >> N >> T >> D;
    for (int i = 1; i <= N ; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> t[i];
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {  //xet lan luot cac diem tu 1 -> N
        for (int j = 1; j <= T; j++) {  //xet thoi gian tang dan tu 1 -> T voi moi diem
            f[i][j] = a[i];
            if (j < t[i]) {
                f[i][j] = 0;
                continue;
            } else {
                //xem xet di toi diem i tu cac diem nho hon i cach nhau toi da D
                for (int k = max(1, i-D); k < i; k++) {
                    f[i][j] = max(f[i][j], f[k][j - t[i]] + a[i]);
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        res = max(res, f[i][T]);
    }
    cout << res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();
    return 0;
}
