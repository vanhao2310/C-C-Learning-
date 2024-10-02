#include<stdio.h>
#include<stdlib.h>

void Nhapmang(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
       arr[i] = rand()%21;
    }
}

void Xuatmang(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    printf("%d\t", arr[i]);
}

void merge(int arr[], int p, int q, int r) // p:first r:last q:mid
{
    
    int L[1000], R[1000];
    for(int a = p; a <= q; a++)
    {
        L[a] = arr[a];
    }
    for(int a = q; a <= r; a++)
    {
        R[a] = arr[a];
    }
    L[q+1] = 999999999;
    R[r+1] = 999999999;
    int i = p, j = q+1, k = p;
    while(i  <= q || j <= r)
    {
        if(L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    }

    
}

void mergesort(int arr[], int p, int r)
{
    if(p < r)
    {
        int q = (p+r)/2;
        mergesort(arr, p, q);
        mergesort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main()
{
    int arr[1000], n;
    printf("Nhap so phan tu cua mang : ");
    scanf("%d", &n);
    Nhapmang(arr, n);
    printf("Mang truoc khi sap xep:\n");
    Xuatmang(arr, n);
    mergesort(arr, 0, n-1);
    printf("\nMang sau khi sap xep :\n");
    Xuatmang(arr, n);
    return 0;
}