/*
    Problem: Week 3 - Linked List Manipulation
    author: Vu Van Hao 20215572
*/

#include<bits/stdc++.h>

struct Node{
    int data;
    Node *next;
};

Node* make_node(int data){
    Node *newnode = new(Node);
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

//tim ptu co data = value trong list
Node* find(Node* head, int value){
    if(head == NULL)
        return NULL;
    while(head != NULL)
    {
        if(head->data == value)
            return head;
        head = head->next;
    }
    return head;
}

//check ptu co khoa key da ton tai trong danh sach chua
bool check(Node* head, int key){
    bool tmp = false;
    while(head != NULL){
        if(head->data == key){
            tmp = true;
            break;
        }
        head = head->next;
    }
    return tmp;

}

void addfirst(Node* (&head), int data){
    Node* newnode = make_node(data);
    if(head == NULL)
        head  = newnode;
    else{
        if(!check(head, data)){     //kiem tra ptu da ton tai trong list chua truoc khi add
            newnode->next = head;
            head = newnode;
        }    
    }
}

void addlast(Node*(&head), int data){
    Node *temp = head;
    Node* newnode = make_node(data);
    if(temp == NULL){
        head = newnode;
    }else{
        if(check(head, data))       //neu phan tu da ton tai trong list thi khong add nua
            return;
        while(temp->next != NULL){

            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void addafter(Node* (&head), int num, int data){    //them data vao sau ptu num
    Node *newnode = make_node(data);
    Node *temp = head;
    if(check(head, data))   //neu data da co trong list k add nua
        return;
    if(!check(head, num))     //neu phan tu canf chen vao sau khhong ton tai thi khong thuc hien duoc
        return;
    
    //neu num da ton tai trong mang va ptu data chua xuat hien trong mang thi tren data vao sau ptu num
    while(temp->data != num)    //di chuyen con tro tam den vi tri ptu num
        temp = temp->next;
    newnode->next = temp->next;
    temp->next = newnode;
}


void addbefore(Node* (&head), int num, int data){   //them data vao truoc ptu num
    Node* newnode = make_node(data);
    Node* temp = head;
    if(check(head, data))   //neu data da co trong list k add nua
        return;
    if(!check(head, num))     //neu phan tu can chen vao trc khhong ton tai thi khong thuc hien duoc
        return;

    //neu num da ton tai va data chua xuat hien trong list thi them data vao truoc phan tu num
    while((temp->next)->data != num)
        temp = temp->next;
    newnode->next = temp->next;
    temp->next = newnode;
}



void print(Node *head){
    if(head == NULL){
        std::cout << "List is empty!" << std::endl;
    }else{
        while(head != NULL){
            std::cout << head->data << " ";
            head = head->next;
        }
    }
}

void remove(Node* (&head), int data){
    if(head == NULL)
        return;
    if(head->data == data){
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    if(!check(head, data))
        return;

    Node* temp = head;
    Node* rm = head;
    while(rm->data != data){
        temp = rm;
        rm = rm->next;
    }
    temp->next = rm->next;
    delete rm;
}

void reverse(Node* (&head)){
    if(head == NULL)    //check list is emty?
        return;
        
    Node* before = NULL;    //before head
    Node* after = head->next;   //after head
    while(head->next != NULL){
        head->next = before;
        before = head;
        head = after;
        after = after->next;
    }
    head->next = before;
}

int check_query(std::string query){
    int index_space = query.find(' ');
    if(index_space == -1)
        return -1;
    std::string sub = query.substr(0, index_space);
    if(sub == "addlast")
        return 1;
    else if(sub == "addfirst")
        return 2;
    else if(sub == "addafter")
        return 3;
    else if(sub == "addbefore")
        return 4;
    else if(sub == "remove")
        return 5;
    
    return 0;
}

void process(Node* (&list), std::string query){
    int choice = check_query(query);
     int index_space = query.find(' ');
    switch (choice)
    {
    case 1:{
        int data = stoi(query.substr(index_space+1, query.length() - index_space-1));
        addlast(list, data);
        break;
    }
    case 2:{
        int data = stoi(query.substr(index_space+1, query.length()-index_space-1));
        addfirst(list, data);
        break;
    }
    case 3:{
        int index_space2 = query.find(' ', index_space+1);
        int first_num = stoi(query.substr(index_space+1, index_space2 - index_space - 1));
        int second_num = stoi(query.substr(index_space2 + 1, query.length() - index_space2 - 1));
        addafter(list, second_num, first_num);
        break;
    }
    case 4:{
        int index_space2 = query.find(' ', index_space+1);
        int first_num = stoi(query.substr(index_space+1, index_space2 - index_space - 1));
        int second_num = stoi(query.substr(index_space2 + 1, query.length() - index_space2 - 1));
        addbefore(list, second_num, first_num);
        break;
    }
    case 5:{
        int data = stoi(query.substr(index_space + 1, query.length() - index_space - 1));
        remove(list, data);
        break;
    }
    case -1:{
        reverse(list);
        break;
    }
    default:
        break;
    }

}

int main(){
    int n;
    std::cin >> n;
    int num;
    std::string query;
    Node   *list = NULL;
    for(int i = 0; i < n; i++){
        std::cin >> num;
        addfirst(list, num);
    }

    while(getline(std::cin, query)){
        if(query == "#")
            break;
       process(list, query);
    }

    print(list);
    delete list;
    return 0;
}