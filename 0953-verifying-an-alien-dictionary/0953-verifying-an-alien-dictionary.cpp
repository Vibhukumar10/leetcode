class Solution {
public:
    bool isSmaller(string &s,string &t,unordered_map<char,int> &ind) {
        int i=0,j=0;
        while(i<s.size() && j<t.size()) {
            if(ind[s[i]]<ind[t[j]]) {
                return true;
            } else if(ind[s[i]]>ind[t[j]]) {
                return false;
            }
            i++;
            j++;
        }

        if(i<s.size()) {
            return false;
        }

        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> ind;

        for(int i=0;i<order.size();i++) {
            ind[order[i]]=i;
        }

        for(int i=1;i<words.size();i++) {
            if(!isSmaller(words[i-1],words[i],ind)) {
                return false;
            }
        }

        return true;
    }
};