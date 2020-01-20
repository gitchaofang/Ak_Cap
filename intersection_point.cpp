#include<iostream>
#include<vector>
#include<cmath>
class Solution{
    public:
        std::vector<double> intersection(const double&,const double&,const double&,const double&,const double&,const double&,const double&,const double&,const double&,const double&);
};

std::vector<double> Solution::intersection(const double& c_x,const double& c_y,const double& c_z,const double& c_r,const double& ray_x,const double& ray_y,const double& ray_z,const double& dir_x, const double& dir_y,const double& dir_z){
    double dir_len = std::sqrt(std::pow(dir_x,2) + std::pow(dir_y,2) + std::pow(dir_z,2));
    double d_x = dir_x/dir_len;
    double d_y = dir_y/dir_len;
    double d_z = dir_z/dir_len;
    double A = std::pow(d_x,2) + std::pow(d_y,2) + std::pow(d_z,2);
    double B = 2*(d_x*(ray_x - c_x) + d_y*(ray_y - c_y) + d_z*(ray_z - c_z));
    double C = std::pow(ray_x - c_x,2) + std::pow(ray_y - c_y,2) + std::pow(ray_z - c_z,2) - std::pow(c_r,2);
    double delta = std::pow(B,2) - 4*A*C;
    if(delta < 0) return {0.0};
    double root1 = (-B + std::sqrt(delta))/(2*A);
    double root2 = (-B - std::sqrt(delta))/(2*A);
    if(root1 < 0.0 && root2 < 0.0) return {0.0};
    std::vector<double> res;
    if(root1 >= 0.0) res.push_back(root1);
    if(root2 >= 0.0) res.push_back(root2);
    return res;
}

int main(){
    Solution cl;
    std::vector<double> res =cl.intersection(1.0,0.0,0.8,1.0,0.0,0.0,0.0,1.0,0.0,0.0);
    for(double d: res) std::cout << d << '\n';
    return 0;       
}
