#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
class Solution{
    public:
        std::vector<int> spell(const std::vector<std::string>&, const std::vector<std::vector<char>>&);
};

std::vector<int> Solution::spell(const std::vector<std::string>& words, const std::vector<std::vector<char>>& list){
    int n = words.size();
    std::unordered_map<char,std::unordered_set<char>> link;
    for(const std::vector<char>& v: list) link[v[0]].insert(v[1]);
    std::vector<int> res(n,0);
    for(int i=0; i<n; ++i){
        std::string s = words[i];
        bool found = true;
        for(int j=1; j<s.size(); ++j){
            if(link[s[j-1]].find(s[j]) == link[s[j-1]].end()){
                res[i] = 0;
                found = false;
                break;
            }
        }
        if(found == true) res[i] = 1;
    }
    return res;
}

int main(){
    Solution cl;
    std::vector<std::string> words = {"a","b","ab","ba"};
    std::vector<std::vector<char>> list = {{'a','b'}};
    std::vector<int> res = cl.spell(words,list);
    for (int d: res) std::cout << d << ' ';
    return 0;
}
