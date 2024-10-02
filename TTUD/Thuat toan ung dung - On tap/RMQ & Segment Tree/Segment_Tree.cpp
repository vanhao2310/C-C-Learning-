#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100004

int a[MAX_N];
int n, m;
int maxval[MAX_N*4];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
}

int getMaxFromNode(int id, int L, int R, int i, int j) {
    //(i, j) khong thuco (L, R)
    if (i > R || j < L)
        return -1;
    if (i <= L && j >= R)
        return maxval[id];

    int mid = (L + R) / 2;
    int id_left = 2 * id;
    int id_right = 2 * id + 1;
    int max_left = getMaxFromNode(id_left, L, mid, i, j);
    int max_right = getMaxFromNode(id_right, mid+1, R, i, j);
    return max(max_left, max_right);
}
int getMax(int i, int j) {
    return getMaxFromNode(1, 1, n, i, j);
}

void updateFromNode(int id, int L, int R, int index, int value) {
    if (L > R)
        return;
    if (index < L || index > R)
        return;
    if (L == R) {
        maxval[id] = value;
        return;
    }

    int left_id = 2 * id;
    int right_id = 2*id + 1;
    int mid = (L + R) / 2;
    updateFromNode(left_id, L, mid, index, value);
    updateFromNode(right_id, mid+1, R, index, value);
    maxval[id] = max(maxval[left_id], maxval[right_id]);
}
void update(int index, int value) {
    updateFromNode(1, 1, n, index, value);
}

void buildSegmentTree() {
    for (int i = 1; i <= n; i++) {
        update(i, a[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    buildSegmentTree();
    string cmd;
    while (m--) {
        cin.ignore();
        cin >> cmd;
        if (cmd == "update") {
                int i, value;
            cin >> i >> value;
            a[i] = value;
            update(i, value);
        } else if (cmd == "get-max") {
            int i, j;
            cin >> i >> j;
            cout << getMax(i, j) << "\n";
        }
    }
    return 0;
}
