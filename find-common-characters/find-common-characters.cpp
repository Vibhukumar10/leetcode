class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> primary(26,0);
        vector<int> check(26,0);
        
        for(char c:words[0])
            primary[c-'a']++;
    
        for(int i=1;i<words.size();i++)
        {
            for(char c:words[i])
                check[c-'a']++;
            
            for(int j=0;j<26;j++)
            {
                primary[j]=min(primary[j],check[j]);
                check[j]=0;
            }
        }
        
        for(int i=0;i<26;i++)
        {
            if(primary[i]>0)
            {
                int t=primary[i];
                while(t--)
                {
                    char a=i+'a';
                    string s;
                    s.push_back(a);
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};