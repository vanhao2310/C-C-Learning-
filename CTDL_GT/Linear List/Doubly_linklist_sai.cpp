// ds liên kết đôi có  ptu đặc biệt là head và tail
// head con trỏ trỏ tới ptu đầu  phàn prev của head là NULL
//tail con trỏ trỏ tới ptu cuói phần next của tail là NULL
// có thể tạo 1 struct doublelist chứa 2 con trỏ là head và tail để quả lý danh sách 
            // các hàm sẽ truyền vào kiểu dữ liệu doublelist là 1 danh sách list
            // câu lệnh tương tự chỉ cần thay head bằng list.head và tail bằng list.tail
            // dùng cách này khó hiểu nhuwngq quản lý hiệu quả hơn.

#include<stdio.h>
#include<stdlib.h>

//tạo danh sách liên kết đôi.
struct Dnode
{
    int data;
    struct Dnode *prev;
    struct Dnode *next;
};
typedef struct Dnode Dnode;

//tạo 1 ptu 
Dnode *makednode(int x)
{
    Dnode *newdnode = (Dnode*)(malloc)(sizeof(Dnode));
    newdnode->data = x;
    newdnode->prev = NULL;
    newdnode->next = NULL;
    return newdnode;
}

//hàm in ra DS
void InDS(Dnode *head) 
{
    if(head == NULL)
    {
        printf("Danh sach rong!");
        return;
    }
    while(head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
}

int count(Dnode *head)
{
    int dem = 0;
    while(head != NULL)
    {
        dem++;
        head = head->next;
    }
}

//hàm tìm kiếm ptu có giá trị x trả về con trỏ trỏ tới ptu có gtri x
Dnode *find(Dnode *head,int x)
{
    if(head == NULL)
    {
        printf("danh sách rỗng!\n");
        return NULL;
    }
    while(head->data != x)
        head = head->next;
    return head;
}

Dnode *InsertFirst(Dnode *head, Dnode *tail , int x)
{
    Dnode *newdnode = makednode(x);
    if(head == NULL)  // nếu danh sách rỗng thì phải tạo 1 ptu cho 2 con tro head và tail trỏ vào ptu đó
    {
        head = newdnode;
        tail = newdnode;
        return head;
    }
    //b1 gán next của newnode vào ptu đầu (head)
    newdnode->next = head;
    //b2 con trỏ head trỏ lại về ptu đầu mới trèn vào là newdnode
    head->prev = newdnode;
    head = newdnode;
    return head;
}

// trèn vào cuối ds
Dnode *InsertLast(Dnode *head, Dnode *tail, int x)
{
   Dnode *newdnode = makednode(x);
   if(head == NULL)  // nếu danh sách rỗng thì phải tạo 1 ptu cho 2 con tro head và tail trỏ vào ptu đó
    {
        head = newdnode;
        tail = newdnode;
        return head;
    }
        //b1 gán prev của newdnode cho tail
   newdnode->prev = tail;
        //b2 gán next của tail  trỏ vào newdnode.
   tail->next = newdnode;
        //b3 cho tail trỏ lại newdnode.
   tail = newdnode;
   return head;
}

// trèn 1 ptu có gtri x vào sau con tro after.
Dnode *InsertAfter(Dnode *head, Dnode *tail, Dnode *after, int x)
{
    if(after == NULL || head == NULL)
    {
        printf("eror place!\n");
        return head;
    }
    Dnode *newdnode = (Dnode*)(malloc)(sizeof(Dnode));
    newdnode->data = x;
    newdnode->prev = NULL;
    newdnode->next = NULL;
    if(after == tail)
    {
        newdnode->prev = tail;
        tail = newdnode;
    }
}

int main()
{
    Dnode *head = NULL;
    Dnode *tail = NULL;
    InDS(head);
    for(int i = 0; i<10;i++)
    {
        head = InsertLast(head, tail, i);
    }
    printf("-------------------------\n");
    InDS(head);
    return 0;
}