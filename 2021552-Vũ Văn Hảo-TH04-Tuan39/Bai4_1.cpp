//Vu Van Hao 20215572
/*
Bài tập 1: Đảo ngược một danh sách liên kết đơn
*/
#include <iostream> 
using namespace std;

//cấu trúc của node trong danh sách liên kết
struct Node { 
    int data; 
    Node* next;

    Node(int data) {    //constructor 
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    /*****************
    Vu Van Hao 20215572
    *****************/
    Node* tmp = new Node(data); //khởi tạo node với dữ liệu data
    tmp->next = head;   //cho next trỏ tới phàn tử đầu cũ
    head = tmp;     //chuyển head về phần tử đầu
    return head;
}

// print the list content on a line
void print(Node* head) {
    /*****************
    Vu Van Hao - 20215572
    *****************/
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout<< endl;
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    /*****************
    Vu Van Hao 20215572
    *****************/
    Node* next = NULL;
    Node* prev = NULL;
    while(head){
        next = head->next;  //luwulaij phần tử tiếp theo
        head->next = prev;  //đảo ngược lại
        prev = head;    //cho prev di chuyển đến phần tử hiện tại
        head = next;    //head chuyển đến phần tử tiếp theo
    }
    return prev;
}
  
int main() {
    int n, u;   
    cin >> n;   //số phần tử của linklist
    Node* head = NULL;  
    for (int i = 0; i < n; ++i){
        //nhập vào linklist
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);   //đảo ngược danh sách
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}
//Vu Van Hao 20215572