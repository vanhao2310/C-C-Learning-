#include<stdio.h>
#include<stdlib.h>

void nhapmang(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        // printf("Nhap a[%d] = ", i);    
        // scanf("%d", &arr[i]);
        arr[i] = -9 + rand()%20;
    }
}

void xuatmang(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int sum(int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int count(int arr[], int n)
{
    int dem = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] == 0)
            dem++;
    return dem;
}

int findzezo(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        if(arr[i] == 0)     return i;
    return -1;
}

void Try(int k, int m, int arr[], int n)
{
    int count = 0;
    int x = findzezo(arr, n);
    for(int i = -9; i <= 9; i++)
    {
        if(i == 0) continue;
        arr[x] = i;
        if(k == m)
        {
            if(sum(arr, n) == 10)
            {
                xuatmang(arr, n);
                count++;
                printf("\n");
            }

        }else Try(k+1, m, arr, n);
        arr[x] = 0;
    }
    if(count == 0) printf("Khong co cach nao\n");
    
}

int main()
{
    int n, arr[100];
    printf("nhap so ptu mang : "); scanf("%d", &n);
    nhapmang(arr, n);
    xuatmang(arr, n);
    int m = count(arr, n);
    Try(1, m, arr, n);
}