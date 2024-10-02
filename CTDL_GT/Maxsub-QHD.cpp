#include<stdio.h>

void Nhapmang(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("nhap a[%d] = ", i);
        scanf("%d", &arr[i]);
    }
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

int Maxsub(int arr[], int n)
{
    int smax = arr[0];      // trong so cua day con lon nhat
    int maxendhere  = arr[0];       // trong so cua day con ket thuc tai a[i]
    int u, v;
    for(int i = 1; i < n; i++ )
    {
        u = maxendhere + arr[i];
        v = arr[i];
        if(u > v)
            maxendhere = u;
        else 
            maxendhere = v;

        if(maxendhere > smax)
            smax = maxendhere;
    }
    return smax;
}

int main()
{
    int arr[1000], n;
    printf("nhap n = ");
    scanf("%d", &n);
    Nhapmang(arr, n);
    int maxsub = Maxsub(arr, n);
    printf("\nTrong so lon nhat cua day la : %d", maxsub);

}