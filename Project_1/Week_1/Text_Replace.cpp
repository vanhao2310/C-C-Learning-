/*
    Problem: Text Replacement
    author: Vu Van Hao - 20215572
*/

#include<bits/stdc++.h>
int main(){
    std::string P1, P2, text;
    getline(std::cin, P1);
    getline(std::cin, P2);
    getline(std::cin, text);

    int index;
    while((index = text.find(P1)) != std::string::npos)
        text.replace(index, P1.length(), P2);
        
    std::cout << text;
    return 0;
}