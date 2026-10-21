#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 建图操作,把先修课关系转为图
        vector<vector<int>> g(numCourses);
        for(auto p: prerequisites){
            g[p[1]].push_back(p[0]);
        }

        // 每门课用三种颜色标记: 0代表没访问过, 1代表正在访问, 2代表访问过
        vector<int> colors(numCourses);
        // 递归找环
        auto dfs = [&](this auto&& dfs, int x) -> bool {
            // 标记为正在访问
            colors[x] = 1;
            // 在 x 的先修课中寻找是否有正在访问的
            for(int y: g[x]){
                // 如果有正在访问的,或者 没访问过但是先修课的先修课有正在访问的, 说明有环
                if(colors[y]==1 || colors[y]==0 && dfs(y)) return true;
            }
            // 没找到环, 则标记访问过
            colors[x] = 2;
            // 没找到环
            return false;
        };
        
        // 遍历课程
        for(int i=0; i<numCourses; i++){
            // 没访问过并且有环,则不能修完
            if(colors[i]==0 && dfs(i)) return false;
        }
        return true;
    }
};