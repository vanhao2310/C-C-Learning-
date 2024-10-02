// cách cài đặt này các câu lệnh chèn thê phần tử dùng hàm void nên k trả về giá trị mà gọi tham chiếu
//                                                      và chén trực tiếp vào danh sách truyền vào hàm

#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;    // ElementType is int

struct node     
{
    ElementType data;
    struct node *next; // link
};

typedef struct node node;   // đặt lại tên 

node* makenode(ElementType x)        // trả về con trỏ kiểu node trỏ đến node có giá trị x.
{
    node *newnode = (node*)/*ép kiểu*/(malloc)(sizeof(node)); // hàm malloc cần khai báo thư viện stdlib.h
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}          

int count(node *head)
{
    int dem = 0;
    while(head != NULL)
    {
        dem ++;
        head = head->next;
    }
    return dem;
}

void InDS(node *head)
{
    while(head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
}

// trèn vào đầu. với giá trị x
void Insertfront(node *(*head), int x)// khi gọi hàm thì truyền vào sẽ là địa chỉ của head vì đang dùng con trỏ trỏ đến con trỏ head
                                        // gọi hàm Insertfront(&head)
{
    node *newnode = (node*)(malloc)(sizeof(node)); // tạo ra node có data = x. có thẻ dùng luôn hàm makenode(x).
        newnode->data = x;
        newnode->next = NULL;
    //B1: con trỏ next của newnode trỏ vào phần tử đầu(=*head)
    newnode->next = *(head);  // * là toán tử giải tham chiếu khi thay đổi sẽ thây đổi trực tiếp trên đối số truyền vào
    //B2: cho con trỏ head trỏ đến newnode.
    *(head) = newnode;   // dấu * ở đây đẻ chỉ giá trị của con trỏ head dc gán bằng newnode
                       //(newnode là 1 con trỏ nên giá trị của newnode là địa chỉ còn newnode->data mới là giá trị mà newnode lưu trữ)

}

void Insertback(node **head, int x) // con trỏ trỏ đến con trỏ head
                                    // 
{
    node *temp = *head;
    node *newnode = makenode(x); // tạo node mới có gtri x.

        //nếu danh sách rỗng thì head = NULL
    if(temp == NULL)
    {
        * head = newnode; // * là tham chiếu : giá trị mà con trỏ đang trỏ tới là giá trị của head dc gán bằng giá trị của con trỏ newnode
        return;
    }

    while(temp->next != NULL) // đúng khi danh sách có ít nhất 1 ptu
        temp = temp->next;
    temp->next = newnode;    // gán con trỏ next của node cuối hiện tại trỏ sang newnode
    
}
void Insert(node **head, int k, int x)    // trèn x vào vị trí thứ k  
{
    int n = count(*head);
    if(k < 1 || k > (n + 1) )
    {
        printf("error place\n");
        return;
    }
    if(k == 1)
        Insertfront(head, x);
    else{
        node *newnode = makenode(x);
        node *temp = *head;     // tạo con trỏ tạm để k làm thay đổi giá trị cả head;
        // chèn vào vị trí k thì cần di chuyển con trỏ đến vị trí k-1 
        // sau đó cho newnode trỏ vào ptu thứ k (gán newnode->next = temp->next)
        // cho node k-1 trỏ vào newnode (gán temp->next = newnode)
        for(int i = 1; i < k-1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

}

node* Insert2(node *pred, int x)
{
    node *newnode = makenode(x);
    newnode->next = pred->next;
    pred->next = newnode;
    return newnode;
}


int main()
{
    node *head = NULL; // con trỏ head để quản lý danh sách liên kết.
    for(int i = 0; i <= 10; i++)
    {
        Insertback(&head, i);
    }
    InDS(head);
    
}