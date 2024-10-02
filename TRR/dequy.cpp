#include<iostream>
using namespace std;

int dequy(int n){
    int a = 3;
    int b = 7;
    int sum;
    for(int i = 3; i <= n;i++){
        sum = a+2*b;
        a = b;
        b = sum;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    cout << dequy(n);
}