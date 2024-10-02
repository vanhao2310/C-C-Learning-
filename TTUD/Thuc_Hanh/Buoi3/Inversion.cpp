#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int n;
int a[1000004];
long long res;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void merge_(int left, int mid, int right) {
    int subLeft = mid - left + 1;
    int subRight = right - mid;

    int *subArrLeft = new int[subLeft];
    int *subArrRight = new int[subRight];

    for(int i = 0 ; i < subLeft; i++){
        subArrLeft[i] = a[left+i];
    }

    for(int i = 0; i < subRight; i++){
        subArrRight[i] = a[mid + 1 + i];
    }

    //merge
    int indexLeft = 0, indexRight = 0, indexArray = 0;

    while(indexLeft < subLeft && indexRight < subRight) {

        //inversion
        if(subArrLeft[indexLeft] > subArrRight[indexRight]){
            a[left + indexArray] = subArrRight[indexRight];
            indexRight++;
            indexArray++;
            res += subLeft - indexLeft;
        } else {
            a[left+indexArray] = subArrLeft[indexLeft];
            indexLeft++;
            indexArray++;
        }
    }

    while(indexLeft < subLeft){
        a[left + indexArray] = subArrLeft[indexLeft];
        indexLeft++;
        indexArray++;
    }

    while(indexRight < subRight){
        a[left + indexArray] = subArrRight[indexRight];
        indexRight++;
        indexArray++;
    }

    res = res % M;

    delete []subArrLeft;
    delete []subArrRight;
}

void merge_sort(int left, int right){
    if(left >= right)
        return;
    int mid = (left + right) / 2;

    //sap xep day con ben tran
    merge_sort(left, mid);
    //sap xep day con ben phai
    merge_sort(mid + 1, right);

    //gop hai day con
    merge_(left, mid, right);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    merge_sort(0, n-1);

    cout << res;


    return 0;
}
