class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res;
        for(int i=0;i<boxes.length();i++)
        {
            int curr=0;
            for(int j=0;j<boxes.length();j++)
            {
                if(i!=j && boxes[j]!='0')
                {
                    curr+=abs(i-j);
                }
            }
            res.push_back(curr);
        }
        return res;
    }
};