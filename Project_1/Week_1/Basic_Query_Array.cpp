//C/C++ 
/*
    Problem: Basic queries on array
    author: Vu Van Hao - 20215572
*/
#include <bits/stdc++.h> 

int find_max(int arr[], int n){
    int max = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[max])
            max = i;
    }
    return arr[max];
}

int find_min(int arr[], int n){
    int min = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[min])
            min = i;
    }
    return arr[min];
}

int sum(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int find_max_segment(int arr[], int begin, int end){
    if(begin ==  end)   return arr[begin-1];
    else{
        int max = begin - 1;
        for(int i = begin; i <= end - 1; i++){
            if(arr[i] > arr[max])
                 max = i;
        }
        return arr[max];
    }
}

int check_query(std::string query){
    if(query == "sum")
        return 1;
    else if(query.length() == 8){
        if(query == "find-max")
            return 2;
        else if(query == "find-min")
            return 3;
    }else if(query.length() > 15)
        return 4;
    return 0;
}

void process(int arr[], int n, std::string query){
    int choice = check_query(query);
   switch (choice)
   {
    
    case 1:{
        std::cout<< sum(arr, n) << std::endl;
        break;
    }
    case 2:{
        std::cout<< find_max(arr, n) << std::endl;
        break;
    }
    case 3:{
        std::cout<< find_min(arr, n) << std::endl;
        break;
    }
    case 4:{
        int index = query.find(' ', 17);
        
        int first_num = stoi(query.substr(17, index-17));

        int second_num = stoi(query.substr(index + 1, query.length() - index - 1));
        std::cout << find_max_segment(arr, first_num, second_num) << std::endl;
        break;
    }
    default:
        break;
   }

}

void input_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
}

int main() 
{ 
    int n;
    std::cin >> n;
    int *arr = new int[n];
    input_array(arr, n);
    std::string query;
    std::vector<std::string>    list_query;
    while(getline(std::cin, query)){
        if(query == "***")
            break;
        list_query.push_back(query);
    }

    for(std::string q : list_query){
        process(arr, n, q);
    }


    delete[] arr;
    return 0;
}