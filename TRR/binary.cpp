#include<bits/stdc++.h>
using namespace std;

int sum = 0;
int n;
int cnt = 0;
int arr[10000];

void Bit(int k)
{
    for(int i = 0; i <= 1; i++)
    {
        if(arr[k-1] + i < 2)
        {
            arr[k] = i;     
            if(k==n)
                cnt++;
            else Bit(k+1);
        }
    }
}

int main(){
    cin >> n;
    Bit(1);
    cout << cnt;
}