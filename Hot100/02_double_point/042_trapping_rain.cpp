#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        
        int pre_max = 0, suf_max = 0; // 先前最大值和后续最大值
        int left = 0, right = n-1; // 双指针
        while(left < right){
            pre_max = max(pre_max, height[left]); // 从0到左指针最大值
            suf_max = max(suf_max, height[right]); // 从右指针到末尾最大值
            // 如果前最大<后最大,当前位置能存的水取决于前最大,即前最大-当前位置(左指针),
            // 反之则后最大-右指针,即谁小处理谁那边
            if(pre_max < suf_max){
                ans += pre_max - height[left];
                left++;
            }else{
                ans += suf_max - height[right];
                right--;
            }
        }
        return ans;
    }
};