#include<vector>
#include<iostream>
class Solution{
    public:
        std::vector<double> me(const std::vector<std::vector<double>>&, std::vector<double>);

};
std::vector<double> Solution::me(const std::vector<std::vector<double>>& sw, std::vector<double> init){
    int n = init.size();
    while(true){
        std::vector<double> v(n);
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                v[j] += init[i] * sw[i][j];
            }
        }
        if(v == init) break;
        init = v;
    }
    for(double& d: init) d = double(int(d*10000+0.5))/10000;
    return init;
}

int main(){
    Solution cl;
    std::vector<std::vector<double>> sw = {{0.8,0.2},{0.1,0.9}};
    std::vector<double> init = {0.4,0.6};
    std::vector<double> res = cl.me(sw,init);
    for(double d: res) std::cout << d << '\n';
    return 0;
    
}
