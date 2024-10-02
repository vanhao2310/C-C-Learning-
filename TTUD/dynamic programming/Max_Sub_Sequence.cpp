#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000


int a[MAX_N], f[MAX_N];
int n;
int max_sum = INT_MIN;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        f[i] = max(a[i], f[i-1] + a[i]);
    }

    int pos;
    for (int i = 0; i < n; i++) {
        if (f[i] > max_sum) {
           max_sum = f[i];
           pos = i;
        }
    }
    cout << max_sum << endl;
    int sum = max_sum;
    stack<int> s;
    while (f[pos] == sum) {
        s.push(a[pos]);
        sum -= a[pos];
        pos--;
    }
    int tmp;
    while (!s.empty()) {
        tmp = s.top();
        s.pop();
        cout << tmp << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();
}
