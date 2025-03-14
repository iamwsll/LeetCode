class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
        {
            vector<int> temp;
            dfs(0,candidates,target,temp);
            return ans;
        }
        void dfs(int x,vector<int>& candidates,int target,vector<int>& one)
        {
            if(target==0)
            {
                ans.push_back(one);
            }
            else if(target<0)
            {
                return ;
            }
    
            for(int i = x;i<candidates.size();i++)
            {
                one.push_back(candidates[i]);
                dfs(i,candidates,target-candidates[i],one);
                one.pop_back();
            }
        }
        vector<vector<int>> ans;
    };