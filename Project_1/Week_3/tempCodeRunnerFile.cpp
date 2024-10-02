/*  
    Problem: Week 3 - Tree manipulation & Traversal
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>

struct Node{
    int id;
    std::vector<Node*> childrens;
};

bool check(Node* tree, int id){
    if(tree == NULL)
        return false;
    if(tree->id == id)
        return true;
    else{
        if((tree->childrens).empty())
            return false;
        else{
            for(Node* tmp : (tree->childrens))
                if(check(tmp, id))
                    return true;
        }
    }
    return false;
}

Node* make_node(int id){
    Node *newnode = new(Node);
    newnode->id = id;
    return newnode;
}

void Insert(Node* (&tree), int children_id, int parent_id){
    if(!check(tree, parent_id))
        return;
    if(check(tree, children_id))
        return;
    if(tree->id == parent_id){
        Node* children = make_node(children_id);
        tree->childrens.push_back(children);
    }else{
        if(tree->childrens.empty())
            return;
        for(int i = 0; i < tree->childrens.size(); i++){
            Insert(tree->childrens.at(i), children_id, parent_id);
        }   
    }
}

void print_preoder(Node* tree){
    if(tree == NULL)
        return;
    else{
        std::cout<< tree->id << " ";
        if(!tree->childrens.empty()){
            for(Node* tmp : tree->childrens)
                print_preoder(tmp);
        }
    }
}

void print_inorder(Node* tree){
    if(tree->childrens.empty())
        std::cout << tree->id << " ";
    else{
        print_inorder(tree->childrens.at(0));
        std::cout << tree->id << " ";
        for(int i = 1; i < tree->childrens.size(); i++){
            print_inorder(tree->childrens.at(i));
        }
    }
}

void print_postorder(Node* tree){
    if(tree->childrens.empty())
        std::cout << tree->id << " ";
    else{

        for(Node* tmp : (tree->childrens))
            print_postorder(tmp);
        std::cout << tree->id << " ";
    }
}

int check_query(std::string query){
    int index_space = query.find(' ');
    if(index_space < 0){
        if(query == "PreOrder")
            return 2;
        else if(query == "InOrder")
            return 3;
        else if(query == "PostOrder")
            return 4;
    }

    std::string sub = query.substr(0, index_space);
    if(sub == "Insert")
        return 1;
    if(sub == "MakeRoot")
        return 0;

    return -1;
}

void process_query(Node* (&tree), std::string query){
    int choice = check_query(query);
    int index_space = query.find(' ');
    switch (choice)
    {
    case 1:{
        int index_space2 = query.find(' ', index_space+1);

        int first_num = stoi(query.substr(index_space+1, index_space2 - index_space - 1));
        int second_num = stoi(query.substr(index_space2 + 1, query.length() - index_space2 -1));
        Insert(tree, first_num, second_num);
        break;
    }
    case 2:{
        print_preoder(tree);
        std::cout << std::endl;
        break;
    }
    case 3:{
        print_inorder(tree);
        std::cout << std::endl;
        break;
    }
    case 4:{
        print_postorder(tree);
        std::cout << std::endl;
        break;
    }
    case 0:{
        int id = stoi(query.substr(index_space+1, query.length() - index_space - 1));
        tree = make_node(id);
        break;
    }
    default:
        break;
    }
}

int main(){
    Node *tree = NULL;
    std::string query;
    
    while(getline(std::cin, query)){
        if(query == "*")
            break;
        process_query(tree, query);
    }
    
    return 0;
}