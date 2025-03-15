class Solution {
    public:
        vector<string> generateParenthesis(int n) 
        {
            string s;
            dfs(n,s,0,0);  
            return ans;
        }
        void dfs(int n,string& s,int leftCnt,int RightCnt)
        {
            // std::cout<<s<<endl;
            if(leftCnt==n)
            {
                if(RightCnt==n)
                {
                    ans.push_back(s);
                    return;
                }
                s.push_back(')');
                dfs(n,s,leftCnt,RightCnt+1);
                s.pop_back();
                return;
            }
            s.push_back('(');
            dfs(n,s,leftCnt+1,RightCnt);
            s.pop_back();
            if(leftCnt>RightCnt)
            {
                s.push_back(')');
                dfs(n,s,leftCnt,RightCnt+1);
                s.pop_back();
            }
        }
        vector<string> ans;
    };