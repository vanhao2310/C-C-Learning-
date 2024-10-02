//C/C++ 
/*
    Problem: Convert hh:mm:ss to seconds
    author: Vu Van Hao - 20215572
*/
#include <bits/stdc++.h> 

bool check_format(std::string time){
    if(time.length() != 8)
        return false;
    if(time[2] != ':' && time[5] != ':')
        return false;
    int hour, minute, second;
    try{
        hour = stoi(time.substr(0, 2));
        if(hour < 0 || hour > 24)
            throw std::exception();
    }catch(...){
        return false;
    }

    try{
        minute = stoi(time.substr(3, 2));
        if(minute < 0 ||minute > 59)
            throw new std::exception;
    }catch(...){
        return false;
    }

    try{
        second = stoi(time.substr(6, 2));
        if(second < 0 || second > 59)
            throw new std::exception;
    }catch(...){
        return false;
    }

    return true;
}

int to_second(std::string time){
    int hour, minute, second;
    hour = stoi(time.substr(0, 2));
    minute = stoi(time.substr(3, 2));
    second = stoi(time.substr(6, 2));
    return hour*3600 + minute *60 + second;
}

int main() 
{ 
    std::string time;
    getline(std::cin, time);
    if(check_format(time))
        std::cout << to_second(time) << std::endl;
    else 
        std::cout << "INCORRECT" << std::endl;
    
    return 0;
}