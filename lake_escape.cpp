#include<iostream>
#include<vector>
#include<utility>
#include<queue>
class Solution{
    public:
        int escape(const int&, const std::vector<std::vector<int>>&, const int& ,const int& , const int& , const int&);
};

int Solution::escape(const int& n, const std::vector<std::vector<int>>& lake, const int& albert_row,const int& albert_col, const int& kuna_row, const int& kuna_col){
    std::vector<std::pair<int,int>> dire = {{-1,0},{0,1},{1,0},{0,-1}};
    std::queue<std::pair<int,int>>q({{albert_row,albert_col}});
    std::vector<std::vector<uint32_t>> check(n,std::vector<uint32_t>(n,0));
    check[albert_row][albert_col] = 1;
    while(!q.empty()){
        std::pair<int,int> cur = q.front();
        q.pop();
        for(const std::pair<int,int>& dir: dire){
            int x = cur.first + dir.first;
            int y = cur.second + dir.second;
            while(x < n && y<n && x >=0 && y>=0 && lake[x][y] == 0){
                x += dir.first;
                y += dir.second;
            }
            if(x<0 ||x>=n ||y<0 ||y>=n || check[x][y] == 1||lake[x][y] != 1) continue;
            if(x == kuna_row && y == kuna_col) {
                std::cout << cur.first << ' ' << cur.second << ' ' << kuna_row <<' ' <<kuna_col << '\n';
                return 1;
            }
            check[x][y] = 1;
            q.push({x,y});
        }
    }
    return -1;
}


int main(){
    Solution cl;
    std::vector<std::vector<int>> input = {{0,0,1,0},{1,0,1,1},{-1,-1,0,0},{1,0,-1,1}};
    int res = cl.escape(input.size(),input,0,2,3,0);
    std::cout << res;
    return 0;
}
