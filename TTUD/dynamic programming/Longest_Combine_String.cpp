#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int f[MAX_N][MAX_N];    //f[i][j]: do dai xau con chung dai nhat cua i ki tu dau cua X va j ki tu dau cau Y
int res = INT_MIN;
 string X, Y;

int main() {

    cin >> X >> Y;
    int lengthX = X.length();
    int lengthY = Y.length();

    for (int i = 1; i <= lengthX; i++) {
        for (int j = 1; j <= lengthY; j++) {
            if (X[i - 1] == Y[j - 1]) {
                f[i][j] = 1 + f[i-1][j-1];
            } else {
                f[i][j] = max(f[i-1][j], f[i][j-1]);
            }
        }
    }
    cout << f[lengthX][lengthY] << endl;
    res = f[lengthX][lengthY];
    stack<char> s;
    int i = lengthX, j = lengthY;
    while (res > 0) {
        if (X[i-1] == Y[j-1] && f[i][j] == f[i-1][j-1] + 1) {
            s.push(X[i-1]);
            i--;
            j--;
            res--;
            continue;
        } else if (f[i][j] == f[i-1][j]) {
            i--;
            continue;
        } else if (f[i][j] == f[i][j-1]) {
            j--;
            continue;
        }
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
