#include<stdio.h>
#include<fstream>
void Nhapmang(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void Xuatmang(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
        if(i == n-1)
        printf("\n");
    }
}

void merge(int arr[], int first, int mid, int last)
{
    int i, j, k;
    int L[1000], R[1000];
    i = first; j = mid + 1; k = first;
    for(int a = first; a <= mid; a++)
        L[a] = arr[a];
    L[mid+1] = 9999999;
    for(int a = mid + 1; a <= last; a++)
        R[a] = arr[a];
    R[last+1] = 999999;
    while(i <= mid || j <= last)
    {
      if(L[i] <= R[j])
      {
        arr[k++] = L[i++];
      }else{
        arr[k++] = R[j++];
      }
    }
}

void mergesort(int arr[] , int first, int last)
{
    if(first < last)
    {
        int mid = (first + last) / 2;
        mergesort(arr, first, mid);
        mergesort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int arr[1000], n;
    scanf("%d", &n);
    Nhapmang(arr, n);
    printf("Mang truoc khi sap xep la\n");
    Xuatmang(arr,n);
    mergesort(arr, 0, n);
    printf("Mang sau khi sap xep la\n");
    Xuatmang(arr, n);
    return 0;
}