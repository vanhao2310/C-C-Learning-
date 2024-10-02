/*
    Problem: Week 3 - Check Parenthesis
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>

bool check(char a, char b){
    if(a == '(' && b == ')')
        return true;
    if(a == '[' && b == ']')
        return true;
    if(a == '{' && b == '}')
        return true;
    
    return false;
}

bool check_parenthesis(std::string s){
    std::stack<char> tmp;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i]  == '[' || s[i] == '{')
            tmp.push(s[i]);

        if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(tmp.empty())   
                    return false;
                else{ 
                    if(check(tmp.top(), s[i]))
                        tmp.pop();
                    else 
                        return false;
                }
        }
    }
    if(tmp.empty())
        return true;
    else 
        return false;
}

int main(){
    std::string s;
    getline(std::cin, s);
    if(check_parenthesis(s))
        std::cout << 1 << std::endl;
    else 
        std::cout<< 0 << std::endl;
    return 0;
}