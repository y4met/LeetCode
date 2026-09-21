#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        // 从矩阵右上角元素开始寻找
        int i=0, j=n-1;
        while(i<m && j >=0){
            if(matrix[i][j] == target){
                return true;
                // 如果右上角元素 < 目标,说明这一行都小于,行+1
                // 如果 > ,说明当前这一列都 > ,列-1
            }else if(matrix[i][j] < target){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};