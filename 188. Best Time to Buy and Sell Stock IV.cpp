//https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/StockBuySellKTransactions.java
//https://www.youtube.com/watch?v=oDhu5uGq_ic

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days=prices.size();
        if(days==0) return 0;
        vector<vector<int>> dp(k+1, vector<int> (days, 0));
        
        for(int i=0; i<=k; i++) {
            int maxDiff=-prices[0];
            for(int j=0; j<days; j++) {
                if(i==0 || j==0) {
                    dp[i][j]=0;
                } else {
                    dp[i][j] = max(dp[i][j-1], maxDiff+ prices[j]);
                    maxDiff = max(maxDiff, dp[i-1][j]-prices[j]);
                }
            }
        }
        
        return dp[k][days-1];
    }
};
