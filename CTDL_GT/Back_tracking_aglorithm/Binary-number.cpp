#include<stdio.h>
#include<math.h>


void Xuatmang(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
        printf("\n");
}

void Bit(int k, int n, int x[])
{
    for(int v = 0; v <= 1; v++)
    {
        x[k] = v;
        if(k == n -1) 
            Xuatmang(x, n);
        else Bit(k+1, n, x);
    }
}




int main()
{
    int n, x[100];
    printf("Nhap so bit = "); scanf("%d", &n);
    Bit(0, n, x);
}