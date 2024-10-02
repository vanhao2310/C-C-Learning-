/*
Problem: So sánh chênh lệch giá điện theo đề xuất mới của EVN
author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>

//calculate electric price with six levels
int six_levels(int electric_Count){
    if(electric_Count <= 50)
        return electric_Count * 1728;
    else if(electric_Count <= 100)
        return 50*1728 + (electric_Count - 50) * 1786;
    else if(electric_Count <= 200)
        return 50*(1728 + 1786) + (electric_Count - 100)*2074;
    else if(electric_Count <= 300)
        return 50*(1728 + 1.786) + 100*2074 + (electric_Count - 200)*2612;
    else if(electric_Count <= 400)
        return 50*(1728 + 1786) + 100*2074 + 100*2612 + (electric_Count - 300)*2919;
    else 
        return 50*(1728 + 1786) + 100*2074 + 100*2612 + 100*2919 + (electric_Count - 400)*3015;
}


//calculate electric price with five levels
int five_levels(int electric_Count){
    if(electric_Count <= 100)
        return electric_Count * 1728;
    else if(electric_Count <= 200)
        return 100*1728 + (electric_Count - 100)*2074;
    else if(electric_Count <= 400)
        return 100*(1728 + 2074) + (electric_Count - 200)*2612;
    else if(electric_Count <= 700)
        return 100*(1728 + 2074) + 200*2612 + (electric_Count - 400)*3111;
    else   
        return 100*(1728 + 2074) + 200*2612 + 300*3111 + (electric_Count - 700)*3457;
}


int main(){
    int electric_count;
    std::cin >> electric_count;
    float diff = 1.1 * (five_levels(electric_count) - six_levels(electric_count));
    std::cout << std::fixed << std::setprecision(2) << diff << std::endl;
    return 0;
}