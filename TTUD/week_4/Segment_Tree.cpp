#include<bits/stdc++.h>
using namespace std;

int arr[1000004];
int n, m;
int maxVal[1000004];

//xay dung cay phan doan dua tren arr
void buildSegmentTree(int id, int left, int right){
    if(left == right){
        maxVal[id] = arr[left];
        return;
    }
    //xay dung cay con trai va phai
    int mid = (left+right)/2;
    buildSegmentTree(2*id, left, mid);
    buildSegmentTree(2*id+1, mid+1, right);
    maxVal[id] = max(maxVal[2*id], maxVal[2*id+1]);
}

int getMaxFromNode(int id, int left, int right, int i, int j){
    if((i > right) || (j < left))   //out of range
        return -1;
    if((i <= left) && (j >= right)){
        return maxVal[id];
    }

    int mid = (left + right)/2;
    int maxleft = getMaxFromNode(2*id, left, mid, i, j);
    int maxright = getMaxFromNode(2*id+1, mid+1, right, i, j);
    return max(maxleft, maxright);
}
int getMax(int i, int j){
    return getMaxFromNode(1, 1, n, i, j);
}

void updateFromNode(int id, int left, int right, int index, int value){
    if(left > right)
        return;

    if((index < left) || (index > right))   //index khong nam trong phan can duoc update
        return;

    if(left == right){  //nut la can update
        maxVal[id] = value;
        return;
    }

    int mid = (left+right)/2;
    updateFromNode(2*id, left, mid, index, value);  //cap nhat maxvalue cua cay con trai
    updateFromNode(2*id+1, mid+1, right, index, value);  //cap nhat maxvalue cua cay con phai

    //cap nhat max value nut hien tai
    maxVal[id] = max(maxVal[2*id], maxVal[2*id+1]);
}

void update(int index, int value){
    arr[index] = value;
    updateFromNode(1, 1, n, index, value);
}


int main(){
    int l, r;
    string query;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    buildSegmentTree(1, 1, n);
    cin >> m;
    while(m--){
        cin.ignore();
        cin >> query;
        if(query == "get-max"){
            cin >> l >> r;
            cout << getMax(l, r) << endl;
        }else if(query == "update"){
            cin >> l >> r;
            update(l, r);
        }
    }
    return 0;
}
