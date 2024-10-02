#include <bits/stdc++.h>
using namespace std;

#define MAX_N 40

int n, load;
int d[MAX_N][MAX_N];
int x[MAX_N];
bool visited[MAX_N];
int best = INT_MAX;
int current = 0;
int current_load = 0;
int cmin = INT_MAX;

void input() {
    cin >> n >> load;
    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            cin >> d[i][j];
            if (d[i][j] != 0)
                cmin = min(cmin, d[i][j]);
        }
    }
}

bool check(int v) {
    if (visited[v])
        return false;

    if (v > n) {
        //diem xuong
        //kiem tra xem nguoi do da len chua
        if (!visited[v-n])
            return false;
    } else {
        //diem len
        if (current_load + 1 > load)
            return false;
    }

    return true;

}

void Try(int k) {
    for (int i = 1; i <= 2*n; i++) {
        if (check(i)) {
            x[k] = i;
            visited[i] = true;
            current += d[x[k-1]][i];
            if (i > n) {
                    //diem xuong giam so nguoi di
                current_load -= 1;
            } else {
                //diem len tang so nguoi len
                current_load += 1;
            }
            if (k == 2*n) {
                //cap nhat best
                best = min(best, current + d[i][0]);
            } else {
                //kiem tra dieu kien cat nhanh
                if (current + cmin * (2 * n + 1 - k) < best)
                    Try(k+1);
            }
            //unmark for backtrack
            visited[i] = false;
            current -= d[x[k-1]][i];
            if (i > n) {
                    //diem xuong giam so nguoi di
                current_load += 1;
            } else {
                //diem len tang so nguoi len
                current_load -= 1;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    Try(1);

    cout << best;

    return 0;
}
