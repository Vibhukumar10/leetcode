class Solution {
public:
    void flood(vector<vector<int>> &image,int r,int c,int color,int newColor) {
        if(image[r][c] == color) {
            image[r][c]=newColor;
            if(r >= 1) flood(image, r-1, c, color, newColor);
            if(c >= 1) flood(image, r, c-1, color, newColor);
            if(r+1 < image.size()) flood(image, r+1, c, color, newColor);
            if(c+1 < image[0].size()) flood(image, r, c+1, color, newColor);
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // vector<vector<pair<int,int>>> adj;
        if(image[sr][sc]!=newColor) {
            flood(image,sr,sc,image[sr][sc],newColor);
        }
        return image;
    }
};