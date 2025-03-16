class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) 
        {
            m = board.size();
            n = board[0].size();
    
            for(int i = 0;i<m;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    st[i][j] = true;
                    dfs(i,j,board,word,0);
                    st[i][j] = false;
                }
            }
            return flag;
        }
        void dfs(int i,int j,vector<vector<char>>& board, string& word,int pos)
        {
            if(board[i][j]!=word[pos])
            {
                return;
            }
            if(pos==word.size()-1)
            {
                flag = true;
                // std::cout<<"Ops! "<<i<<' '<<j<<endl;
                // std::cout<<pos<<endl;
                return;
            }
            for(int t = 0;t<4;t++)
            {
                int nowx = px[t]+i;
                int nowy = py[t]+j;
                if(nowx>=0&&nowx<m&&nowy>=0&&nowy<n&&!st[nowx][nowy])
                {
                    st[nowx][nowy] = true;
                    dfs(nowx,nowy,board,word,pos+1);
                    st[nowx][nowy] = false;
                }
            }
        }
        int px[4] = {1,-1,0,0};
        int py[4] = {0,0,1,-1};
        int m,n;
        bool st[7][7];
        bool flag = false;
    };