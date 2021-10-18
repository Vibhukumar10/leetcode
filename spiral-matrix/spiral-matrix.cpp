class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0,bottom=n-1,left=0,right=m-1;
        
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
                res.push_back(matrix[top][i]);
            top++;
            
            for(int j=top;j<=bottom;j++)
                res.push_back(matrix[j][right]);
            right--;
            
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                    res.push_back(matrix[bottom][i]);
                bottom--;
            }
            
            if(left<=right)
            {
                for(int j=bottom;j>=top;j--)
                    res.push_back(matrix[j][left]);
                left++;       
            }
        }
        return res;
    }
};