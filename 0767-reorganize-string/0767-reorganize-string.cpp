class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        // {frequency, character}
        priority_queue<pair<int, char>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        // {remaining frequency, character}
        pair<int, char> coolout = {0, '#'};

        string res = "";

        while (!pq.empty()) {

            // Get most frequent available character
            auto [f, c] = pq.top();
            pq.pop();

            res += c;
            f--;

            // Previous character is now available again
            if (coolout.first > 0) {
                pq.push(coolout);
            }

            // Current character goes into cooldown
            coolout = {f, c};
        }

        // Some character is still left but cannot be placed
        if (coolout.first > 0) {
            return "";
        }

        return res;
    }
};