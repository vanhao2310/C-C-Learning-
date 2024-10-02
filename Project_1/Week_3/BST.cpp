/*
    Problem: Week 3 - BST - Insertion and PreOrder Traversal
    author: Vu Van Hao 20215572
*/
#include<bits/stdc++.h>

struct Node {
    int data;
    Node *left_child;
    Node *right_child;
};
Node* make_node(int data){
    Node *newnode = new(Node);
    newnode->data = data;
    newnode->left_child = NULL;
    newnode->right_child = NULL;
    return newnode;
}

void Insert(Node* (&T), int data){
    if(T == NULL)
        T = make_node(data);
    else if(T->data == data)
        return;
    else if(data < T->data)
        Insert(T->left_child, data);
    else    
        Insert(T->right_child, data);
}

void print_preoder(Node* BST){
    if(BST == NULL)
        return;
    std::cout << BST->data << " ";
    print_preoder(BST->left_child);
    print_preoder(BST->right_child);
}

void process_query(Node* (&Tree), std::string query){
    int index_space = query.find(' ');
    int num = stoi(query.substr(index_space+1, query.length()-index_space-1));
    Insert(Tree, num);
}

int main(){
    Node* Tree = NULL;
    
    std::string query;
    while(getline(std::cin, query)){
        if(query == "#")
            break;
        process_query(Tree, query);
    }

    print_preoder(Tree);
    return 0;
}