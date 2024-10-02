// ds liên kết đôi có  ptu đặc biệt là head và tail
// head con trỏ trỏ tới ptu đầu  phàn prev của head là NULL
//tail con trỏ trỏ tới ptu cuói phần next của tail là NULL
// có thể tạo 1 struct doublelist chứa 2 con trỏ là head và tail để quả lý danh sách 
            // các hàm sẽ truyền vào kiểu dữ liệu doublelist là 1 danh sách list
            // câu lệnh tương tự chỉ cần thay head bằng list.head và tail bằng list.tail

#include<stdio.h>
#include<stdlib.h>

//tạo ds liên kết đôi
struct Dnode
{
    int data;
    struct Dnode *prev;
    struct Dnode *next;
};
typedef struct Dnode Dnode;

//tạo phần quản lý danh sách
typedef struct doublelist
{
    Dnode *head;
    Dnode *tail;
}doublelist;

//tạo 1 Dnode mới
Dnode *makednode(int x)
{
    Dnode *newdnode = (Dnode*)(malloc)(sizeof(Dnode));
    newdnode->data = x;
    newdnode->prev = NULL;
    newdnode->next = NULL;
    return newdnode;
}

//in ra giá trị của ptu trỏ bởi con trỏ p
void Inptu(doublelist list, Dnode *p)
{
    while(list.head != p)
        list.head = list.head->next;
    printf("%d\n", list.head->data);
}

//in ra ds 
void InDS(doublelist list)
{
    if(list.head == NULL)
    {
        printf("Danh sach rong!");
        return;
    }
    while(list.head != NULL)
    {
        printf("%d\t", (list.head)->data);
        list.head = (list.head)->next;
    }
    printf("\n");
}

//đém số ptu của ds
int count(Dnode *head)
{
    int dem = 0;
    while(head != NULL)
    {
        dem++;
        head = head->next;
    }
}

// hàm trả về con trỏ trỏ đến ptu có data = x
Dnode *find(doublelist list, int x)
{
    if(list.head == NULL)
    {
        printf("eror!\n");
        return NULL;
    }
    while(list.head->data != x)
        list.head = list.head->next;
    return list.head;
}

// Trèn vào đầu ds
doublelist InsertFirst(doublelist list , int x)
{
    Dnode *newdnode = makednode(x);
    if(list.head == NULL)  //nếu danh sách rỗng phải tạo 1 ptu và cho head và tail trỏ vào ptu đó
    {
        list.head = newdnode;
        list.tail = newdnode;
        return list;
    }
    //b1 gán next của newdnode cho head
    newdnode->next = list.head;
    //b2 cho phần prev của ptu đầu (trỏ bởi head) trỏ đến newdnode.
    list.head->prev = newdnode;
    //cập nhật cho head trỏ đến ptu đầu mới được thay bới newdnode.
    list.head = newdnode;
    return list;
}

doublelist InsertLast(doublelist list, int x)
{
   Dnode *newdnode = makednode(x);
   if(list.head == NULL)  //nếu danh sách rỗng phải tạo 1 ptu và cho head và tail trỏ vào ptu đó
    {
        list.head = newdnode;
        list.tail = newdnode;
        return list;
    }
   //b1 cho prev của newdnode trỏ đến ptu cuối cùng của ds(đang dc trỏ bới tail).
   newdnode->prev = list.tail;
   //b2 cho next của ptur cuối(đang được trỏ bới tail) trỏ tới newdnode.
   list.tail->next = newdnode;
   //cập nhật cho tail trỏ đến ptu cuối mới được thay bởi newdnode.
   list.tail = newdnode;
   return list;
}

//trèn ptu vào sau ptu được trỏ bởi after
doublelist InsertAfter(doublelist list, Dnode *after, int x)
{
    if(after == NULL || list.head == NULL)
    {
        printf("eror!\n");
        return list;
    }
    Dnode *newdnode = makednode(x);
    if(after == list.head)
    {
        newdnode->next = list.head;
        list.head->prev = newdnode;
        list.head = newdnode;
        return list;
    }
    if(after == list.tail)
    {
        newdnode->prev = list.tail;
        list.tail->next = newdnode;
        list.tail = newdnode;
        return list;
    }
    newdnode->prev = after;
    newdnode->next = after->next;
    after->next = newdnode;
    after->next->prev = newdnode;
    return list;
}

int main()
{
    doublelist list;
    list.head = NULL;
    list.tail = NULL;
    InDS(list);
    int i ;
    for( i = 0; i<10;i++)
    {
        list = InsertLast(list, i);
    }
    printf("-------------------------\n");
    InDS(list);
    Dnode *p = find(list, 5);
    list = InsertAfter(list, p, 11);
    InDS(list);
    return 0;
}