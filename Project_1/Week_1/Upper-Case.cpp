//CPP 
/*
Problem: Convert a TEXT to Upper-Case
author: Vu Van Hao - 20215572
*/
#include <bits/stdc++.h> 

std::string upper_case(std::string text){
    int n = text.length();
    for(int i = 0; i < n; i++){
        text[i] = toupper(text[i]);
    }
    return text;
}

int main() 
{ 

    std::string text;
    std::vector<std::string> multy_line;
    while(getline(std::cin, text)){
        multy_line.push_back(upper_case(text));
    }
    for(std::string tmp : multy_line){
        std::cout << tmp << std::endl;
    }
    return 0;
}