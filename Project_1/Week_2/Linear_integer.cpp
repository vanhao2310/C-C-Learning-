#include<bits/stdc++.h>

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

bool check_sum(int arr[], int n, int sum){
    int tmp = 0;
    for(int i = 0; i < n; i++){
        tmp += arr[i];
    }
    if(tmp == sum)  return true;
    else return false;
}

void Try(int arr[], int n, int k, int sum){
    for(int i = 1; i <= 9; i++){
        arr[k] = i;
        if(k == n-1){
            if(check_sum(arr, n, sum)) 
                print(arr, n);
        }else{
            Try(arr, n, k+1, sum);
        }
    }
}

int main(){
    int n, m;
    std::cin >> n >> m;
    int arr[n];
    Try(arr, n, 0, m);
    return 0;
}