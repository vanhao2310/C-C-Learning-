//Vu Van Hao 20215572
/*
Bài 4.4. Cho hai std::vector, hãy xóa hết các phần tử chẵn, sắp xếp giảm dần các số trong cả 2 vector và trộn lại thành một 
vector cũng được sắp xếp giảm dần.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    /*****************
    Vu Van Hao 20215572
    *****************/
    for(unsigned int i = 0; i < a.size(); i++){
        if(a[i]%2 == 0){
            a.erase(a.begin() + i);    //delete a[i] if a[i] is even
            i--;
        }
    }
    
}

void sort_decrease(vector<int> &a) {
    /*****************
    Vu Van Hao 20215572
    *****************/
    std::sort(a.begin(), a.end(), [](int a, int b){
        return a > b;
    });
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    /*****************
    Vu Van Hao 20215572
    *****************/
    vector<int> rs(a.size() + b.size());
    std::merge(a.begin(), a.end(), b.begin(), b.end(), rs.begin(), [](int a, int b){
        return a > b;
    });
    return rs;
}

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
//Vu Van Hao 20215572