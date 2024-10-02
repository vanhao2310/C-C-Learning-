//CPP 
/*
Problem: Extract Year, Month, Date from a String YYYY-MM-DD
author: Vu Van Hao - 20215572
*/
#include <bits/stdc++.h> 

//check format string date      YYYY-MM-YY
void date_format(std::string date){
    
    if(date.length() != 10){
        std::cout << "INCORRECT";
        return;
    }
    if(date[4] != '-' || date[7] != '-'){
        std::cout << "INCORRECT";
        return;
    }

    int year, month, day;
    //check YYYY
    try{
        std::string y = date.substr(0, 4);
        year = std::stoi(y);
    }catch(...){
        std::cout << "INCORRECT";
        return;
    }

    //check month
    try{
        std::string m = date.substr(5, 2);
        month = std::stoi(m);
        if(month < 1 || month > 12)
            throw std::exception();
    }catch(...){
        std::cout << "INCORRECT";
        return;
    }

    //check day
    try{
        std::string d = date.substr(8, 2);
        day = std::stoi(d);
        if(day < 1 || day > 31)
            throw std::exception();
    }catch(...){
        std::cout << "INCORRECT";
        return;
    }

    //output
    std::cout << year << " " << month << " " << day << std::endl;
}

int main() 
{ 
    std::string date;
    getline(std::cin, date);
    date_format(date);
}