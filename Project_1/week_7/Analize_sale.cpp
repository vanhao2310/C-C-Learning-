/*
    Problem: Week 7 - Analyze sales order of an e-commerce company
    author; Vu Van Hao - 20215572
*/
#include <bits/stdc++.h>
using namespace std;

struct Order{
    string customer_id;
    string product_id;
    int price;
    string shop_id;
    string timepoint;

    bool check(string custommerId, string shopID){
        return customer_id == custommerId && shop_id == shopID;
    }
};

int revenue_period_time[86404];
unordered_map<string, int> revenue_shop; // doanh so theo tung shop
unordered_map<string, int> revenue_cus_shop;
int total_revenue = 0;         // tong doanh so cac shop
int n = 0;

void revenue_period(){
    for(int i = 1; i < 86404; i++){
        revenue_period_time[i] += revenue_period_time[i-1];
    }
}

int convert_to_second(string time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));

    return h*3600 + m*60 + s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(revenue_period_time, 0, 86400);
    string customer, product, shopid, t;
    int price;
    while (1){
        cin >> customer;
        if (customer == "#")
            break;
        cin.ignore();
        cin >> product >> price >> shopid >> t;
        int second = convert_to_second(t);
        revenue_period_time[second] += price;
        total_revenue += price;
        string cus_shop_id = customer + shopid;
        if (revenue_shop.find(shopid) != revenue_shop.end()){
            revenue_shop[shopid] += price;
        }
        else{
            revenue_shop.insert({shopid, price});
        };

        if(revenue_cus_shop.find(cus_shop_id) != revenue_cus_shop.end()){
            revenue_cus_shop[cus_shop_id] += price;
        }else{
            revenue_cus_shop.insert({cus_shop_id, price});
        }
        ++n;
    }
    
    revenue_period();

    string q, cus_id, s_id, t1, t2;
    while(1){
        cin >> q;
        if(q == "#")
            break;

        if(q == "?total_consume_of_customer_shop"){
            cin.ignore(); cin >> cus_id;
            cin.ignore(); cin >> s_id;
            cout << revenue_cus_shop[cus_id + s_id] << "\n";
        }else if(q == "?total_revenue_in_period"){
            cin.ignore(); cin >> t1;
            cin.ignore(); cin >> t2;
            int time1 = convert_to_second(t1);
            int time2 = convert_to_second(t2);
            cout << revenue_period_time[time2] - revenue_period_time[time1-1] << "\n";

        }else if(q == "?revenue_of_shop"){
            cin.ignore(); cin >> s_id;
            cout << revenue_shop[s_id] << "\n";
        }else if(q == "?total_revenue"){
            cout << total_revenue << "\n";
        }else if(q == "?total_number_orders"){
            cout << n << "\n";
        }
    }
    return 0;
}
