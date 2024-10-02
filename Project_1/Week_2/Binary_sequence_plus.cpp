/*
    Problem: Binary sequences generation without consecutive 11
    author: Vu Van Hao 20215572
*/
#include<bits/stdc++.h>

//in ra day nhi phan tim duoc
void print(int arr[], int n){
    for(int i = 1; i <= n; i++)
        std::cout << arr[i];
    std::cout << std::endl;
}

//thuat toan quay lui sinh day nhi phan
void bin_generation(int k, int n, int bin[]){   //cac bit dc luu vao mang bin[]
    for(int i =0; i <= 1; i++){
        if(bin[k-1] + i < 2){
            bin[k] = i;
            if(k == n)
                print(bin, n);
            else    
                bin_generation(k+1, n, bin);
        }   
    }
}

int main(){
    int n;
    std::cin >> n;
    int bin[n];
    bin[0] = 0;
    bin_generation(1, n, bin);
    return 0;
}