//Vu Van Hao 20215572
/*
Bài tập 7: Viết các hàm thực hiện các phép giao và hợp của hai tập hợp được biểu diễn bằng set.
*/
#include<iostream>
#include<set>
using namespace std;
template<class T>
set<T> set_union(const std::set<T> &a, const std::set<T> &b) {
    /*****************
    Vu Van Hao 20215572
    *****************/
    set<T> rs = a;  //copy set a vao set result
    rs.insert(b.begin(), b.end());  //copy set b vao set result
    return rs;
}

template<class T>
set<T> set_intersection(const std::set<T> &a, const std::set<T> &b) {
    /*****************
    Vu Van Hao 20215572
    *****************/
    set<T> rs;
    for(auto x : a){
        if(b.count(x))  //neu trong set b co phan tu x trong set a thi insert x vao set rs
            rs.insert(x);
    }
    return rs;
}

template<class T>
void print_set(const std::set<T> &a) {
    for (const T &x : a) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main(){
    set<int> a = {1, 2, 3, 5, 7};
    set<int> b = {2, 4, 5, 6, 9};
    set<int> c = set_union(a, b);
    set<int> d = set_intersection(a, b);
    
    cout << "Union: "; print_set(c);
    cout << "Intersection: "; print_set(d);
    return 0;
}
//Vu Van Hao 20215572