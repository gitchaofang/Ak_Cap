#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<set>
class Solution{
    public:
        std::vector<int> seek(int, const std::vector<std::vector<int>>&);
};

std::vector<int> Solution::seek(int n, const std::vector<std::vector<int>>& m){
    std::vector<std::pair<int,int>> dire({{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}});
    std::multiset<int> store;
    std::vector<std::vector<int>> check(n,std::vector<int>(n,0));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(check[i][j] == 1) continue;
            check[i][j] = 1;
            bool sig = true;
            for(const std::pair<int,int>& dir: dire){
                int x = i + dir.first;
                int y = j + dir.second;
                if(x<0 ||x>=n ||y<0 ||y>=n) continue;
                if(m[x][y] <= m[i][j]){
                    sig = false;
                    break;
                }
                check[x][y] = 1;
            }
            if(sig == true){
                store.insert(m[i][j]);
                if(store.size() > 3) store.erase(store.begin());
            }
        }
    }
    std::vector<int> res(store.begin(),store.end());
    return res;
}


int main(){
    Solution mn;
    std::vector<std::vector<int>>input = {{5,2,5,3,1},{5,1,5,6,5},{9,5,5,4,5},{5,5,4,6,3},{0,5,5,3,4}};
    std::vector<int> res = mn.seek(5,input);
    for(const int& d: res)std::cout << d << "   ";

    return 0;
}
