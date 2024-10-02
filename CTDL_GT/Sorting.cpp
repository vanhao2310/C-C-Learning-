#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//swap
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Nhapmang_heap(int arr[], int n)
{
    for(int  i = 1 ; i <= n; i++)
        arr[i] = rand()%21;
}
void Xuatmang_heap(int a[], int n)
{
    for(int i = 1; i <= n; i++)
        printf("%d\t", a[i]);
     printf("\n");
}

void Nhapmang(int a[], int n)   
{
    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 21;
    }
    printf("\n");
}

void Xuatmang(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d\t", a[i]);
     printf("\n");
}
// Insertion sort (sap xep chen)
void Insertion_sort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int last = a[i];
        int j = i;
        while(j > 0 && (a[j-1] > last) )
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = last;
    }
}

void Selection_sort(int a[], int n)
{
    int min;
    for(int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[min]) 
                min = j;
                // swap(&a[i], &a[j]);// cach nay doi cho nhieu lan khoong toi uu
        }
        swap(&a[i], &a[min]);
    }   
   
}

void Bouble_sort(int a[], int n)
{
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = 0; j < i ; j++)
        {
            if(a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
        }
    }
}

void Merge(int a[], int first, int mid, int last)
{
    int L[100], R[100];
    for(int i = first; i <= mid ; i++)
        L[i] = a[i];
    for(int i = mid+1; i <= last; i++)
        R[i] = a[i];
    L[mid + 1] = 99999;
    R[last + 1] = 99999;
    int k  = first, i = first, j = mid + 1;
    while(i <= mid || j <= last)
    {
        if(L[i] < R[j])
            a[k++] = L[i++];
        else    
            a[k++] = R[j++];
    }
}

void Merge_sort(int a[], int first, int last)
{
    if(first < last)
    {
        int mid = (first + last) / 2;
        Merge_sort(a, first, mid);
        Merge_sort(a, mid + 1, last);
        Merge(a, first, mid, last);
    }
}

int Partition(int arr[], int left, int right)// pivot laf ptu dung dau (left)
{
    int i = left, j = right+1, pivot = arr[left];
    while(i < j)
    {
        i++;
        while(arr[i] < pivot && i <= right)
            i++;
        j--;
        while(arr[j] > pivot && j >= left)
            j--;
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[i], &arr[j]);
    swap(&arr[j], &arr[left]);
    return j;
}
void Quick_sort(int arr[], int left, int right)
{
    if(left < right)
    {
        int pivot = Partition(arr, left, right);
        Quick_sort(arr, left, pivot - 1);
        Quick_sort(arr, pivot+1, right);
    }
}

// Heap_sort
void Max_heap(int arr[], int i, int n) // ham khoi phuc heap max n: kich thuoc heap (heapsize)
                                // gia su cay con trai va phai cua nut i dang la max_heap
{
    int leftchild = 2*i, rightchild = 2*i +1;
    int largest = i;
    if(arr[leftchild] > arr[i] && leftchild <= n)
        largest = leftchild;
    if(arr[rightchild] > arr[largest] && rightchild <= n)
        largest = rightchild;
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        Max_heap(arr, largest, n);
    }
}

void Build_max_heap(int arr[], int n)
{
    for(int i = n/2; i >0; i--)
        Max_heap(arr, i, n);
}

void Heap_sort(int arr[], int n)    //n: heapsize
{
    Build_max_heap(arr, n);
    for(int i = n; i > 0; i--)
    {
        swap(&arr[1], &arr[i]);
        Max_heap(arr, 1,  i-1);
    }
}

/// Với heap sort phần tử đầu bắt đầu từ vị trí 1  
int main()
{
    int a[100];
    Nhapmang_heap(a, 20);
    Xuatmang_heap(a, 20);
    Heap_sort(a, 20);
    Xuatmang_heap(a, 20);
    return 0;
}