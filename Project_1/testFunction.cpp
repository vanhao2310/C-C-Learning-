#include<bits/stdc++.h>
using namespace std;
int main(){
    // std::string query;
    // getline(std::cin, query);
    // int index = query.find(' ', 17);
    // int first_num = stoi(query.substr(17, index-17));
    // std::cout << first_num << std::endl; 

    // int second_num = stoi(query.substr(index+1, query.length()-1));
    // std::cout << second_num;
    set<string> sss;
    sss.insert("ABC");
    sss.insert("ABD");
    sss.insert("AAC");
    for(auto a : sss)
        cout << a << endl;
    return 0;
}