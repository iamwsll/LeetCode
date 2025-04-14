class Solution {
    public:
        vector<int> partitionLabels(string s) 
        {
            unordered_map<char, int> endPos;
            for(int i = 0;i<s.size();++i)
            {
                endPos[s[i]] = max(endPos[s[i]],i);
            }
            vector<int> ans;
            int begin = 0;
            int end = -1;
            for(int i = 0;i<s.size();++i)
            {
                end = max(end,endPos[s[i]]);
                // std::cout<<end<<' ';
                if(i==end)
                {
                    ans.push_back(end-begin+1);
                    begin = end+1;
                }
            }
            return ans;
        }
    };