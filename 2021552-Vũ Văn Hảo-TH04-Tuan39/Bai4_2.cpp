//Vu Van Hao 20215572
/*
Bài tập 2: Tính diện tích tam giác
Một điểm trong không gian 2 chiều được biểu diễn bằng pair. Hãy viết hàm double area(Point a, Point b, Point c) tính diện tích tam giác theo tọa độ 3 đỉnh. 
Trong đó, Point là kiểu được định nghĩa sẵn trong trình chấm như sau: using Point = pair<double, double>;
*/
#include<iostream>
#include<utility>
#include<math.h>
using namespace std;
using Point = std::pair<double, double>;

double area(Point a, Point b, Point c) {

   //S = 1/2|(xC-xA)(yB-yC) - (xB-xA)(yC-yA)|
   return 1.0/2 * fabs((c.first - a.first)*(b.second - a.second) - (b.first - a.first)*(c.second - a.second));

}

int main(){
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
}
//Vu Van Hao 20215572
