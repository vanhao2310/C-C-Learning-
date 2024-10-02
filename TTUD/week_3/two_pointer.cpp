/*Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M.
Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.*/
#include<bits/stdc++.h>
using namespace std;

int arr[1000001];
int n, M, res = 0;

/*
ý tưởng là sắp xếp các phần tử của mảng
cho left bắt đầu từ đầu mảng right cuối mảng
lặp cho đếns khi left và righr gặp nhau
neu a[left] + a[right] > Q thi giam rigth di 1
                       < Q thi tang left  len 1
                       = Q thi res += 1;
*/

int main(){
    scanf("%d%d", &n, &M);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    //sap xep mang
    sort(arr, arr + n);
    int left = 0, right = n-1;
    while(left < right){
        if(arr[left]  + arr[right] == M){
            ++res;
            ++left;
        }else if(arr[left] + arr[right] < M)
            ++left;
        else
            right--;
    }
    cout << res << endl;
    return 0;
}
