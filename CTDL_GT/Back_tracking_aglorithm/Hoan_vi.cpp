#include<stdio.h>
#include<math.h>

void Xuatmang(int arr[], int n)
{
    for(int i = 1; i <= n; i++)
        printf("%d", arr[i]);
    printf("\n");
}
void gan_mang(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
        arr[i] = 0;
    
}

void Hoanvi2( int k , int brr[], int n)
{
    for(int i = 1; i <= n; i++)
    {   
            brr[k] = i;
            if(k == n)
                Xuatmang(brr, n);
            else Hoanvi2(k+1, brr, n);   
    }

}

void Hoanvi( int k , int brr[], int n, int arr[])
{
    for(int i = 1; i <= n; i++)
    {
        if(!arr[i])
        {
            brr[k] = i;
            arr[i] = 1;
            if(k == n)
                Xuatmang(brr, n);
            else Hoanvi(k+1, brr, n, arr);
            arr[i] = 0;
        }
        
    }

}

int main()
{
    int n, arr[100], brr[100];
    printf("Nhap phan tu lon nhat : "); scanf("%d", &n);
    gan_mang(arr, n);
    Hoanvi2(1, brr, n);
    printf("Khong giong\n");
    Hoanvi(1, brr, n, arr);

}