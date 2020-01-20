#include<iostream>
#include<vector>
class Solution{
    public:
        int pick_melon(const std::vector<int>& melon, const std::vector<int>& box){
            int len_melon = melon.size() - 1;
            int len_box = box.size() - 1;
            int res = 0;
            while(len_box >=0 && len_melon>=0){
                if(melon[len_melon] <= box[len_box]){
                    --len_melon;
                    --len_box;
                    ++res;
                }
                else --len_box;
            }
            return res;
        }

};

int main(){
    Solution cl;
    std::vector<int> melon({5,4,3,4});
    std::vector<int> box({4,5,2,3,1,4,5});
    int res = cl.pick_melon(melon,box);
    std::cout << res;
    return 0;
}
