class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> box(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    // FIX 1:
                    // stoi(board[i][j]-1) is invalid.
                    // Replace every occurrence with:
                    // int num = board[i][j] - '1';

                    int num = board[i][j] - '1';

                    row[i][num]++;
                    if(row[i][num] > 1)
                    {
                        return false;
                    }

                    // FIX 2:
                    // Use column index 'j', not row index 'i'.

                    // FIX 3:
                    // You forgot the ++ here.

                    col[j][num]++;
                    if(col[j][num] > 1)
                    {
                        return false;
                    }

                    if(i < 3 && j < 3)
                    {
                        box[0][num]++;
                        if(box[0][num] > 1)
                        {
                            return false;
                        }
                    }
                    else if(i < 3 && j >= 3 && j < 6)
                    {
                        box[1][num]++;
                        if(box[1][num] > 1)
                        {
                            return false;
                        }
                    }
                    else if(i < 3 && j >= 6 && j < 9)
                    {
                        box[2][num]++;
                        if(box[2][num] > 1)
                        {
                            return false;
                        }
                    }

                    else if(i >= 3 && i < 6 && j >= 0 && j < 3)
                    {
                        box[3][num]++;
                        if(box[3][num] > 1)
                        {
                            return false;
                        }
                    }
                    else if(i >= 3 && i < 6 && j >= 3 && j < 6)
                    {
                        box[4][num]++;
                        if(box[4][num] > 1)
                        {
                            return false;
                        }
                    }
                    else if(i >= 3 && i < 6 && j >= 6 && j < 9)
                    {
                        box[5][num]++;
                        if(box[5][num] > 1)
                        {
                            return false;
                        }
                    }

                    else if(i >= 6 && i < 9 && j >= 0 && j < 3)
                    {
                        box[6][num]++;
                        if(box[6][num] > 1)
                        {
                            return false;
                        }
                    }
                    else if(i >= 6 && i < 9 && j >= 3 && j < 6)
                    {
                        box[7][num]++;
                        if(box[7][num] > 1)
                        {
                            return false;
                        }
                    }
                    else if(i >= 6 && i < 9 && j >= 6 && j < 9)
                    {
                        box[8][num]++;
                        if(box[8][num] > 1)
                        {
                            return false;
                        }
                    }

                    // OPTIONAL IMPROVEMENT:
                    // Instead of all the above if-else,
                    // you can simply do:
                    //
                    // int boxNo = (i / 3) * 3 + (j / 3);
                    // box[boxNo][num]++;
                    // if(box[boxNo][num] > 1) return false;
                }
            }
        }

        return true;
    }
};