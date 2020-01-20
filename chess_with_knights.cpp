#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
class Solution{
    public:
        std::pair<int,int> chess(const int, const std::pair<int,int>, const std::pair<int,int>, const bool);
};

std::pair<int,int> Solution::chess(const int n, const std::pair<int,int> white, const std::pair<int,int> black, const bool sig){
    std::vector<std::vector<int>>dp(n,std::vector<int>(n,0));
    dp[white.first][white.second] = 1;
    dp[black.first][black.second] = 2;
    std::queue<int> q1({white.first * n + white.second});
    std::queue<int> q2({black.first * n + black.second});
    std::vector<std::pair<int,int>> dire({{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}});
    int cnt = 0;
    if(!sig){
        ++cnt;
        std::swap(q1,q2);
        dp[white.first][white.second] = 2;
        dp[black.first][black.second] = 1;
        int pos = q2.front();
        q2.pop(); 
        int ini_x = pos % n;
        int ini_y = pos / n;
        for(const std::pair<int,int>&dir: dire){
            int x = ini_x + dir.first;
            int y = ini_y + dir.second;
            if(x < 0 ||x>=n || y<0|| y>=n|| dp[x][y] != 0) continue;
            dp[x][y] = 2;
            q2.push(x*n+y);
        }    
    }
    bool found = false;
    std::pair<int,int>res({0,0});;
  
    while(!q1.empty() && !q2.empty()){
        ++cnt;
        int len = q1.size();
        for(int i=0; i<len; ++i){
            int pos = q1.front();
            q1.pop();
            int ini_x = pos % n;
            int ini_y = pos / n;
            for(const std::pair<int,int>& dir:dire){
                int x = ini_x + dir.first;
                int y = ini_y + dir.second;
                if(x < 0 ||x>=n || y<0|| y>=n|| dp[x][y] == 1||dp[x][y] == 3) continue;
                if(dp[x][y] == 2){
                    dp[x][y] = 3;
                    res.first = cnt;
                    ++res.second;
                    found = true;
                }
                else{
                    dp[x][y] = 1;
                    q1.push(x*n+y);
                }
            }
        }
        if(found == true)break;
        ++cnt;
        len = q2.size();
        for(int i=0; i<len; ++i){
            int pos = q2.front();
            q2.pop();
            int ini_x = pos % n;
            int ini_y = pos / n;
            for(const std::pair<int,int>&dir: dire){
                int x = ini_x + dir.first;
                int y = ini_y + dir.second;
                if(x < 0 ||x>=n || y<0|| y>=n|| dp[x][y] != 0) continue;
                dp[x][y] = 2;
                q2.push(x*n+y);
            }
        }
    }
    if(res.first == 0) return {-1,-1};
    return res;
}

int main(){
    Solution cl;
    std::pair<int,int>res = cl.chess(8,{7,2},{0,1},false);
    std::cout << res.first << " " << res.second;
    return 0;
}





