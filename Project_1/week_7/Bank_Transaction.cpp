/*
    Problem: Week 7 - Bank Transaction
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

#define MAX 100004

bool visited[MAX];
int id = 1;
int number_transaction = 0;
int total_money_transacction = 0;
set<string> sorted_account;     //sap xep 
unordered_map<string, int> total_money_from_account;    //tong so tien giao dich theo tai khoan 
unordered_map<string, int> id_account;  //
vector<int> adj[MAX];   //danh sach ke

void print_sorted_account(){
    for(auto a : sorted_account)
        cout << a << " ";
    cout << "\n";
}

bool dfs(int k, int id_s, int id_t){  //tham cac dinh tu dinh tu dinh s neu cho chu trinh bac k tu t quay lai duoc s return true
    if(k == 0){
        if(id_s == id_t)
            return true;
        else    
            return false;
    }

    for(int i : adj[id_s]){
        if(!visited[i]){
            visited[i] = true;
            if(dfs(k-1, i, id_t))
               return true;
            visited[i] = false;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string from_account, to_account, timepoint, atm;
    int money;
    while(1){
        cin >> from_account;
        if(from_account == "#")  break;
        cin >> to_account >> money >> timepoint >> atm;
        sorted_account.insert(from_account);
        sorted_account.insert(to_account);

        //cap nhat tien voi tai khoan nguon
        if(total_money_from_account.find(from_account) != total_money_from_account.end()){
            total_money_from_account[from_account] += money;
        }else{
            total_money_from_account.insert({from_account, money});
        }

        total_money_transacction += money;
        ++number_transaction;

        //ma hoa cac account bang id
        if(id_account[from_account] == 0){
            id_account[from_account] = id;
            ++id;
        }
        if(id_account[to_account] == 0){
            id_account[to_account] = id;
            ++id;
        }

        adj[id_account[from_account]].push_back(id_account[to_account]);  //them canh vao do thi
    }


    string q, from;
    int k;
    while(1){
        cin >> q;
        if(q == "#")
            break;
        if(q == "?number_transactions"){
            cout << number_transaction << "\n";
        }else if(q == "?total_money_transaction"){
            cout << total_money_transacction << "\n";
        }else if(q == "?list_sorted_accounts"){
            print_sorted_account();
        }else if(q == "?total_money_transaction_from"){
            cin >> from;
            cout << total_money_from_account[from] << "\n";
        }else if(q == "?inspect_cycle"){
            memset(visited, false, sizeof(visited));
            
            cin >> from >> k;
            int id_s = id_account[from];
            if(dfs(k, id_s, id_s))
                cout << 1 << "\n";
            else 
                cout << 0 << "\n";
        }
    }
}