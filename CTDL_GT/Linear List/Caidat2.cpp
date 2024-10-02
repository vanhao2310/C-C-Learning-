#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

struct node
{
    ElementType data;
    struct node *next;
};

typedef struct node node;

// tạo node mới 
node* /*trả về con trỏ node*/ makenode(int x) // con trỏ trỏ tới node có data = x.
{
    node *newnode = (node*)/*ép kiểu sang con trỏ node*/(malloc)(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;

}

//dem so phan tu của mang
int count(node *head)
{
    int dem = 0;
    while(head != NULL)
    {
        dem++;
        head = head->next;
    }
    return dem;
}

//in ra danh sách
void InDS(node *head)
{
    while(head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
}

// tìm ptu có tri x.
node *find(node * head, int x)
{
    // node *newnode = head;
    while(head != NULL)
    {
        if(head->data == x)  return head;
        head = head->next;
    }
    return NULL;

}

//tìm ptu cuối cùng của mảng 
node* findlast(node *head)
{
    while(head != NULL)
    {
        if(head->next == NULL)
            return head;
        head = head->next;
    }
    return head;
}

//chèn ptu vào cuối danh sách.
node *InsertLast(node *head, int x)
{
    node *newnode = makenode(x);
    if(head == NULL) return newnode;
    node *temp  = head;     // cần 1 biến tạm để chạy con trỏ tạm tránh thay đổi vị trí con trỏ head.
    while(temp->next != NULL)
        temp = temp->next;
    temp->next= newnode;
    return head;
}

//chèn ptu vào đầu mảng
node *InsertFront(node *head, int x)
{
    node *newnode = makenode(x);
    if(head == NULL) return newnode;
    newnode->next = head;
    head = newnode;
    return head;
}

// xóa phần tủ trỏ bởi com trỏ p 
//(nếu xóa ptu sau con trỏ p thì gán p->next = (p->next)->next)
        // p->next = (p->next)->next;
        // node *newnode = p->next;
        // free(newnode);
node *Remove(node *head, node *p)
{
    if(head == NULL || p == NULL)
        return head;
    // di chuyển con trỏ tạm đến trước vị trí của con trỏ p
    node *newnode = head;
    while(newnode->next != p)
        newnode = newnode->next;
    // bài toán trỏ thành xóa ptu sau con trỏ newnode.
    newnode->next = p->next;
    free(p);
    return head;
}

//chèn ptu có gtri x vào đầu danh sách.
node* InsertAt(node *head, node * p, int x) //trèn vào sau ptu được trỏ bới con trỏ p
{
    if(p == NULL)
    {
        printf("eror\n");
        return head;
    }
    node *newnode = makenode(x);
    if(head == NULL) return newnode;
    newnode->next = p->next;
    p->next = newnode;
    return head;
}

//xóa ptu ở đầu
node *Removefirst(node *head)
{
    if(head == NULL)
    {
        printf("Empty!");
        return head;
    }
    node *newnode = (node*)(malloc)(sizeof(node));
    newnode = head;
    head = newnode->next;
    free(newnode);
    return head;
}

int main()
{
    node *head = NULL;
    for(int i = 0; i<10;i++)
    {
        head = InsertFront(head, i);
    }
    InDS(head);
    node *p = find(head, 5);
    head = Remove(head, p);
    printf("\n sau khi xoa \n");
    InDS(head);
    return 0;
}