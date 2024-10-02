#include <bits/stdc++.h>
using namespace std;

string X, Y;
int res = INT_MIN;
int f[1000][1000];

void input() {
    cin >> X >> Y;
}

void solve() {
    for (int i = 1; i < X.length(); i++) {
        for (int j = 1; j < Y.length(); j++) {
            if (X[i] == Y[j]) {
                f[i][j] = max(f[i][j], 1 + f[i-1][j-1]);
            } else {
                f[i][j] = max(f[i][j], f[i-1][j]);
                f[i][j] = max(f[i][j], f[i][j-1]);
            }
        }
    }
}

void trace() {
    cout << f[X.length()-1][Y.length()-1];
}

int main() {
    input();
    solve();
    trace();
}
