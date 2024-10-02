/*
    Problem: k-Subsequence even
    author: Vu Van Hao - 20215572
*/

#include<bits/stdc++.h>

void input_array(int arr[], int n){
    for(int i = 0; i < n; i++)
        std::cin >> arr[i];
}


int main(){
    int n, k, count;
    std::cin >> n >> k;
    int *arr = new int[n];
    input_array(arr, n);
    int sum_sub = 0;
    
    //tong k phan tu dau tien
    for(int i = 0; i < k; i++)
        sum_sub += arr[i];
    if(sum_sub % 2 == 0)
        count = 1;
    else 
        count = 0;
    
    //dich chuyen o sang phai dan 
    for(int i = 0;i < n-k; i++){
        sum_sub = sum_sub - arr[i] + arr[i+k];
        if(sum_sub % 2 == 0)
            count++;
    }

    std::cout << count << std::endl;

    delete[] arr;
    return 0;
}