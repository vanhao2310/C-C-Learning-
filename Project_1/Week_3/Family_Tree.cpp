/*
    Problem: Week 3 - Family Tree
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    string name;
    string parent_name;
    vector<Node*> childrens;
};

Node* make_node(string name, string parent_name){
    Node* newnode = new(Node);
    newnode->name = name;
    newnode->parent_name = parent_name;
    return newnode;
}

// //ktra nguoi do da co trong cay gia pha hay chua.
// bool check(Node* f_tree, string name){
//     if(f_tree->name == name)
//         return true;
//     else if(f_tree->childrens.empty())
//         return false;
//     else{
//         for(Node* tmp : (f_tree->childrens) ){
//             if(check(tmp, name))
//                 return true;
//         }
//     }
//     return false;
// }

//kiem tra nguoi do da duoc liet ke trong danh sach people chua
bool check(vector<Node*> peoples, string name){
    for(Node* tmp : peoples){
        if(tmp->name == name)
            return true;
    }
    return false;
}

//tao cay pha he tu danh sach peole
void make_family_tree(vector<Node*> (&peoples)){
    for(Node*  p : peoples)
    {
        for(Node* c : peoples){
            //neu c co cha la p thi them c vao danh sach childrens cua p
            if(c->parent_name == p->name){
                p->childrens.push_back(c);
           }
        }
    }
}

//ham tra ve so luong con chau cua node nhan vao
int descendants(Node* people){
    //neu con tro null hoac danh sach con rong tra ve 0
    if(people == NULL || people->childrens.empty())
        return 0;

    int count = people->childrens.size();   // so con cua p
    for(Node* tmp : people->childrens){
        count += descendants(tmp);  //cong them so con cua con p
    }
    return count;
}

//ham tra ve so the he con chau cua node dua vao
int generation(Node* people){
    //neu danh sach con rong thi so the he con chau = 0
    if(people->childrens.empty())
        return 0;
    else{
        int max_children_generation = 0;    //so the he con chau lon nhat trong cac con
        for(Node* child : people->childrens){
            int count = generation(child);
            if(count > max_children_generation)
                max_children_generation = count;
        }
        return max_children_generation + 1;
    }
}

int main(){

    vector<Node*> people;
    string s;
    while(getline(cin, s)){
        if(s == "***")
            break;
        int index_space = s.find(' ');
        string child = s.substr(0, index_space);
        string parent = s.substr(index_space + 1, s.length() - index_space - 1);
        people.push_back(make_node(child, parent)); //them thong tin nguoi vao danh sach people
    }

    //tim to tien cua ca cay va them vao people
    //neu ten cha nguoi do khong co trong danh sach people thi nguoi do la to tien cua cay gia pha
    for(Node* tmp : people){
        if(!check(people, tmp->parent_name)){
            people.push_back(make_node(tmp->parent_name, " "));
            break;
        }
    }
    
    //tao cay gia pha tu danh sach people vua tao ben tren
    make_family_tree(people);

    while(getline(cin, s)){
        if(s == "***")
            break;
        else{
            int index_space = s.find(' ');
            string func = s.substr(0, index_space);
            string name = s.substr(index_space + 1, s.length() - index_space - 1);
            Node* node = NULL;
            for(Node* tmp : people)
                if(tmp->name == name)
                    node = tmp;
            if(func == "generation")
                cout << generation(node) << endl;
            else if(func == "descendants")
                cout << descendants(node) << endl;

        }
    }
}