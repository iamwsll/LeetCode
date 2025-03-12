class Solution {
    public:
        vector<string> letterCombinations(string digits) 
        {
            n = digits.size();
            if(n==0)return {};
            hash[2] = "abc";
            hash[3] = "def";
            hash[4] = "ghi";
            hash[5] = "jkl";
            hash[6] = "mno";
            hash[7] = "pqrs";
            hash[8] = "tuv";
            hash[9] = "wxyz";
            string str;
            dfs(digits,0,str);
            return ans;
        }
        void dfs(string& digits,int pos,string& str)
        {
            if(str.size()==n)
            {
                ans.push_back(str);
                return ;
            }
            int c = digits[pos] - '0';
            string possible_c = hash[c];
            for(char choose:possible_c)
            {
                str.push_back(choose);
                dfs(digits,pos+1,str);
                str.pop_back();
            }
        }
    private:
        int n;
        unordered_map<int, string> hash;
        vector<string> ans;
    };