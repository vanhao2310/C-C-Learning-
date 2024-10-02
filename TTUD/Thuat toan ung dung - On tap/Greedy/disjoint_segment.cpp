/*
Description
Given a set of segments X = {(a
1
, b
1
), . . . , (a
n
, b
n
)} in which ai < bi are coordinates of the segment i on a line, i = 1, …, n.  Find a subset of X having largest cardinality in which no two segments of the subset intersect
Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line i+1 (i= 1,...,n): contains ai and bi (0 <= a
i
 <= b
i
<= 1000000)
Output
Number of segments in the solution found.
Example
Input
6
0 10
3 7
6 14
9 11
12 15
17 19
*/

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define MAX_N 100004

pii segments[MAX_N];
int n, cnt;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    //preprocess
    //sap xep cac doan theo tu thu tang dan diem ket thuc
    sort(segments, segments + n, [](pii a, pii b) {
            return a.second < b.second;
        });
}

//greedy
void solve() {
    int last = segments[0].second;
    cnt += 1;
    for (int i = 1; i < n; i++) {
        if (segments[i].first > last) {
            last = segments[i].second;
            cnt++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();
    cout << cnt;
}
