class Solution {
    public:
        string longestPalindrome(string s) 
        {
            int n = s.size();
            vector<vector<char>> st(n+1,vector<char>(n+1,false));  
            int leftPos = 0;
            int len = 1;
            for(int i = 0;i<n;i++)
            {
                st[i][i] = true;
            }
            for(int i = 0;i<n-1;i++)
            {
                if(s[i]==s[i+1])
                {
                    // cout<<i<<' '<<i+1<<endl;
                    leftPos = i;
                    len = 2;
                    st[i][i+1]=true;
                }
            }
    
            //ifs[i]==s[j] st[i][j]== st[i+1][j-1]
            for(int i = n-1;i>=0;i--)
            {
                for(int j  = i+2;j<n;j++)
                {
                    if(s[i]==s[j])
                    {
                        if(i+1<n)
                        {
                            st[i][j] = st[i+1][j-1];
                            // cout<<"trans from"<<i+1<<' '<<j-1<<' ';
                            // cout<<i<<' '<<j<<' '<<(int)st[i][j]<<endl;
                            if(j-i+1>len&&st[i][j])
                            {
                                len = j-i+1;
                                leftPos = i;
                                // cout<<"len: "<<len<<" leftPos"<<leftPos<<endl;
                            }
                        }
                    }
                }
            }
            return s.substr(leftPos,len);
        }
    };