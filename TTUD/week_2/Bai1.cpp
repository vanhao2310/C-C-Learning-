#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    set<int> S;
    S.insert(a);
    if(S.insert(b).second){
        cout << b << " chua xuat hien trong set" << endl;
    }else{
        cout <<  b << "Da xuat hien trong set" << endl;
    }

    for(int a : S){
        cout << a << endl;
    }
   
    return 0;
}
