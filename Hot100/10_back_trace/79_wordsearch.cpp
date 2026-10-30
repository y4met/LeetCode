#include <vector>
#include <string>
using namespace std;

class Solution {
    // 方向数组
    static constexpr int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> bool {
            // 没匹配上
            if(board[i][j] != word[k]) return false;
            // 当前长度如果等于单词长度,说明之前字母都匹配成功
            if(k+1 == word.length()) return true;
            // 标记为已使用
            board[i][j] = 0;
            // 遍历当前字母上下左右四个方向
            for(auto& [dx,dy]: dirs){
                int x = i+dx, y = j+dy;
                // 如果四个方向能找到下一个字母,则继续(返回真)
                if(x>=0 && x<m && y>=0 && y<n && dfs(x,y,k+1)) return true;
            }
            // 没找到则恢复当前字母,不影响后续寻找
            board[i][j] = word[k];
            return false;
        };

        // 遍历图,每个字母都可能是开头
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dfs(i,j,0)) return true;
            }
        }
        return false;
    }
};