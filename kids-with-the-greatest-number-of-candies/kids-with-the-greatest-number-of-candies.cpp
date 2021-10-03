class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy=0;
        for(int x:candies)
            maxCandy=max(maxCandy,x);
        vector<bool> res;
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies>=maxCandy)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};