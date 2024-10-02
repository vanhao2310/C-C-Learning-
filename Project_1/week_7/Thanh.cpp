#include <iostream>
#include <map>
#include <vector>

#define DAY_BY_SECOND 86404
using namespace std;

int countOrder;
int totalRevenue;
map<int, int> revenueOfShop;
map<int, map<int, int>> getFromCustomer;
int revenueByTime[DAY_BY_SECOND];

map<string, int> shopMap, customerMap;
int sttShop, sttCustomer;

int convertToSecond(string timePoint) {
    int hh = stoi(timePoint.substr(0, 2));
    int mm = stoi(timePoint.substr(3, 2));
    int ss = stoi(timePoint.substr(6, 2));
    return hh * 3600 + mm * 60 + ss;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string customerID;
    string productID;
    int price;
    string shopID;
    string timePoint;
    while(1) {
        cin >> customerID;
        if (customerID == "#") break;
        cin >> productID >> price >> shopID >> timePoint;
        if (shopMap[shopID] == 0) {
            sttShop++;
            shopMap[shopID] = sttShop;
        }
        if (customerMap[customerID] == 0) {
            sttCustomer++;
            customerMap[customerID] = sttCustomer;
        }

        countOrder++;
        totalRevenue += price;
        revenueOfShop[shopMap[shopID]] += price;
        getFromCustomer[shopMap[shopID]][customerMap[customerID]] += price;
        int t = convertToSecond(timePoint);
        revenueByTime[t] += price;
    }

    // calculate revenue from 00:00:00 to each time point
    for (int i = 1; i < DAY_BY_SECOND; i++) {
        revenueByTime[i] += revenueByTime[i - 1];
    }
    string query;
    while(1) {
        cin >> query;
        if (query == "#") break;

        if (query == "?total_number_orders") 
            cout << countOrder << '\n';
        else if (query == "?total_revenue")
            cout << totalRevenue << '\n';
        else if (query == "?revenue_of_shop") {
            cin >> shopID;
            sttShop = shopMap[shopID];
            cout << revenueOfShop[sttShop] << '\n';
        }
        else if (query == "?total_consume_of_customer_shop") {
            cin >> customerID >> shopID;
            sttShop = shopMap[shopID];
            sttCustomer = customerMap[customerID];
            cout << getFromCustomer[sttShop][sttCustomer] << '\n';
        }
        else if (query == "?total_revenue_in_period") {
            string fromTime, toTime;
            cin >> fromTime >> toTime;
            int ft = convertToSecond(fromTime);
            int tt = convertToSecond(toTime);
            cout << revenueByTime[tt] - revenueByTime[ft - 1] << '\n';

        }
    }
}