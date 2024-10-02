#include<iostream>
#include<fstream>
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int age;
    std::cin >> age;
    std::cout << "You are " << age << " years old" << std::endl;
    return 0;
}