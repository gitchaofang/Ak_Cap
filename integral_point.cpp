#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
class Solution{
    public:
        double area(const std::vector<double>& p1,const std::vector<double>& p2,const std::vector<double>& p){
            double res = ((p[0] - p1[0])*(p[1] - p2[1]) - (p[1] - p1[1])*(p[0] - p2[0]));
            if(res < 0) res *= -1.0;
            return res;
        }
        bool isinside(const std::vector<double>& p1, const std::vector<double>& p2, const std::vector<double>& p3,std::vector<double>& p){
            return (area(p1,p3,p) + area(p1,p2,p) + area(p2,p3,p)) ==  area(p1,p2,p3);
        }

        double dist(const std::vector<double>& p1, const std::vector<double>& p2, const std::vector<double>& p3,std::vector<double>& p){
            double d1 =  std::sqrt(std::pow((p[0] - p1[0]),2) + std::pow((p[1] - p1[1]),2));
            double d2 =  std::sqrt(std::pow((p[0] - p2[0]),2) + std::pow((p[1] - p2[1]),2));
            double d3 =  std::sqrt(std::pow((p[0] - p3[0]),2) + std::pow((p[1] - p3[1]),2));
            return d1 + d2 + d3;
        }
        std::vector<int> ip(const std::vector<double>& p1, const std::vector<double>& p2, const std::vector<double>& p3){
            double left = std::min(std::min(p1[0],p2[0]),p3[0]);
            double right = std::max(std::max(p1[0],p2[0]),p3[0]);
            double bottom = std::min(std::min(p1[1],p2[1]),p3[1]);
            double top = std::max(std::max(p1[1],p2[1]),p3[1]);
            double dis = INT_MAX;
            std::vector<int> res = {INT_MIN,INT_MIN};
 //           std::cout << left << ' ' << right << "---" << bottom << ' ' << top ;
            for(int x=left; x<=right; ++x){
                for(int y=bottom; y<=top; ++y){
                    std::vector<double>p = {x,y};
                    if(!isinside(p1,p2,p3,p)) continue;
                    double d = dist(p1,p2,p3,p);
                     std::cout << x << ' ' << y <<' ' << d <<'\n';
                    if(d < dis){
                        dis = d;
                        res = {x,y};
                    }
                    else if(d == dis){
                        if(res[0] == x){
                            if(res[1] < y)res = {x,y};
                        }
                        else if(res[0] < x) res = {x,y};
                    }
                }
            }
            return res;
        }
};


int main(){
    Solution cl;
    std::vector<double> p1 = {0.0,0.0};
    std::vector<double> p2 = {3.0,0.0};
    std::vector<double> p3 = {3.0,3.0};
    std::vector<int> res = cl.ip(p1,p2,p3);
    std::cout << res[0] << ' ' <<res[1];
    return 0;
}
