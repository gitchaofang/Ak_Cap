#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<set>
class Solution{
    public:
        bool check(const std::vector<std::vector<int>>&,int,int,int,std::vector<std::vector<double>>&);
        int seek(const std::vector<std::vector<int>>&);
};
bool Solution::check(const std::vector<std::vector<int>>& v,int i,int j, int k, std::vector<std::vector<double>>& sp){
    if(sp[i][j] == -2){
        if(v[i][0] == v[j][0]) sp[i][j] = -1;
         else sp[i][j] = double(abs(v[i][1] - v[j][1]))/double(abs(v[i][0] - v[j][0]));  
    }
    if(sp[i][k] == -2){
        if(v[i][0] == v[k][0]) sp[i][k] = -1;
        else sp[i][k] = double(abs(v[i][1] - v[k][1]))/double(abs(v[i][0] - v[k][0]));
    }
    return sp[i][j] == sp[i][k];
}
int Solution::seek(const std::vector<std::vector<int>>& input){
    int n = input.size();
    std::vector<std::vector<double>>sp(n,std::vector<double>(n,-2));
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            for(int k=j+1; k<n; ++k){
                bool sig = check(input,i,j,k,sp);
                if(sig == true) return 1;
            }
        }
    }
    return 0;
}

int main(){
    std::vector<std::vector<int>>input = {{-1,-1},{0,0},{1,2}};
    Solution cl;
    int res = cl.seek(input);
    std::cout << res;
    return 0;
}
