class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, false);

        dp[0] = true;
        for (int i = 0; i < s.size(); i++) {
            if (dp[i] == false) {
                continue;
            }

            for (string word : wordDict) {
                if (i + word.size() > s.size()) {
                    continue;
                }
                bool match = false;
                for (int j = 0; j < word.size(); j++) {
                    match = true;

                    if (s[i + j] != word[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    dp[i + word.size()] = true;;
                }

            }
        }
        return dp[s.size()];
    }
};
