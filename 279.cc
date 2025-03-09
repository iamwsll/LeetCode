class Solution {
    public:
        int numSquares(int n) 
        {
            //f[i] = min(1+f[i-j*j]);
             vector<int> dp(n+1,0x3f3f3f3f);
             dp[0] = 0;
             dp[1] = 1;
            for(int i = 2;i<=n;i++)
            {
                for(int j = 1;j*j<=i;j++)
                {
                    dp[i] = min(dp[i],dp[i-j*j]+1);
                }
            }
            return dp[n];
        }
    };