//Vu Van Hao 20215572
/*
Bài tập 12. Lược đồ
Cho một lược đồ gồm n cột chữ nhật liên tiếp nhau có chiều rộng bằng 1 và chiều cao lần lượt là các số nguyên không âm 
h1,h2,…,hn. Hãy xác định hình chữ nhật có diện tích lớn nhất có thể tạo thành từ các cột liên tiếp.
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<long long> h; //mang danh sach chieu cao cua cac cot
int n; //so cot 

//ham nhap du lieu
void input(){
    cin >> n;   //nhap vao so cot
    h.push_back(-1);    //phan tu chan hai dau de luon tim duoc phan co chieu cao nho hon h[i]
    for(int i = 0; i < n; i++){
        long long tmp;   //chieu cao cot i
        cin >> tmp;
        h.push_back(tmp);   //them chieu cao cua cot vao
    }
    h.push_back(-1);    //phan tu chan hai dau
}

void max_area(){
    stack<int> st;

    vector<int> L(n+2); //luu vi tri gan nhat ben trai co chieu cao nho hon h[i]
    vector<int> R(n+2); //luu vi tri gan nhat ben phai co cbieu cao nho hon h[i]
 
    //tim phan tu gan nhat ben trai nho hon phan tu dang xet
    for(int i = n; i >= 0; i--){
        while(!st.empty() && h[i] < h[st.top()]){
            L[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    st.pop();   //loai bo phan tu chan 

    //tim phan tu ben phai gan nhat nho hon phan tu dang xet
    for(int i = 1; i <= n+1; i++){
        while( !st.empty() && (h[i] < h[st.top()]) ){
            //neu cot i thap hon cot o dau stack thi gan R[st.top()] = i
            R[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    st.pop();   //bo phan tu chan ra khoi stack

    long long max = 0;
    for(int i = 1; i <= n; i++){
        long long area = (R[i] - L[i] - 1) * h[i];
        if(max < area)  max = area;
    }
    cout<<endl;
    cout<<"Vu Van Hao - 20215572\n";
    cout << max;
}

int main(){
    input();
    max_area();
    return 0;
}
//Vu Van Hao 20215572