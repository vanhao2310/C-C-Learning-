#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000


int a[MAX_N], f[MAX_N]; //f[i]: day con tang do dai lon nhat ket thuc tai a[i]
int n;
int res = INT_MIN;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                f[i] = max(f[i], 1 + f[j]);
            }
        }
    }
    int pos;
    for (int i = 0; i < n; i++) {
        if (f[i] > res) {
            res = f[i];
            pos = i;
        }
    }
    cout << res << endl;

    stack<int> s;
    s.push(a[pos]);

    for (int k = 0; k < res; k++) {
        for (int i = pos - 1; i >= 0; i--) {
            if (a[i] < a[pos] && f[i] == f[pos] - 1) {
                s.push(a[i]);
                pos = i;
                break;
            }
        }
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

}

int main() {
    input();
    solve();
}
