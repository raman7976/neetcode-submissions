class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        queue<pair<int,int>> q;


        for(int i=0;i<c;i++)
        {
           if(board[0][i]=='O')
           {
            board[0][i]='#';
            q.push({0,i});
           }
           
           if(board[r-1][i]=='O')
           {
            board[r-1][i]='#';
            q.push({r-1,i});
           }
        }


        for(int i=0;i<r;i++)
        {
           if(board[i][0]=='O')
           {
            board[i][0]='#';
            q.push({i,0});
           }
           
           if(board[i][c-1]=='O')
           {
             board[i][c-1]='#';
             q.push({i,c-1});
           }
        }

        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,-1,0,1};


        while(!q.empty())
        {
            int sz = q.size();
            pair<int,int> p = q.front();
            q.pop(); 
            int xx = p.first ;
            int yy= p.second ;
            for(int i=0;i<4;i++)
            {
               int x = xx +dx[i];
               int y = yy + dy[i];
               

                if(x>=0 && x<r && y>=0 && y<c && board[x][y]=='O')
                {
                    q.push({x,y});
                    board[x][y]='#';
                }
                
            }
        }

        for(int i =0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};
