/*
    Problem: Permutation generation
    author: Vu Van Hao 20215572
*/
#include<bits/stdc++.h>

//in ra cac hoan vi
void print(int arr[], int n){
    for(int i = 1; i <= n; i++){
        std::cout << arr[i] << " "; 
    }
    std::cout << std::endl;
}

//cac hoan vi duoc luu trong mang num
void permutation(int k, int n, int num[], std::vector<int> mark){   //vector mark danh dau cac so da xuat hien
    for(int i = 1; i <= n; i++)
    {
        if(!mark[i]){
            num[k] = i;
            mark[i] = 1;
            if(k == n)
                print(num, n);
            else{
                permutation(k+1, n, num, mark);
            }
            mark[i] = 0;
        }
    }
}

int main(){
    int n;
    std::cin >> n;
    int num[n+1];
    std::vector<int> mark(n+1, 0);
    permutation(1, n, num, mark);
    return 0;
}