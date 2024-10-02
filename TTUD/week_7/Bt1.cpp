#include <bits/stdc++.h>
using namespace std;

int n = 10, m = 3;
int arr[] = {2, 5, 8, 10, 13, 15, 17, 19, 22, 23};

int sum = 0;

void sum_arr(){
    for(int i = 0; i < n; i++)
        sum += arr[i];
}

void DC() {

}

int main(){
    sum_arr();
    return 0;

}
