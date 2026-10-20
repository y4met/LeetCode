#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 行数和列数
        int m = grid.size(), n = grid[0].size();
        // 递归
        auto dfs = [&](this auto&& dfs, int i, int j) -> void {
            // 当行/列 <0 或 >上限时说明访问到图外,直接停止
            // 当图中值不等于1时,说明"出岛",停止
            if(i<0 || i>=m || j<0 || j>=n || grid[i][j] != '1') return;

            // 标记访问过的点
            grid[i][j] = '2';
            // 递归访问当前点的左右上下
            dfs(i, j-1);
            dfs(i, j+1);
            dfs(i-1, j);
            dfs(i+1, j);
        };

        int ans = 0;
        // 遍历图
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // 当点值为1时,开始标记
                if(grid[i][j] == '1'){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};