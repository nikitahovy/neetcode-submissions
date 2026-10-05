class Solution {
public:
    void incrm (vector<int>& nums, vector<int>& inc, int i) {
        int value = nums[i];
        if (inc.size() == 0) {
            inc.push_back(value);
            return;
        }
        if (value > inc.back()) {
            inc.push_back(value);
            return;
        }
        else {
            if (value < inc[0]) {
                inc[0] = value;
            }
            for (int j = 0; j < inc.size() - 1; j++) {
                if (value < inc[j + 1] && value > inc[j]) {
                    inc[j+1] = value;
                    return;
                }
            }
        }
        return;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> inc;
        for (int i = 0; i < nums.size(); i++) {
            incrm(nums, inc, i);
        }
        return inc.size();

    }
};
