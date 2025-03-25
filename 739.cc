class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) 
        {
            stack<int> st;
            int n = temperatures.size();
            vector<int> ans(n,0);
            
            for(int i = 0;i<n;i++)
            {
                while(!st.empty()&&temperatures[i]>temperatures[st.top()])
                {
                    int now = st.top();
                    st.pop();
                    ans[now] = i-now;
                }
                st.push(i);
            }
    
            return ans;
        }
    };