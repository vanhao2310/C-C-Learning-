//C/C++ 
/*
    Problem: Solve degree-2 polynomial equation
    author: Vu Van Hao - 20215572
*/
#include <bits/stdc++.h> 

void solution(int a, int b, int c){
    double delta = b*b - 4*a*c;
    if(delta < 0)
        
        std::cout << "NO SOLUTION" << std::endl;
    
    else if(delta > 0){
        
        double x1 = (b*(-1) - sqrt(delta)) / (2*a);
        double x2 = (b*(-1) + sqrt(delta)) / (2*a);
        std::cout << std::fixed << std::setprecision(2) << x1 << " " << x2 << std::endl;
    
    }else if(delta == 0){
        
        double x = (-1*b) / (2*a);
        std::cout << std::fixed << std::setprecision(2) << x << std::endl;

    }
}

int main() 
{ 
    int a, b, c;
    std::cin >> a >> b >> c;
    solution(a, b, c);
    return 0;
}