// time complecity : https://leetcode.com/problems/campus-bikes-ii/discuss/360037/Step-by-Step-solution-from-400ms-to-1ms-(beating-100) see one of comments
class Solution {
private:
    vector<int> dp;
    int n,m;
    vector<vector<int>> workers, bikes;
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        n=workers.size();
        m=bikes.size();
        this->workers=workers;
        this->bikes=bikes;
        
        dp.assign(1<<m, -1);
        
        return assign(0, 0);
    }
    
    int assign(int i, int used) {
        if(i>=n) {
            return 0;
        }   
        
        if(dp[used] != -1) return dp[used];
        
        int res=INT_MAX;
        for(int j=0; j<m; j++) {
            if((used & (1<<j)) == 0) {
                res = min(res, dist(workers[i], bikes[j]) + assign(i+1, used | 1<<j));
            }
        }
        
        dp[used]=res;
        return res;
    }
    
    int dist(vector<int> a, vector<int> b) {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
};
