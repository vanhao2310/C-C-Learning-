//Vu Van Hao 20215572
/*
Bài tập 3: Tính tích có hướng của 2 vector¶
Một vector trong không gian 3 chiều được biểu diễn bằng tuple<double, double, double>. Hãy viết hàm Vector cross_product(Vector a, Vector b) 
tính tích có hướng của 2 vector. Trong đó Vector là kiểu dữ liệu được định nghĩa sẵn trong trình chấm như sau: using Vector = tuple<double, double, double>;
*/
#include<iostream>
#include<math.h>
#include<tuple>
using namespace std;
using Vector = tuple<double, double, double>;
Vector cross_product(Vector a, Vector b) {
    /*****************
    Vu Van Hao 20215572
    *****************/
    Vector rs;
    get<0>(rs) = get<1>(a)*get<2>(b) - get<1>(b)*get<2>(a); 
    get<1>(rs) = get<2>(a)*get<0>(b) - get<2>(b)*get<0>(a);
    get<2>(rs) = get<0>(a)*get<1>(b) - get<0>(b)*get<1>(a);
    return rs;
}
int main(){
    Vector a {1.2, 4, -0.5};
    Vector b {1.5, -2, 2.5};
    Vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
    return 0;
}
//Vu Van Hao 20215572