class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        
        for(int i=0;i<n;i++)
        {
            int l=0,r=n-1;
            while(l<=r)
            {            
                swap(image[i][l],image[i][r]);
                
                l++;
                r--;
            }
            
            for(int j=0;j<n;j++)
            {
                if(image[i][j]==0)
                    image[i][j]=1;
                else
                    image[i][j]=0;
            }
        }
        return image;
    }
};