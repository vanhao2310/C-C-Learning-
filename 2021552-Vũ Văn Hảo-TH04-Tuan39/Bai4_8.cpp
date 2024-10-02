#include<iostream>
#include<map>
using namespace std;
//Vu Van Hao 20215572
/*
Bài tập 8:
Viết các hàm thực hiện các phép giao và hợp của hai tập hợp mờ được biểu diễn bằng map.
Trong đó mỗi phần tử được gán cho một số thực trong đoạn [0..1] biểu thị độ thuộc của phần tử trong tập hợp, 
với độ thuộc bằng 1 nghĩa là phần tử chắc chắn thuộc vào tập hợp và ngược lại độ thuộc bằng 0 nghĩa là phần tử 
chắc chắn không thuộc trong tập hợp.
Phép giao và hợp của 2 tập hợp được thực hiện trên các cặp phần tử bằng nhau của 2 tập hợp, 
với độ thuộc mới được tính bằng phép toán min và max của hai độ thuộc.
*/
template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b){
    /*******************
    Vu Van Hao 20215572  
    *******************/
   map<T, double> rs = a;   //coppy cac phan tu trong map a vao map result
   for(const auto x : b){
        if(rs.count(x.first)){  /*kiem tra tung phan tu trong map b 
                                neu phan tu do co key da xuat hien trong result thi cap nhat do thuoc*/
            rs[x.first] = rs[x.first] < x.second ? x.second : rs[x.first];  //voi hop thi do thuoc la max
        }else{
            //neu phan tu chua xuat hien trong result thi insert vao result
            rs.insert(x);
        }
   }
   return rs;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b){
    /*******************
    Vu Van Hao 20215572  
    *******************/
    map<T, double> rs;
    for(const auto x : a){    /*duyet qua cac phan tu trong map a neu phan tu do co key cung xuat hien trong map b 
                        thi them phan tu do vao trong result voi do thuoc min*/
        if(b.count(x.first))
            rs[x.first] = x.second < (b.find(x.first)) -> second ? x.second : (b.find(x.first)) -> second;
                            //khong dung dc b[x.first] do b khai bao sonst ma [] khong phai phuong thuc const
                            //can su dung find tra ve iterator tro den phan tu do 
        
    }
    return rs;
}

template<class T>
void print_fuzzy_set(const map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    cout << endl;
}

int main(){
    map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    cout << "A = "; print_fuzzy_set(a);
    cout << "B = "; print_fuzzy_set(b);
    map<int, double> c = fuzzy_set_union(a, b);
    map<int, double> d = fuzzy_set_intersection(a, b);
    cout << "Union: "; print_fuzzy_set(c);
    cout << "Intersection: "; print_fuzzy_set(d);
    return 0;
}
//Vu Van Hao 20215572