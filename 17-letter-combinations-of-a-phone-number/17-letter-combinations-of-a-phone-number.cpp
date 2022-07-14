class Solution {
public:
    unordered_map<char,string>mp {
        {'1', ""}, 
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    
    
    void helper(int index,string digits,vector<string> &res,unordered_map<char,string> mp, string curr) {
        if(index==digits.size()) {
            res.push_back(curr);
            return;
        }
        
        string mapping = mp[digits[index]];
        
        for(char c:mapping) {
            helper(index+1,digits,res,mp,curr+c);
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length()==0) {
            return res;
        }
        
        helper(0,digits,res,mp,"");    
        return res;
    }
};