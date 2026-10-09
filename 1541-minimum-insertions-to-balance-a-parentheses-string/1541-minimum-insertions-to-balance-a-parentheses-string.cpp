class Solution {
public:
    int minInsertions(string s) {
        int count = 0;
        int res = 0;

        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                count++;
                i++;
            } else {
                // Match the closing pair with an opening '('.
                if (count==0) {
                    res++; // Insert missing '('
                }

                // Consume )) as one closing pair.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i += 2;
                } else {
                    res++; // Insert missing ')'
                    i++;
                }

                if(count)
                    count--;
            }
        }

        return res + 2 * count;
    }
};