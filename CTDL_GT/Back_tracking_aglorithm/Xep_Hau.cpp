#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Xuatmang(int arr[], int n)
{
    for(int i = 1; i <= n; i++)
    {
        printf("%d\t", arr[i]);
    }
        printf("\n");
}

int UCV(int j, int k, int arr[])
{
    for(int i = 1; i < k; i++)
    {
        if(j == arr[i] || fabs(j - arr[i]) == fabs(k-i))
            return 0;
    }
    return 1;
}

int Xep_hau(int k, int n, int arr[])
{
    for(int i = 1; i <= n; i++)
    {
        if(UCV(i, k, arr))
        {
            arr[k] = i;
            if(k == n)
            {
                Xuatmang(arr, n);
                exit(0);
            }
            else Xep_hau(k+1, n, arr);
        }

    }
}



int main()
{
    int n, arr[100];
    printf("Nhap so dong so cot : "); scanf("%d", &n);
    Xep_hau(1, n, arr);
    printf("mmmmm");
}