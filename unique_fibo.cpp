#include<iostream>
#include<cmath>
class Solution{
    public:
        bool isfibo(const int& d);
        bool unique_fibo(const int&,const int&);
};

bool Solution::isfibo(const int& d){
    if (d == 0) return false;
    int d1 = 5*d*d + 4;
    int d2 = 5*d*d - 4;
    if(std::pow(int(std::sqrt(d1)),2) != d1 && std::pow(int(std::sqrt(d2)),2) != d2) return false;
    return true;
}

bool Solution::unique_fibo(const int& x, const int& n){
    std::cout << x << ' ' << n << '\n';
    int d = x;
    if(d == 0 && n == 0) return true;
    if((d == 0 && n != 0) || (d != 0 && n == 0))return false;
    while(!isfibo(d)) --d;
    return unique_fibo(x-d,n-1);
}


int main(){
    Solution cl;
    bool res = cl.unique_fibo(5,3);
    std::cout << res;
    return 0;
}
