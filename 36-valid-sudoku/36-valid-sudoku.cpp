class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++)
        {
            int mp[10]={0};
            for(int j=0; j<9; j++)
            {
                if(board[i][j]!='.')
                mp[board[i][j]-'0']++;
            }
            for(int x=1; x<=9; x++)
                if(mp[x]>1)
                return false;
        }
        for(int i=0; i<9; i++)
        {
            int mp[10]={0};
            for(int j=0; j<9; j++)
            {
                if(board[j][i]!='.')
                mp[board[j][i]-'0']++;
            }
            for(int x=1; x<=9; x++)
                if(mp[x]>1)
                return false;
        }
        for(int i=0; i<9; i+=3)
        {
            for(int j=0; j<9; j+=3)
            {
                int mp[10]={0};
                for(int k=i; k<3+i; k++)
                {
                    for(int l=j; l<3+j; l++)
                    {
                        if(board[k][l]!='.')
                        mp[board[k][l]-'0']++;
                    }
                }
                for(int x=1; x<=9; x++)
                if(mp[x]>1)
                return false;
            }
        }
        return true;
    }
};