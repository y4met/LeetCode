#include <vector>
using namespace std;

// 将二维转成一维处理
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        // 二分
        int left = -1, right = m*n;
        while(left+1 < right){
            int mid = left + (right-left)/2;
            // arr[mid] == arr[mid/n][mid%n]
            int x = matrix[mid/n][mid%n];
            if(x == target) return true;
            (x >= target ? right : left) = mid;
        }
        return false;
    }
};