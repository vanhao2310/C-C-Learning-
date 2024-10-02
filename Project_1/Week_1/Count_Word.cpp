/*
    Problem: Count words
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>

int count_word(std::string line){
    int count = 0;
    int i = 0;
    int length = line.length();
    while(isspace(line[i]) && i < length)
        i++;
    if(i < length)
        count = 1;
    
    while(i < length - 1){
        if(isspace(line[i]) && !isspace(line[i+1]))
            count++;
        i++;
    }
    return count;
}


int main(){
    std::string line;
    std::vector<std::string> text;
    int count = 0;
    while(getline(std::cin, line)){
        count += count_word(line);
    }
    std::cout << count;

}