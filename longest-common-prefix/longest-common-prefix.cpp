class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());

		string start = strs[0];
		string end = strs[strs.size()-1];

		string common;
		for(int i = 0; i<start.length() && i<end.length();i++)
		{
			if (start[i] == end[i]) common.push_back(start[i]);
			else break;
		}
		return common;
    }
};