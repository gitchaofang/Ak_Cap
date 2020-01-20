#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
class Solution{
    public:
        bool check(const std::string& month, const std::string& day,const std::string& year);
        int palin(const int&);
};


bool Solution::check(const std::string& month, const std::string& day,const std::string& year){
            int m = std::stoi(month);
            int d = std::stoi(day);
            if(m == 0 || d == 0) return false;
            int y = std::stoi(year);
            if(m == 2){ 
                if(((y%4==0 && y%100 !=0)||y%400 == 0)&& d < 30) return true;
                if(d <30) return true;
            }
            else if(m < 8){ 
                if(m % 2 == 1 && d <32) return true;
                else if(m%2 == 0 && d < 31) return true;
            }   
            else if(m < 13){
                if(m % 2 == 0 && d <32) return true;
                else if(m%2 == 1 && d < 31) return true;
            }
            return false;
        }
int Solution::palin(const int& year){
    int cent = (year-1)/100 * 100;
    int res = 0;
    for(int i=1; i<=100; ++i){
        std::string y = std::to_string(cent + i);
        std::reverse(y.begin(),y.end());
        //seven
        std::string month = y.substr(0,1);
        std::string day = y.substr(1,2);
        if(check(month,day,y)) ++res;
        //eight
        month = y.substr(0,2);
        day = y.substr(2,2);
        if(check(month,day,y)) ++res;
    }
    return res;
}


int main(){
    Solution cl;
    int res = cl.palin(2001);
    std::cout << res;
    return 0;
}





