#include<iostream>
#include<vector>
class Solution{
    public:
        int flip(const std::string& s, int K);
};
int Solution::flip(const std::string& s, int K){
    uint32_t n = s.size();
    std::vector<uint32_t> isflipped(n,0);
    uint32_t curflip = 0;
    int res = 0;
    for(uint32_t i=0; i<n; ++i){
        uint32_t sig = 0;
        if(s[i] == '+') sig  = 1;
        if(i >= K) curflip ^= isflipped[i - K];
        if(curflip %2^sig  == 0){
            if(i + K > n) return -1;
            isflipped[i] = 1;
            curflip ^= 1;
            ++res; 
        }
    }
    return res;
}

int main(){
    Solution cl;
    std::string input = "+--+--";
    int res = cl.flip(input,3);
    std::cout << res;
    return 0;
}
