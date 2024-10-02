#include<stdio.h>
#include<math.h>
#include<stdlib.h>

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

int Max(int a, int b, int c)
{
    int max = a;
    if( max < b) max = b;
    if(max < c) max = c;
    return max;
}

int Maxleft(int arr[], int i, int j)
{
    int Maxsum = -9999999, sum = 0;  // Maxsum ban dau = -vc
    for(int a = j; a >= i; a--)
    {
        sum += arr[a];
        Maxsum = (sum > Maxsum)?sum:Maxsum;
    }
    return Maxsum;

}


int Maxright(int arr[], int i, int j)
{
    int Maxsum = -999999, sum = 0;
    for(int a = i; a <= j; a++)
    {
        sum += arr[a];
        Maxsum = (sum > Maxsum)?sum:Maxsum;
    }
    return Maxsum;

}

int Maxsub(int arr[], int i, int j)
{
    if(i == j )
        return arr[i];
    else{
        int mid =(i+j)/2;
        int WL, WR, WM;
        WL = Maxsub(arr, i, mid);
        WR = Maxsub(arr, mid+1, j);
        WM = Maxleft(arr, i, mid) + Maxright(arr, mid+1, j);
        return Max(WL, WR, WM);
    }
}


int main()
{
    int arr[1000], n;
    printf("nhap n = ");
    scanf("%d", &n);
    Nhapmang(arr, n);
    int maxsub = Maxsub(arr, 0, n-1);
    printf("\nTrong so lon nhat cua day la : %d", maxsub);

}