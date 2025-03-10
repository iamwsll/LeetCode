class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) 
        {
            unordered_set<string> hash;
            for(auto& str :wordDict)
            {
                hash.insert(str);
            }
            // for(auto i:hash)
            // {
            //     cout<<i<<' ';
            // }
            int n = s.size();
            vector<int> dp(n+1,false);
            dp[0] = true;
            for(int i = 1;i<=n;i++)
            {
                for(int j = 0;j<i;j++)
                {
                    if(dp[j]&&hash.contains(s.substr(j,i-j)))
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
            // for(int i = 0;i<=n;i++)
            // {
            //     cout<<dp[i]<<' ';
            // }
            return dp[n];
        }
    };