//Vu Van Hao 20215572
/*
Bài tập 13: Đếm xâu con
Cho một xâu nhị phân độ dài n. Hãy viết chương trình đếm số lượng xâu con chứa số ký tự 0 và số ký tự 1 bằng nhau.
*/
#include<iostream>
#include<stack>
using namespace std;

#define MAX 1000000

string binary_string;   //xau nhi phan
int n;  //so luong bit cua xau
int count0[MAX];    //count0[i] so luong bit 0 tu vi tri 0 -> i
int count1[MAX];    //count1[i] so luong bit 1 tu vi tri 0 -> i
int count;      //dem so xau con thoa man
void input(){
    count = 0;
    cin >> binary_string;
    n = binary_string.length();

    //tinh so luong bit 0 va so luong bit 1 tu vi tri 0 ->  vi tri thu i
    if(binary_string[0]== '0'){
        count0[0] = 1;
        count1[0] = 0;
    }else{
        count0[0] = 0;
        count1[0] = 1;
    }
    for(int i = 1; i < n; i++){
        if(binary_string[i] == '0'){    //neu bit thu i la bit 0
            count0[i] = count0[i-1] + 1;    //so bit 0 tai vi tri thu i bang so bit 0 tai vi tri i-1 cong them 1
            count1[i] =  count1[i-1];       //so bit 1 o vi tri thu i bang so bit 1 o vi tri thu i-1
        }else{
            //neu bit thu i la bit 1
            count0[i] = count0[i-1];    //so bit 0 tai vi tri thu i bang so bit 0 tai vi tri thu i-1
            count1[i] = count1[i-1] + 1;    //so bit 1 tai vi tri thu i bang so bit 1 tai vi tri thu i-1 cong them 1
        }
    }
}

void count_sub_string(){
    for(int i = 0; i < n; i++){     
        for(int j = i+1; j < n; j+=2){  //duyet tung  bit trong xau va xet xau con tu vi tri i -> j
            if(i == 0){
                //bit dau tien chi can xet so luong bit 0 va 1 ke tu dau xau den vi tri j bang nhau thi count++ 
                if(count0[j]== count1[j])   count++;
            }else{
                int c0 = count0[j] - count0[i-1]; //so luong bit 0 tu vi tri i -> j
                int c1 = count1[j] - count1[i-1]; //so luong bit 1 tu vi tri i -> j
                if(c0 == c1)    
                    count++;    //neu so luong bit 0 va 1 bang nhau thi count++
            }
        }
    }
    cout<<"\nVu Van Hao - 20215572\n";
    cout << count;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    count_sub_string();
}
//Vu Van Hao 20215572