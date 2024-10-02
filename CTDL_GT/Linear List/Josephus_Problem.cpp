#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node node;

node* makenode(int x)
{
    node *newnode = (node*)(malloc)(sizeof(node));
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

struct list
{
    node *head;
    node *tail;
};
typedef struct list list;

void INDS(list ds)
{
    if(ds.head == NULL)
    {
        printf("ds rong!\n");
        return ;
    }
    while(ds.head != NULL)
    {
        printf("%d\t", ds.head->data);
        ds.head = ds.head->next;
    }
    printf("\n");
}

int size(list ds)
{
    int count = 0;
    while(ds.head != NULL)
    {
        
        count++;
        ds.head = ds.head->next;
    }
    return count;
}

node* find(list ds, int x)
{
    while(ds.head->data != x)
        ds.head = ds.head->next;
    return ds.head;
}

list InsertLast(list ds, int x)
{
    node *newnode = makenode(x);
    if(ds.head == NULL)
    {
        ds.head = newnode;
        ds.tail = newnode;
        return ds;
    }
    newnode->prev = ds.tail;
    ds.tail->next = newnode;
    newnode->next = ds.head;
    return ds;
}

list Remove(list ds, node *place)
{
    node *newnode  = ds.head;
    if(ds.head == NULL)
    {
        printf("DS rong!\n");
        return ds;
    }
    while(newnode->next != place)
        newnode = newnode->next;
    newnode->next = place->next;
    place->next->prev = newnode;
    free(place);
    return ds;
}

list RemoveFirst(list ds)
{
    if(ds.head == NULL)
    {
        printf("ds rong!\n");
        return ds;
    }
    node *newnode = (node*)(malloc)(sizeof(node));
    newnode = ds.head;
    ds.head = newnode->next;
    free(newnode);
    return ds;
}

int winner(list ds)
{
    return ds.head->data;
}

void Josephus(list ds, int m)
{
    while(ds.head->next != NULL)
    {
        for(int i = 1; i <= m; i++)
        {
            ds.head = ds.head->next;
        }
        ds = RemoveFirst(ds);
    }
    printf("nguoi thang cuoc la nguoi mang so : %d\n", winner(ds));
}

int main()
{
    list ds;
    ds.head = NULL;
    ds.tail = NULL;
    int n;
    printf("Nhap so nguoi choi n = ");
    scanf("%d", &n);
    for(int i = 1; i<= n; i++)
        ds = InsertLast(ds, i);
    int m;
    printf("nhap con so may man(< %d) : ", n);
    scanf("%d", &m);
    Josephus(ds, m);
    return 0;

}