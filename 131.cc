class Solution {
    public:
        void dfs(int start,int end,vector<vector<char>>& dp,vector<string>& ans,string& s)
        {
            if(start==end)
            {
                res.push_back(ans);
                return;
            }
    
            for(int i = start;i<end;i++)
            {
                if(dp[start][i])
                {
                    ans.push_back(s.substr(start,i-start+1));
                    dfs(i+1,end,dp,ans,s);
                    ans.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) 
        {
            int n = s.size();
            vector<vector<char>> dp(n,vector<char>(n,false));
            
            for(int i = 0;i<n;i++)
            {
                dp[i][i] = true;
            }
            for(int i = 0;i<n-1;i++)
            {
                if(s[i]==s[i+1])dp[i][i+1] = true;
            }
    
            for(int i = n-1;i>=0;i--)
            {
                for(int j = i+2;j<n;j++)
                {
                    dp[i][j] = dp[i+1][j-1]&&(s[i]==s[j]);
                }
            }
            // for(int i = 0;i<n;i++)
            // {
            //     for(int j = 0;j<n;j++)
            //     {
            //         if(dp[i][j])cout<<i<<' '<<j<<endl;
            //     }
            // }
            vector<string> ans;
            dfs(0,n,dp,ans,s);
            return res;
        }
    vector<vector<string>> res;
    };