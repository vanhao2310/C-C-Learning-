#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000004

int a[MAX_N], n, Q;
int max_length = INT_MIN;

void input() {
    cin >> n >> Q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solve() {
    int left = 0, right = 0, sum = 0;
    for (; right < n; right++) {
        sum += a[right];

        while (sum > Q) {
            sum -= a[left];
            left++;
        }

        max_length = max(max_length, right - left + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();
    cout << max_length;
}
