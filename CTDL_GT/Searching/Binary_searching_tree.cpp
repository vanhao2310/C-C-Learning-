#include<stdio.h>
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

void Max_heap(int arr[], int i, int n)  // tai tao lai max heap o vi tri i gia su cay con trai va cay con phai da la maxheap
{
    int leftchild = 2*i, rightchild = 2*i + 1;
    int largest;
    if( arr[leftchild] > arr[i] && leftchild <= n)
        largest = leftchild;
    else largest = i;
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
    for(int i = n/2; i > 0 ; i--) 
    {
        Max_heap(arr, i, n);
    }
}
void Heap_sort(int arr[], int n)
{
    Build_max_heap(arr, n);
    for(int i = n; i > 1; i--)
    {
        swap(&arr[1], &arr[i]);
        Max_heap(arr, 1, i-1);
    }
}

struct Tree_nodeRec
{
    int data;
    struct Tree_nodeRec* leftchild;
    struct Tree_nodeRec* rightchild;
};

typedef struct Tree_nodeRec Treenode;

Treenode* MakeTreenode(int x)
{
    Treenode* newnode = (Treenode*)(malloc)(sizeof(Treenode));
    if(newnode == NULL)
    {
        printf("Eror, out of memory\n");
        exit(1);
    }else{
        newnode->data = x;
        newnode->leftchild = NULL;
        newnode->rightchild = NULL;
    }
    return newnode;
}

Treenode* Find_max(Treenode* T)
{
    if(T == NULL)   return NULL;
    while(T->rightchild != NULL)
        T = T->rightchild;
    return T;
}
Treenode* Find_min(Treenode* T)
{
    if(T == NULL) return NULL;
    while(T->leftchild != NULL)
        T=T->leftchild;
    return T;
}

// duyệt cây theo thứ tự giữa
void PrintInorder(Treenode* T)
{
    if(T != NULL)
    {
    PrintInorder(T->leftchild);
    printf("%d\t", T->data);
    PrintInorder(T->rightchild);
    }
}

Treenode* Insert(Treenode* T, int x)
{
    if(T == NULL)
        T = MakeTreenode(x);
    else if( x < T->data)
        T->leftchild = Insert(T->leftchild, x);
    else if(x > T->data)
        T->rightchild = Insert(T->rightchild, x);
    return T;
}

Treenode* Delete(Treenode* T, int x)    //xóa ptu có giá trị x
{
    Treenode* tmp;
    if(T == NULL) printf("Not found\n");
    else if(x < T->data)    // đi sang bên trái
        T->leftchild = Delete(T->leftchild, x);
    else if(x > T->data)  // đi sang bên phải 
        T->rightchild = Delete(T->rightchild, x);
    else // tìm được node có data = x
    {
        if(T->leftchild && T->rightchild)   // node này có cả cây con trái và cây con phải
        {
            
            tmp = Find_min(T->rightchild);    //b1 tìm ptu thế chỗ là ptu kế cận sau (Min cây con phải)
            
            T->data = tmp->data;    //b2 thay đổi giá trị của node T thành giá trị thay thế
            
            T->rightchild = Delete(T->rightchild, tmp->data);   // xóa bỏ ptu thay thế
        }else  //node này chỉ có 1 con 
        {
            tmp = T;
            if(T->leftchild == NULL)    // chỉ có con phải hoặc không có con nào
            {
                T = T->rightchild;
                free(tmp);
            }else if(T->rightchild == NULL)     // chỉ có con trái
            {
                T = T->leftchild;
                free(tmp);
            }
        }               
    }
    return T;
}


int main()
{
    Treenode* Binary_tree_search = NULL ;  // tạo một cây nhị phân tìm kiếm mới
    for(int i = 0; i < 10; i++)
        Binary_tree_search = Insert(Binary_tree_search, i); //Insert(Binary_tree_search, rand()%21);
    PrintInorder(Binary_tree_search);
    return 0;
}