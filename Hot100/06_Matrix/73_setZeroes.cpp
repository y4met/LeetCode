#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 用两个数组分别记录行和列是否有0
        vector<int> row_zero(m);
        vector<int> col_zero(n);

        // 遍历矩阵,如果有0,则对应位置置1
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0)
                row_zero[i] = col_zero[j] = 1;
            }
        }

        // 再次遍历,如果有0,则行列置0
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(row_zero[i] || col_zero[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};