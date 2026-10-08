class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(), 0);
        vector<int> dp2(nums.size(), 0);

        int size = nums.size();
        if (nums.size() == 1){
            return nums[0];
        }
        for (int i = 1; i < size; i++) {
            if (i == 1) { 
                dp1[i] = nums[i];
                continue;
            }
            if (i == 2) {
                dp1[i] = max(nums[1], nums[2]);
                continue;
            }
            int big = max(dp1[i - 2] + nums[i], dp1[i - 1]);
            dp1[i] = big;
        }
        for (int i = 0; i < size - 1; i++) {
            if (i == 0) { 
                dp2[i] = nums[i];
                continue;
            }
            if (i == 1) {
                dp2[i] = max(nums[0], nums[1]);
                continue;
            }
            int big = max(dp2[i - 2] + nums[i], dp2[i - 1]);
            dp2[i] = big;
        }
        return (max(dp1[dp1.size() - 1], dp2[dp2.size() - 2]));
    }
};
