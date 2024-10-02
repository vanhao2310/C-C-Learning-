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
    int n, k, count = 0;
    std::cin >> n >> k;
    int *arr = new int[n];
    input_array(arr, n);
    for(int i = 0;  i < n-3; i++){
        if((arr[i] + arr[i+1] + arr[i+2]) % 2 == 0 )
            count++;
    }
    std::cout << count << std::endl;

    delete[] arr;
    return 0;
}