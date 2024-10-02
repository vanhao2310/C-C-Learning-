//Vu Van Hao 20215572
/*
Bài tập 10: Search Engine
Xây dựng một máy tìm kiếm (search engine) đơn giản. Cho N văn bản và Q truy vấn. 
Với mỗi truy vấn, cần trả về văn bản khớp với truy vấn đó nhất.
Sử dụng phương pháp tính điểm TF-IDF:
*/
#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<algorithm>
using namespace std;
vector<vector<string>> vector_chain;//luu mang cac chuoi
vector<vector<string>> vector_test;
int n,q;
vector<int> maxf;
map<string,int> df ;//df[w]: so van ban chua tu ws
map<pair<string,int>,int>fe;//tu w xuat hien trong vb d k lan

vector<string> split_string(string s){
    vector<string> result;
    string tmp;
    for(char c : s){
        if(c == ' ' || c == ','){
            if(!tmp.empty()){
                result.push_back(tmp);
                tmp.clear();
            }
        }
        else tmp += c;
    }
    if(!tmp.empty())result.push_back(tmp);
    return result;
}
void input(){
    cin>>n;
    vector<string>chain;
    vector<string>test;
    string tmp;
    getline(cin,tmp);
    for(int i = 0;i<n;i++){
        getline(cin,tmp);
        vector<string> element = split_string(tmp);
        vector_chain.push_back(element);
    }
    cin>>q;
    getline(cin,tmp);
    for(int i = 0;i<q;i++){
        getline(cin,tmp);
        test.push_back(tmp);
        vector<string>element = split_string(tmp);
        vector_test.push_back(element);
    }
    
    
}
//Tinh tan xuat cua tu xuat hien nhieu nhat
void pre_processing(){
    for(vector<string> c:vector_chain){
        map<string,int> m;//word,tan xuat 
        int f = -1;
        for(string s: c){
            map<string,int> ::iterator ite = m.find(s);
            if(ite==m.end()){
                m.insert({s,1});
            }
            else ite->second +=1;
            f = max(f,m[s]);
        }
        maxf.push_back(f);

    }
}
//tinh tan xuat xuat hien tu t trong van ban d
int f(string t,int d){
    
    if(fe.find({t,d})!=fe.end()){
        return fe[{t,d}];
    }
    else{
        int result = 0;
        vector<string> s = vector_chain[d];
        for(string tmp : s){
            if(tmp == t)result++;
        }
        fe.insert({{t,d},result});
        return result;
    }

}
//tinh so van ban chua tu t
int d(string t){
    if(df.find(t)!=df.end()){
        return df[t];
    }
    else{
        int count = 0;
        for(vector<string> tmp:vector_chain){
            for(string c:tmp){
                if(c==t){
                    count++;
                    break;
                }
            }
        }
        df.insert({t,count});
        return count;
    }

}
//search engine
int search_engine(vector<string> list_word){
    double score_max = -1000;
    int predict_label;
    
    for(int i = 0;i<n;i++){
        vector<string> tmp = vector_chain[i];
        double score = 0;
        int maxfd = maxf[i];
        for(string c : list_word){
          if(find(tmp.begin(),tmp.end(),c)==tmp.end()){
            continue;
          }else{
              int ftd = f(c,i);
            int dft = d(c);
            double tf = 0.5+0.5*ftd/(double)maxfd;
            double idf = log2((double)n/dft);
            score+=tf*idf;
          }
        }
        if(score>score_max){
            score_max = score;
            predict_label = i+1;
        }
    }
    return predict_label;

}
int main(){
    input();
    pre_processing();
    cout << "Vu Van Hao - 20215572";
    for(vector<string> s:vector_test){
        cout<<search_engine(s)<<endl;
    }
}
//Vu Van Hao 20215572