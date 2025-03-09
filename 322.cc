class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) 
        {
            //完全背包问题
            // dp[i][j] 表示从前i个硬币中挑选,总金额不超过j,需要的最小硬币数.
            // dp[i][j] = min(dp[i-1][j],dp[i-1][j-w[i]]+1,dp[i-1][j-2*w[i]]+2)
            //dp[i][j-w[i]] = min(dp[i-1][j-w[i]],dp[i-1][j-2*w[i]]+1)
            //dp[i][j] = min(dp[i-1][j],dp[i][j-w[i]]+1);
            int n = coins.size();
            vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
            for(int i = 0;i<=n;i++)
            {
                dp[i][0] = 0;
            }
            for(int i = 1;i<=n;i++)
            {
                for(int j = 1;j<=amount;j++)
                {
                    if(dp[i-1][j]!=-1)dp[i][j] = dp[i-1][j];
                    if(j>=coins[i-1]&&dp[i][j-coins[i-1]]!=-1)
                    {
                        if(dp[i][j]==-1)dp[i][j] = dp[i][j-coins[i-1]] +1;
                        else dp[i][j] = min(dp[i][j],dp[i][j-coins[i-1]] +1);
                    }
                }
            }
            return dp[n][amount];
        }
    };