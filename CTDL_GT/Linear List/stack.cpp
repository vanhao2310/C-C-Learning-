#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *makenode(int x)
{
    node *newnode = (node*)(malloc)(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

int size(node *st)
{
    int count = 0;
    while(st != NULL)
    {
        count++;
        st = st->next;
    }
    return count;
}

bool isEmpty(node *st)
{
    return st == NULL;
}

void INDS(node *st)
{
    if(st == NULL)
    {
        printf("Empty\n");
        return;
    }
    while(st != NULL)
    {
        printf("%d\t", st->data);
        st = st->next;
    }
    printf("\n");
}

node *push(node *st, int x)
{
    node *newnode = makenode(x);
    if(st == NULL)  return newnode;
    newnode->next = st;
    st = newnode;
    return st;
}

node *pop(node *st)
{
    if(st == NULL)
    {
        printf("ERROR!");
        return st;
    }
    node *newnode = st;
    st = newnode->next;
    free(newnode);
    return st;
}

void top(node *st)
{
    if(st == NULL)
    {
        printf("Empty!\n");
        return;
    }
    printf("%d\n",st->data);
}


int main()
{
    node *st = NULL;
    
    while(1)
    {
        int lc;
        printf("---------------------------\n");
        printf("1:push\n");
        printf("2:pop\n");
        printf("3:top\n");
        printf("4:INDS\n");
        printf("---------------------------\n");
        printf("Nhap lua chon : "); scanf("%d", &lc);
        switch (lc)
        {
            case 1 :
                {
                    int x;
                    printf("Nhap x = : "); scanf("%d", &x);
                    st = push(st, x);
                }
                break;
            case 2 :
                {
                    st = pop(st);
                }
                break;
            case 3:
                {
                    top(st);
                }
                break;
            case 4:
                    INDS(st);
                break;
            default:
                break;
        }
    }
}
