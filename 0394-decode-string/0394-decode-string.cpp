class Solution {
public:
    string decodeString(string s) {
        stack<int> counterStack;
        stack<string> stringStack;

        string curr="";
        int k=0;
        for(char c:s) {
            if(isdigit(c)) {
                k=k*10+(c-'0');
            } else if(c=='[') {
                counterStack.push(k);
                stringStack.push(curr);
                k=0;
                curr="";
            } else if(c==']') {
                int repeat=counterStack.top(); counterStack.pop();
                string temp=curr;
                curr=stringStack.top(); stringStack.pop();
                for(int i=0;i<repeat;i++) {
                    curr+=temp;
                }
            } else {
                curr+=c;
            }
        }

        return curr;
    }
};