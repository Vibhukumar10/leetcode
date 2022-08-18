class Solution {
public:
    vector<string> m = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    unordered_map<int,string> code;
    
    int uniqueMorseRepresentations(vector<string>& words) {
        for(int i=0;i<26;i++) {
            code[i] = m[i];
        }
        unordered_set<string> st;
        for(string s:words) {
            string morse="";
            for(char c:s) {
                morse+=code[c-'a'];
            }
            st.insert(morse);
        }
        return st.size();
    }
};