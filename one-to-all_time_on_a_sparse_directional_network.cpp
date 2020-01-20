#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<set>
#include<unordered_map>
#include<string>
#include<queue>
#include<climits>
class Solution{
    public:
        int network_delivery_time(const int&, const std::vector<std::vector<std::string>>&);
};

int Solution::network_delivery_time(const int& orig, const std::vector<std::vector<std::string>>& matrix){
    int n = matrix.size();
    if(n == 0) return -1;
    std::vector<int> dp(n,INT_MAX);
    std::unordered_map<int,std::vector<std::pair<int,int>>> connect;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(matrix[i][j] == "None") continue;
            connect[i].push_back(std::make_pair(j,std::stoi(matrix[i][j])));
        }
    }

    std::queue<std::pair<int,int>> q({{orig,0}});
    dp[orig] = 0;
    while(!q.empty()){
        std::pair<int,int>p = q.front();
        q.pop();
        std::vector<std::pair<int,int>> v = connect[p.first];
        for(const std::pair<int,int>& tp: v){
            int pos = tp.first;
            int t = tp.second + p.second;
            if(t >= dp[pos]) continue;
            dp[pos] = t;
            q.push({pos,t});
        }
    }
    int res = INT_MIN;
    for(const int& d: dp){
        if(d == INT_MAX) return -1;
        res = std::max(d,res);
    }
    for(int d: dp) std::cout << d <<' ';
    return res;
}

int main(){
    std::vector<std::vector<std::string>>input(4,std::vector<std::string>(4,"None"));
    input[0][2] = "122";
    input[2][0] = "341";
    input[1][3] = "50";
    input[2][3] = "205";
    input[3][0] = "456";
    input[3][2] = "186"; 
    Solution cl;
    int res = cl.network_delivery_time(1,input);
    std::cout << res;
    return 0;
}


