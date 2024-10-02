/*
                           _oo0oo_
                          o8888888o
                          88" . "88
                          (| -_- |)
                          0\  =  /0
                        ___/`---'\___
                      .' \\|     |// '.
                     / \\|||  :  |||// \
                    / _||||| -:- |||||- \
                   |   | \\\  -  /// |   |
                   | \_|  ''\---/''  |_/ |
                   \  .-\__  '-'  ___/-. /
                 ___'. .'  /--.--\  `. .'___
              ."" '<  `.___\_<|>_/___.' >' "".
             | | :  `- \`.;`\ _ /`;.`/ - ` : | |
             \  \ `_.   \_ __\ /__ _/   .-` /  /
         =====`-.____`.___ \_____/___.-`___.-'=====
                           `=---='

        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                Phật phù hộ, không có BUG
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include<bits/stdc++.h>
using namespace std;

int N, T;   //T: number testcase, N: number elements
int c; //number elements of subset
int arr[1000000];


void input() {
        cin >> N >> c;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        //sap xep lai mang
        sort(arr + 1, arr + N + 1);
}

bool check(int distance) {
    int num = 1;
    int pre = arr[1];
    for (int i = 2; i <= N; i++) {
        if (arr[i] - pre >= distance) {
            num++;
            pre = arr[i];
            if (num >= c)
                return true;
        }
    }
    return false;
}

int solve() {
    int l = 0;
    int r = (arr[N] - arr[1]) / (c - 2);
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++) {
        input();
        cout << solve() << endl;
    }
    return 0;
}
