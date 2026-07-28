class Solution {
public:
    bool dfs(int i,int j,int ind,vector<vector<char>> &board,vector<vector<bool>> &visi,string &word)
    {
        if(ind == word.size()-1)
        {
            return true;
        }
        
        


        visi[i][j]=true;
        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,-1,0,1};

        

        for(int k=0;k<4;k++)
        {
            int nx = i+dx[k];
            int ny = j+dy[k];

            if(nx < board.size() && nx >=0 && ny>=0 && ny<board[0].size() && visi[nx][ny]==false && board[nx][ny]==word[ind+1])
            {
                if(dfs(nx,ny,ind+1,board,visi,word)==true)
                {
                    visi[i][j] = false;
                    return true;
                }
            }


        }

        visi[i][j]=false;

        return false;

        
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        vector<vector<bool>> visi(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(i,j,0,board,visi,word)==true)
                    return true;
                }
            }
        }

        return false;
        
    }
};
