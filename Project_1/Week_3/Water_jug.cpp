/*
    Problem: Week 3 - WATER JUGS
    author: Vu Van Hao - 20215572
*/

#include<bits/stdc++.h>
using namespace std;

//luong nuoc o moi binh
typedef pair<int, int> p; 

void BFSSolution(int first_jug, int second_jug, int target){
    map<p, int> check;    //danh dau cac truong hop da xuat hien
    map<p, p> prev;     // lien ket voi truong hop truoc do

    queue<p> q;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        if(check[u] == 1)
            continue;
        
        check[u] = 1;   //danh dau truong hop nay da thuc hien 1 lan roi

        //neu da tim duoc luong nuoc mong muon
        if(u.first == target || u.second == target){
            int step = 0;
            //tim so buoc can de dat duoc muc nuoc mong muon
            while(!(u.first == 0 && u.second == 0)){
                u = prev[u];
                step++;
            }
            cout << step;
            return;
        }
        //truong hop do day binh 1
        if(check[{first_jug, u.second}] != 1){
            q.push(make_pair(first_jug, u.second));
            prev[{first_jug, u.second}] = u;
        }

        //truong hop do day binh 2
        if(check[{u.first, second_jug}] != 1){
            q.push(make_pair(u.first, second_jug));
            prev[{u.first, second_jug}] = u;
        }

        //truong hop do tu binh 1 -> 2
        int d = second_jug - u.second;  //khoang trong con lai trong binh 2
        if(d > u.first){
            int sum =  u.second + u.first;
            if(check[{0, sum}] != 1){
                q.push(make_pair(0, sum));
                prev[{0, sum}] = u;
            }
        }else{
            int c = u.first - d;
            if(check[{c, second_jug}] != 1){
                q.push(make_pair(c, second_jug));
                prev[{c, second_jug}] = u;
            }
        }

        //truong hop do tu binh 2 -> 1
        d = first_jug - u.first;    //khoang trong con lai trong binh 1
        if(d > u.second){
            int sum = u.second + u.first;;
            if(check[{sum, 0}] != 1){
                q.push(make_pair(sum, 0));
                prev[{sum, 0}] = u;
            }
        }else{
            int c = u.second - d;
            if(check[{first_jug, c}] != 1){
                q.push(make_pair(first_jug, c));
                prev[{first_jug, c}] = u;
            }
        }

        //truong hop do nuoc trong binh 1 di
        if(check[{0, u.second}] != 1){
            q.push(make_pair(0, u.second));
            prev[{0, u.second}]  = u;
        }

        //truong hop do nuoc trong binh 2 di
        if(check[{u.first, 0}] != 1){
            q.push(make_pair(u.first, 0));
            prev[{u.first, 0}] = u;
        }
    }
}

int main(){
    int first_jug, second_jug, target;
    cin >> first_jug >> second_jug >> target;
    BFSSolution(first_jug, second_jug, target);
    return 0;
}