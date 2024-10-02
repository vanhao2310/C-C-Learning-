//Vu Van Hao 20215572ư
/*
Bài tập 11. Bảo vệ lâu đài
Bức tường bao quanh một lâu đài nọ được cấu thành từ n đoạn tường được đánh số từ 1 đến n. 
Quân giặc lên kế hoạch tấn công lâu đài bằng cách gửi ai tên giặc đánh vào đoạn tường thứ i. 
Để bảo vệ lâu đài có tất cả s lính.
*/
#include<iostream>
#include<queue>
using namespace std;

//du lieu input
struct data{
    int ai; //so quan dich tan cong buc tuong thu i
    int ki; //so quan dich co the tieu diet cua moi linh o buc tuong thu i
    data(int ai, int ki){
        this->ai = ai;
        this->ki = ki;
    }
};

//ham so sanh do uu tien cua cac buc tuong bi tan cong
struct compare{
    //sp sanh dua tren so luong dich tan cong vao buc tuong hoac so luong ke dich co the tieu diet boi 1 linh tai buc tuong do
    bool operator () (data a, data b){
        int ra, rb;
        ra =  a.ai <= a.ki ? a.ai : a.ki;
        rb = b.ai <= b.ki ? b.ai : b.ki;
        return ra < rb;
    }
};

int n;  //so buc tuong can bao ve
int s;  //so linh co 
int total_enemy, kill_enemy;
priority_queue<data, vector<data>, compare> Q;  //hang doi cac buc tuong voi do uu tien xet theo so ke dich tan vong vao
                                              //hoac kha nang phong thu o buc tuong do
//ham nhap du lieu vao
void input(){
    cin >> n >> s;  //nhap so nuc tuong va so linh
    kill_enemy = 0; //so ke dich bi tieu diet
    total_enemy = 0;    //tong so ke dich 
    for(int i = 0; i < n; i++){
        int tmp_ai, tmp_ki;
        cin >> tmp_ai >> tmp_ki;    //nhap vao so ke dich tan cong vao buc tuong i va kha nang phong thu o buc tuong do
        total_enemy += tmp_ai;
        Q.push(data(tmp_ai, tmp_ki));   
    }
}

//ham xu ly
void defend(){
    while(!Q.empty() && s > 0){     //moi lan dieu 1 quan linh den buc tuong uu tien cao nhat
        data wall_i = Q.top();  //lay ra buc tuong co do uu tien phong thu cao nhat
        Q.pop();
        if(wall_i.ai <= wall_i.ki){     //n
            kill_enemy += wall_i.ai;
        }else{
            int re_enemy = wall_i.ai - wall_i.ki;
            kill_enemy += wall_i.ki;
            Q.push(data(re_enemy, wall_i.ki));
        }
        s -= 1;
    }
    cout << total_enemy - kill_enemy;
}

int main(){
    input();
    defend();
    return 0;
}
//Vu Van Hao 20215572