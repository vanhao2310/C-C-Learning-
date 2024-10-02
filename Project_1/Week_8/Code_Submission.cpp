/*
    Problem: Week 8 - Analyze Code Submission of a Programming Contest
    author: Vu Van Hao  - 20215572
*/
#include<bits/stdc++.h>
using namespace std;

#define MAX 100004
#define MAX_SECOND 86400    //so giay trong 1 ngay


int total_submission = 0;
int number_error_submission = 0;
unordered_map<string, int> user_problem;    //kiem tra user da lam problem do chua
unordered_map<string, int> error_sumission_user;    //so luong submit loi cua user
unordered_map<string, int> point_of_user;   //so diem cua user
int submission_period[MAX_SECOND];  //  so luong submit trong khoang thoi gian tu 0 -> t

int convert_to_second(string time){ //  HH:MM:SS
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    return h*3600 + m*60 + s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(&submission_period, 0, sizeof(submission_period));
    string user_id, problem_id, timepoint, status;
    int point;
    while(1){
        cin >> user_id;
        if(user_id == "#")
            break;
        cin >> problem_id >> timepoint >> status >> point;
        
        ++total_submission;

        if(status == "ERR"){
            ++number_error_submission;
            error_sumission_user[user_id] += 1;
        }

        //kiem tra xem user da tung lam problem nay hay chua
        string u_p = user_id + problem_id;
        if(user_problem[u_p] == 0){        //neu chua tung lam problem nay
            user_problem[u_p] = point;
            point_of_user[user_id] += point;
        }else{
            //neu da tung lam roi va diem dat duoc lon hon thi cap nhat lai diem
            if(point > user_problem[u_p]){
                point_of_user[user_id] = point_of_user[user_id] - user_problem[u_p] + point;
                user_problem[u_p] = point;
            }
        }
        int second = convert_to_second(timepoint);
        //tang so bai submit trong thoi gian second
        ++submission_period[second];
    }

    //thiet lap so submit trong khoang thoi gian
    for(int i = 1; i <= MAX_SECOND; ++i){
        submission_period[i] += submission_period[i-1];
    }

    string query, user, time1, time2;
    while(1){
        cin >> query;
        if(query == "#")
            break;
 
        if(query == "?total_number_submissions"){
            cout << total_submission << "\n";
        }else if(query == "?number_error_submision"){
            cout << number_error_submission << "\n";
        }else if(query == "?number_error_submision_of_user"){
            cin >> user;
            cout << error_sumission_user[user] << "\n";
        }else if(query == "?total_point_of_user"){
            cin >> user;
            cout << point_of_user[user] << "\n";
        }else if(query == "?number_submission_period"){
            cin >> time1 >> time2;
            int t1 = convert_to_second(time1);
            int t2 = convert_to_second(time2);
            cout << submission_period[t2] - submission_period[t1-1] << "\n";
        }
    }
}