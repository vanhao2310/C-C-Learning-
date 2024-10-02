/*
    Problem: Week 8 - Citizen Data Analysis
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

#define MAX 100004
#define MAX_DATE 1116372
//infor data:  <code>  <dat_of_birth>  <fathher_code>   <mother_code>  <is_alive>  <region_code>

int number_people = 0;      
int people_born_at[MAX_DATE];
int people_born_between[MAX_DATE];
unordered_map<string, pair<string, string>> relationship;
int unrelated_people = 0;

//date:  YYYY-MM-DD
int convert_date(string date){
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    return year*372 + month*31 + day;
}

int most_ancestor(string id){
    if(relationship[id].first == "0000000" & relationship[id].second == "0000000")
        return 0;
    else{
        return 1 + max(most_ancestor(relationship[id].first), most_ancestor(relationship[id].second));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(people_born_at, 0, sizeof(people_born_at));
    memset(people_born_between, 9, sizeof(people_born_between));
    string id, father_id, mother_id, date, region_id;
    char is_alive;
    while(1){
        cin >> id;
        if(id == "*")   break;

        cin >> date >> father_id >> mother_id >> is_alive >> region_id;
        ++number_people;
        int day = convert_date(date);
        ++people_born_at[day];
        relationship.insert({id, {father_id, mother_id}});
        if(father_id == "0000000" && mother_id == "0000000")
            ++unrelated_people;
    }

    people_born_between[0] = people_born_at[0];
    for(int i = 1; i < MAX_DATE; i++){
        people_born_between[i] = people_born_between[i-1] + people_born_at[i];
    }

    string q, d, code, d1, d2;
    while(1){
        cin >> q;
        if(q == "***")  break;

        if(q == "NUMBER_PEOPLE")
            cout << number_people << "\n";
        else if(q == "NUMBER_PEOPLE_BORN_AT"){
            cin >> d;
            int dd = convert_date(d);
            cout << people_born_at[dd] << "\n";
        }else if(q == "MOST_ALIVE_ANCESTOR"){
            cin >> code;
            cout << most_ancestor(code) << "\n";
        }else if(q == "NUMBER_PEOPLE_BORN_BETWEEN"){
            cin >> d1 >> d2;
            int dd1 = convert_date(d1);
            int dd2 = convert_date(d2);
            cout << people_born_between[dd2] - people_born_between[dd1-1] << "\n";
        }else if(q == "MAX_UNRELATED_PEOPLE")
            cout << unrelated_people << "\n";
    }
    return 0;
}
    